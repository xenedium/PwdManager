#include <iostream>
#include <fstream>

#include <base64.hpp>

using namespace std;

int main(int argc, char** argv)
{
    ifstream cin("input.txt");
    ofstream cout("inc_output.txt");

    for (size_t i = 0; i < 10000 ; i++)
    {
        string inpt;
        cin >> inpt;
        cout << B64_Encode(inpt.c_str()) << endl;
    }
    
    ifstream fcin("target.txt");
    ofstream fcout("dec_output.txt");

    for (size_t i = 0; i < 10000; i++)
    {
        string inpt;
        fcin >> inpt;
        fcout << B64_Decode(inpt.c_str()) << endl;
    }

    system("sha256sum target.txt inc_output.txt input.txt dec_output.txt && rm inc_output.txt dec_output.txt");    

    return 0;
}