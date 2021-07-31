#ifndef ARGS
#define ARGS

#define ERR_INVALID_ARGS 0x1
#define ERR_INVALID_ARG_GETPWD 0x2
#define ERR_INVALID_ARG_SETPWD 0x4
#define ERR_INVALID_ARG_DELPWD 0x8
#define ERR_INVALID_ARG_LISTPWD 0x10


#include <iostream>

void ThrowErrorAndExit(uint8_t error, const char* argv0);

#endif