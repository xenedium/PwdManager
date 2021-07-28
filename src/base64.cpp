#include <base64.hpp>

char *base64_encode(const char *data)
{
    static const char *b64_map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char *output = new char[strlen(data) * 4/3 + 4];

    char temp[3] = {0}, counter = 0, outc = 0;

    while (*data)
    {
        temp[counter++] = *data++;
        if (counter == 3)
        {
            output[outc++] = b64_map[temp[0] >> 2];
            output[outc++] = b64_map[((temp[0] << 6) | (temp[1] >> 2)) >> 2];
            output[outc++] = b64_map[((temp[1] << 4) | (temp[2] >> 4)) >> 2];
            output[outc++] = b64_map[temp[2] & 0x3F];
            counter = 0;
            memset(temp, 0, sizeof(temp));
        }
    }

    if (counter)
    {
        output[outc++] = b64_map[temp[0] >> 2];
        if (counter == 1)
        {
            output[outc++] = b64_map[(temp[0] & 0x3F) << 4];
            output[outc++] = 0x3D;
        }
        else
        {
            output[outc++] = b64_map[((temp[0] << 6) | (temp[1] >> 2)) >> 2];
            output[outc++] = b64_map[(temp[1] & 0x0F) << 2];
        }
        output[outc++] = 0x3D;
    }
    output[outc] = 0;
    return output;
}