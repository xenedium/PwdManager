#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <pthread.h>

using namespace std;

const char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void *GenerateLine(void *vcout)
{
    for (uint32_t i = 0; i < 0xFFFF; i++)
    {
        uint8_t pwdlen = rand() % 0x50;
        for (uint8_t i = 0; i < pwdlen + 1; i++) *(ofstream *)vcout << alpha[rand() % 63];
        *(ofstream *)vcout << endl;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread[100];
    srand(time(NULL));

    ofstream fcout("input.txt");

    GenerateLine(&fcout);
    
}
