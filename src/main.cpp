#include <iostream>
#include <fstream>
#include <string>


#include <err.hpp>
#include <base64.hpp>
#include <encdb.hpp>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) ThrowErrorAndExit(ERR_INVALID_ARGS, argv[0]);
    
    if (!strcmp(argv[1], "--help"))
    {
        cout << "Usage: " << argv[0] << " [--help] [--getpwd] [--setpwd] [--delpwd] [--listpwd]" << endl;
        cout << "--help: Show this help." << endl;
        cout << "--getpwd [pwd] [name]: Get a stored password." << endl;
        cout << "--setpwd [pwd] [name] [password]: Add or change a password" << endl;
        cout << "--delpwd [pwd] [name]: Delete a password." << endl;
        cout << "--listpwd [pwd]: List all stored passwords." << endl;
        return 0;
    }

    if (!strcmp(argv[1], "--getpwd"))
    {
        if (argc < 4) ThrowErrorAndExit(ERR_INVALID_ARG_GETPWD, argv[0]);
        CheckForExdbFile();
    }
    else if (!strcmp(argv[1], "--setpwd"))
    {
        if (argc < 5) ThrowErrorAndExit(ERR_INVALID_ARG_SETPWD, argv[0]);
        CheckForExdbFile();
    }
    else if (!strcmp(argv[1], "--delpwd"))
    {
        if (argc < 4) ThrowErrorAndExit(ERR_INVALID_ARG_DELPWD, argv[0]);
        CheckForExdbFile();
    }
    else if (!strcmp(argv[1], "--listpwd"))
    {
        if (argc < 3) ThrowErrorAndExit(ERR_INVALID_ARG_LISTPWD, argv[0]);
        CheckForExdbFile();
    }
    else ThrowErrorAndExit(ERR_INVALID_ARGS, argv[0]);

    
    return 0;
}