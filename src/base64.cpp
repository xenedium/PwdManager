#include <base64.hpp>

const char *B64_MAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


uint8_t B64_FetchIndex(const char b64_ch)
{
    uint8_t pos ;
    for(pos = 0; pos < 64 && B64_MAP[pos] != b64_ch; pos++);
    return pos;
}

char *B64_Encode(const char *data)
{
    
    char *output = new char[strlen(data) * 4/3 + 4];

    char temp[3] = {0}, counter = 0, outc = 0;

    while (*data)
    {
        temp[counter++] = *data++;
        if (counter == 3)
        {
            output[outc++] = B64_MAP[temp[0] >> 2];
            output[outc++] = B64_MAP[(uint8_t)((uint8_t)(temp[0] << 6) | (uint8_t)(temp[1] >> 2)) >> 2];
            output[outc++] = B64_MAP[(uint8_t)((uint8_t)(temp[1] << 4) | (uint8_t)(temp[2] >> 4)) >> 2];
            output[outc++] = B64_MAP[temp[2] & 0x3F];
            counter = 0;
        }
    }

    if (counter)
    {
        output[outc++] = B64_MAP[temp[0] >> 2];
        if (counter == 1)
        {
            output[outc++] = B64_MAP[(temp[0] & 0x03) << 4];
            output[outc++] = 0x3D;
        }
        else
        {
            output[outc++] = B64_MAP[(uint8_t)((uint8_t)(temp[0] << 6) | (uint8_t)(temp[1] >> 2)) >> 2];
            output[outc++] = B64_MAP[(temp[1] & 0x0F) << 2];
        }
        output[outc++] = 0x3D;
    }
    output[outc] = 0;
    return output;
}

char *B64_Decode(const char *data)
{
    char *output = new char[strlen(data) * 3/4];
    uint8_t counter = 0, outc = 0, idx;
    char temp[4] = {0};

    while(*data)
    {
        temp[counter++] = *data++;
        if (counter == 4)
        {
            output[outc++] = (B64_FetchIndex(temp[0]) << 2) | (B64_FetchIndex(temp[1]) >> 4);
            if ((idx = B64_FetchIndex(temp[2])) != 64) output[outc++] = (uint8_t)(B64_FetchIndex(temp[1]) << 4) | (idx >> 2);
            if ((idx = B64_FetchIndex(temp[3])) != 64) output[outc++] = (uint8_t)(B64_FetchIndex(temp[2]) << 6) | (idx);
            counter = 0;
        }
    }

    output[outc] = 0;
    return output;
}
