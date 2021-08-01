#ifndef ARGS_HPP_INCLUDED
#define ARGS_HPP_INCLUDED

#define ERR_INVALID_ARGS 0x1
#define ERR_INVALID_ARG_GETPWD 0x2
#define ERR_INVALID_ARG_SETPWD 0x4
#define ERR_INVALID_ARG_DELPWD 0x8
#define ERR_INVALID_ARG_LISTPWD 0x10
#define ERR_CANNOT_CREATE_PWD_FILE 0x20


#include <iostream>

void ThrowErrorAndExit(uint8_t error, const char* val);

#endif