
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include "func.h"
using namespace std;

Number::Input()
{
    cout<<"a and b"<<endl;
    cin>>a>>b;
};

int Number::Sum()
{
    c = a + b;
    d = "+";
    return c;
};

int Number::Comp()
{
    c = a * b;
    d = "*";
    return c;
};

int Number::Div()
{
    c = a / b;
    d = "/";
    return c;
};

int Number::Mod()
{
    c = a % b;
    d = "mod";
    return c;
};

int Number::Pov()
{
    c = 1;
    for(int i = 1; i <= b; i++)
        c = c * a;
    d = "^";
    return c;
};

Number::Print()
{
    cout << a << "  " << d << "  " << b << "  =  " << c << endl;
};
