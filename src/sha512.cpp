#include <sha512.hpp>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cstdint>
#include <sstream>

typedef unsigned __int128 uint128;

SHA512::SHA512()
{
}

SHA512::~SHA512()
{
}

uint8_t* SHA512::hash(const std::string input)
{
    size_t nBuffer;
    uint64_t **buffer;
    uint64_t *h = new uint64_t[8];
    buffer = preprocess((unsigned char *)input.c_str(), nBuffer);
    process(buffer, nBuffer, h);
    freeBuffer(buffer, nBuffer);
    return (uint8_t*)h;
}

uint64_t **SHA512::preprocess(const unsigned char *input, size_t &nBuffer)
{
    size_t mLen = strlen((const char *)input);
    size_t kLen = (895 - (mLen * 8)) % 1024;
    nBuffer = (mLen * 8 + 1 + kLen + 128) / 1024;

    uint64_t **buffer = new uint64_t *[nBuffer];

    for (size_t i = 0; i < nBuffer; i++)
    {
        buffer[i] = new uint64_t[SEQUENCE_LEN];
    }

    for (size_t i = 0; i < nBuffer; i++)
    {
        for (size_t j = 0; j < SEQUENCE_LEN; j++)
        {
            uint64_t in = 0x0ULL;
            for (size_t k = 0; k < 8; k++)
            {
                if (i * 128 + j * 8 + k < mLen)
                {
                    in = in << 8 | (uint64_t)input[i * 128 + j * 8 + k];
                }
                else if (i * 128 + j * 8 + k == mLen)
                {
                    in = in << 8 | 0x80ULL;
                }
                else
                {
                    in = in << 8 | 0x0ULL;
                }
            }
            buffer[i][j] = in;
        }
    }

    appendLen(mLen, 8, buffer[nBuffer - 1][SEQUENCE_LEN - 1], buffer[nBuffer - 1][SEQUENCE_LEN - 2]);
    return buffer;
}

void SHA512::process(uint64_t **buffer, size_t nBuffer, uint64_t *h)
{
    uint64_t s[8];
    uint64_t w[80];

    memcpy(h, hPrime, 8 * sizeof(uint64_t));

    for (size_t i = 0; i < nBuffer; i++)
    {
        //message schedule
        memcpy(w, buffer[i], 16 * sizeof(uint64_t));

        for (size_t j = 16; j < 80; j++)
        {
            w[j] = w[j - 16] + sig0(w[j - 15]) + w[j - 7] + sig1(w[j - 2]);
        }
        //init
        memcpy(s, h, 8 * sizeof(uint64_t));
        //compression
        for (size_t j = 0; j < 80; j++)
        {
            uint64_t temp1 = s[7] + Sig1(s[4]) + Ch(s[4], s[5], s[6]) + k[j] + w[j];
            uint64_t temp2 = Sig0(s[0]) + Maj(s[0], s[1], s[2]);

            s[7] = s[6];
            s[6] = s[5];
            s[5] = s[4];
            s[4] = s[3] + temp1;
            s[3] = s[2];
            s[2] = s[1];
            s[1] = s[0];
            s[0] = temp1 + temp2;
        }

        for (size_t j = 0; j < 8; j++)
        {
            h[j] += s[j];
        }
    }
}

void SHA512::appendLen(uint64_t mLen, uint64_t mp, uint64_t &lo, uint64_t &hi)
{
    uint128 prod = mLen * mp;
    lo = prod;
    hi = prod >> 64;
}


void SHA512::freeBuffer(uint64_t **buffer, size_t nBuffer)
{
    for (size_t i = 0; i < nBuffer; i++)
    {
        delete[] buffer[i];
    }

    delete[] buffer;
}