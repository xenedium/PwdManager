#include <encdb.hpp>


using namespace std;

void CheckForExdbFile()
{
    #ifdef _WIN32

    char win32PATH[MAX_PATH];
    strcpy(win32PATH, getenv("LOCALAPPDATA"));
    strcat(win32PATH, "\\PwdManager\\encdb.exdb");
    if (GetFileAttributes(win32PATH) != INVALID_FILE_ATTRIBUTES) return;

    #elif __linux__

    char linuxPATH[PATH_MAX]; 
    strcpy(linuxPATH, getenv("HOME"));
    strcat(linuxPATH, "/.config/PwdManager/encdb.exdb");
    if (access(linuxPATH, F_OK) != -1) return;

    #endif

    cout << "Config file not found !\nGenerating a new one...\n";
    GenereateExdbFile();
}

void GenereateExdbFile()
{
    #ifdef _WIN32

    HANDLE hFile;
    char win32PATH[MAX_PATH];
    strcpy(win32PATH, getenv("LOCALAPPDATA"));
    strcat(win32PATH, "\\PwdManager");
    if(!CreateDirectoryA(win32PATH, NULL)) ThrowErrorAndExit(ERR_CANNOT_CREATE_PWD_FILE, NULL);
    strcat(win32PATH, "\\encdb.exdb");
    if((hFile = CreateFileA(win32PATH, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE) ThrowErrorAndExit(ERR_CANNOT_CREATE_PWD_FILE, NULL);
    

    #elif __linux__

    char linuxPATH[PATH_MAX];
    FILE *pFile;
    strcpy(linuxPATH, getenv("HOME"));
    strcat(linuxPATH, "/.config/PwdManager");
    if(mkdir(linuxPATH, 0755) == -1) ThrowErrorAndExit(ERR_CANNOT_CREATE_PWD_FILE, NULL);
    strcat(linuxPATH, "/encdb.exdb");
    if((pFile = fopen(linuxPATH, "wb")) == NULL) ThrowErrorAndExit(ERR_CANNOT_CREATE_PWD_FILE, NULL);

    #endif

    cout << "Enter a new password for you config file: ";
    string pwd;
    cin >> pwd;

    unsigned char header[72] = {0};

    uint32_t fversion = 0x01000000;
    memcpy(header, &fversion, 4);

    SHA512 hasher;
    memcpy(header + 4, hasher.hash(pwd), 64);

    uint32_t nPwd = 0;
    memcpy(header + 68, &nPwd, 4);

    #ifdef _WIN32
    WriteFile(hFile, header, 72, NULL, NULL);
    CloseHandle(hFile);
    #elif __linux__
    fwrite(header, 1, 72, pFile);
    fclose(pFile);
    #endif

}