#define __FUNC_H__
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
using namespace std;

class Array
{
public:
    int n;
    int* Ar;
    int* ArNew;

    Array();
    Array(int k);
    Array(int k, int* a);
    Array(const Array& p);
    ~Array();



    friend istream& operator>>(istream& in, Array& p);
    friend ostream& operator<< (ostream& out, Array& p);

    friend bool Chet(Array& t, int i)
    {
        int x = t.Ar[i];
        while(x>0)
        {
            if((x%10)%2 == 0)
                return true;
            x = x/10;
        }
        return false;
    }


    Array&  operator -= (Array&  p)
    {

        for (int i = 0; i < p.n-1; i++ )
        {

            if (!Chet(p, i+1))
                ArNew[i] = p.Ar[i+1];
            else
                ArNew[i] = p.Ar[i];
        }
        ArNew[n-1] = p.Ar[n-1];
        return *this;
    }


};

