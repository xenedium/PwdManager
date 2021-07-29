#include <iostream>
#include <fstream>

#include <base64.hpp>

using namespace std;

int main(int argc, char** argv)
{
    ifstream cin("input.txt");
    ofstream cout("ouput.txt");

    for (uint8_t i = 0; i < 0xff ; i++)
    {
        string inpt;
        cin >> inpt;
        cout << B64_Encode(inpt.c_str()) << endl;
    }
    

    return 0;
}