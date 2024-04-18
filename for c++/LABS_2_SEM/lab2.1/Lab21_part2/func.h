#define __FUNC_H__
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
using namespace std;

class Number
{
    int a, b, c;
    string d;

public:
    Number()
    {
        a = 10; b = 5;
    }
    Number(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    Input();
    int Sum();
    int Comp();
    int Div();
    int Mod();
    int Pov();
    Print();
};
