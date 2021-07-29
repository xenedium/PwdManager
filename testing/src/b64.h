#ifndef BASE64_H
#define BASE64_H

#include <stdlib.h>
#include <memory.h>
#include <string.h>


/***********************************************
Encodes ASCCI string into base64 format string
@param plain ASCII string to be encoded
@return encoded base64 format string
***********************************************/
char* base64_encode(const char* plain);


/***********************************************
decodes base64 format string into ASCCI string
@param plain encoded base64 format string
@return ASCII string to be encoded
***********************************************/
char* base64_decode(const char* cipher);


#endif //BASE64_H