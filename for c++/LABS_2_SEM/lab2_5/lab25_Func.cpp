
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include <time.h>
#include "func.h"
using namespace std;

Money::Money()
{
    pound = 0;
    shilling = 0;
    penny = 0;
};

Money::Money(int pd, int sh, int p)
{
    if (pd < 0 || sh < 0 || p < 0) throw "Under zero";
    if (sh > 20 || p > 12 || pd > 1000000000) throw "Out of range";
    pound = pd;
    shilling = sh;
    penny = p;
};

Money operator  + (const  Money& e1, const  Money& e2)
{
    Money m;
    m.pound=e1.pound + e2.pound;
    if(e1.shilling+e2.shilling >= 20)
    {
        m.pound = m.pound +1;
        m.shilling = e1.shilling+e2.shilling - 20;
    }
    else
        m.shilling=e1.shilling + e2.shilling;

    if(e1.penny+e2.penny >= 12)
    {
        m.shilling = m.shilling +1;
        if (m.shilling >= 20)
        {
            m.shilling = m.shilling - 20;
            m.pound = m.pound +1;
        }
        m.penny = e1.penny+e2.penny - 12;
    }
    else
        m.penny=e1.penny + e2.penny;
    return m;
};

Money operator  - (const  Money& e1, const  Money& e2)
{
    Money m;
    m.pound=e1.pound - e2.pound;
    if(e1.shilling-e2.shilling <0)
    {
        m.pound = m.pound -1;
        m.shilling = e1.shilling-e2.shilling + 20;
    }
    else
        m.shilling=e1.shilling - e2.shilling;

    if(e1.penny-e2.penny <0)
    {
        m.shilling = m.shilling -1;
        if (m.shilling < 0)
        {
            m.shilling = 19;
            m.pound = m.pound -1;
        }
        m.penny = e1.penny-e2.penny +12;
    }
    else
        m.penny=e1.penny - e2.penny;
    return m;
};

bool operator  == (const  Money& e1, const  Money& e2)
{
    return (e1.pound*20*12 + e1.shilling*12 + e1.penny) == (e2.pound*20*12 + e2.shilling*12 + e2.penny);
};

bool operator  < (const  Money& e1, const  Money& e2)
{
    return (e1.pound*20*12 + e1.shilling*12 + e1.penny) < (e2.pound*20*12 + e2.shilling*12 + e2.penny);
};


