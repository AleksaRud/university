#define __FUNC_H__
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
using namespace std;

class Money
{
private:
    int pound;
    int shilling;
    int penny;

public:
    Money();
    Money(int pd, int sh, int p);


    Money& operator-()
    {
        pound = -pound;
        shilling = -shilling;
        penny = -penny;
        return *this;
    }

    Money& operator=(const Money& e)
    {
        pound = e.pound;
        shilling = e.shilling;
        penny = e.penny;
        return *this;
    }

    Money& operator+=( const Money& e)
    {
        pound+=e.pound;
        if(shilling+e.shilling >= 20)
        {
            pound = pound +1;
            shilling += shilling+e.shilling - 20;
        }
        else
            shilling+= e.shilling;

        if(penny+e.penny >= 12)
        {
            shilling = shilling +1;
            if (shilling >= 20)
            {
                shilling = shilling - 20;
                pound = pound +1;
            }
            penny = penny+e.penny - 12;
        }
        else
            penny+=e.penny;
        return *this;
    }

    Money& operator-=( const Money& e)
    {
        pound-=e.pound;

        if(shilling-e.shilling <0)
        {
            pound = pound -1;
            shilling = shilling-e.shilling + 20;
        }
        else
            shilling-=e.shilling;

        if(penny-e.penny <0)
        {
            shilling = shilling -1;
            if (shilling < 0)
            {
                shilling = 19;
                pound = pound -1;
            }
            penny = penny-e.penny +12;
        }
        else
            penny-= e.penny;

        return *this;
    }

    friend  Money operator  + (const  Money& e1, const  Money& e2);
    friend  Money operator  - (const  Money& e1, const  Money& e2);
    friend  bool operator  == (const  Money& e1, const  Money& e2);
    friend  bool operator  < (const  Money& e1, const  Money& e2);

    friend istream& operator>>(istream& in, Money& e)
{
    in>> e.pound >> e.shilling >> e.penny;
    if (e.pound < 0 || e.shilling < 0 || e.penny < 0) throw "Under zero";
    if (e.shilling > 20 || e.penny > 12 || e.pound > 1000000000) throw "Out of range";
    return in;
}
    friend ostream& operator<< (ostream& out, Money& e)
    {
    out << e.pound << " pd. " << e.shilling << " sh. " << e.penny << " p. " << endl;
    return out;
}
};
