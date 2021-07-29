#include <iostream>
#include <fstream>

#include <base64.hpp>

using namespace std;

int main(int argc, char** argv)
{
    ifstream cin("input.txt");
    ofstream cout("enc_output.txt");
    string inpt;

    for (size_t i = 0; i < 0x1000 ; i++)
    {
        cin >> inpt;
        cout << B64_Encode(inpt.c_str()) << endl;
    }
    
    ifstream fcin("enc_target.txt");
    ofstream fcout("dec_output.txt");

    for (size_t i = 0; i < 0x1000; i++)
    {
        
        fcin >> inpt;
        fcout << B64_Decode(inpt.c_str()) << endl;
    }
    
    return 0;
}