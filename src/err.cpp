#include <err.hpp>
using namespace std;

void ThrowErrorAndExit(uint8_t error, const char* val)
{
    switch (error)
    {
    case ERR_INVALID_ARGS:
        cerr << "Unvalid arguments.\n" << "Usage: " << val << " --help" << endl;
        break;
    case ERR_INVALID_ARG_GETPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << val << " --getpwd [pwd] [name]" << endl;
        break;
    case ERR_INVALID_ARG_SETPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << val << " --setpwd [pwd] [name] [password]" << endl;
        break;
    case ERR_INVALID_ARG_DELPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << val << " --delpwd [pwd] [name]" << endl;
        break;
    case ERR_INVALID_ARG_LISTPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << val << " --listpwd [pwd]" << endl;
        break;
    case ERR_CANNOT_CREATE_PWD_FILE:
        cerr << "Cannot create password file." << endl;
        break;
    }
    exit(EXIT_FAILURE);
}
