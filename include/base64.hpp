#ifndef BASE64_HPP_INCLUDED
#define BASE64_HPP_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <iostream>

typedef unsigned char uint8_t;


//encode a null terminated string
char *B64_Encode(const char *data);

//decode a null terminated b64 encoded string
char *B64_Decode(const char *data);

#endif