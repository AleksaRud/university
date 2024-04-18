#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string str;

    ifstream in("Input.txt");
    if (in.is_open())
    {
        in.ignore(100, ' ');
        getline(in, str, ' ');

            cout << str <<endl;
        }

    in.close();
    cout<<str;
}
