#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string str[30], space = " ";

    ifstream in("spisok.txt");
    if (in.is_open())
    {
        int i=0;
        while (getline(in, str[i]))
        {
            cout << str[i]  <<endl;
            i++;
        }

    }
    in.close();

}
