#include <args.hpp>
using namespace std;

void ThrowErrorAndExit(uint8_t error, const char* argv0)
{
    switch (error)
    {
    case ERR_INVALID_ARGS:
        cerr << "Unvalid arguments.\n" << "Usage: " << argv0 << " --help" << endl;
        break;
    case ERR_INVALID_ARG_GETPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << argv0 << " --getpwd [pwd] [name]" << endl;
        break;
    case ERR_INVALID_ARG_SETPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << argv0 << " --setpwd [pwd] [name] [password]" << endl;
        break;
    case ERR_INVALID_ARG_DELPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << argv0 << " --delpwd [pwd] [name]" << endl;
        break;
    case ERR_INVALID_ARG_LISTPWD:
        cerr << "Unvalid arguments.\n" << "Usage: " << argv0 << " --listpwd [pwd]" << endl;
        break;
    }
    exit(EXIT_FAILURE);
}
