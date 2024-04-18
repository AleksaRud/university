/*Рудович Александра, 1 курс, пи, фск
лаб 2.5
Реализовать класс для обработки денежных единиц
*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include "func.h"
using namespace std;

int main()
{
    try
    {
        Money a(2,3,4), b, c;

        cout<< "Input b(pd, sh, p): pd>=0, 20>sh>=0, 12>p>=0" << endl;
        cin>>b;

        cout<<setw(7)<<"a:"<<setw(3);
        cout<<a;
        cout<<setw(7) << "b:" << setw(3);
        cout<< b;

        cout<<setw(7)<<"c=a+b:"<< setw(3);
        c = a+b;
        cout<< c;

        cout<<setw(7)<<"c-=a:"<< setw(3);
        c-=a;
        cout<<c;

        cout<<setw(7)<<"c+=b:"<< setw(3);
        c+=b;
        cout<<c;

        cout<<setw(7)<<"c=a-b:"<< setw(3);
        c = a-b;
        cout<< c ;

        cout<<setw(7) << "-a:"<<setw(3);
        c = -a;
        cout << c;

        if(a == b)
            cout << "a = b"<<endl;
        else
        {
            if (a < b)
                cout << "a < b" << endl;
            else
                cout << " a > b" << endl;
        }
        cout<< a;
    }
    catch(const char* er)
    {
        cout<< "Error: "<< er << endl;
    }

}
