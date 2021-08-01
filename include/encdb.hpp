#ifndef ENCDB_HPP_INCLUDED
#define ENCDB_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <err.hpp>
#include <sha512.hpp>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <linux/limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif



void CheckForExdbFile();
void GenereateExdbFile();



#endif