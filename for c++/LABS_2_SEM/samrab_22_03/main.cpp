/*Рудович Александра, 1 курс, пи, фск

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
    srand(time(0));
    try
    {

        Array a(15);
        cout<<"A: " << endl;
        cout<<a;
        cout<<endl;
        a-=a;
        cout<<"Result"<<endl;
        cout << a;
        cout<<endl;

        Array c;
        cout<<"C: " << endl;
        cout<<c;
        cout<<endl;
        c-=c;
        cout<<"Result"<<endl;
        cout << c;
        cout<<endl;

        cout<<"B: "<<endl;
        Array b(63);
        cout<<b;
        cout<<endl;
        b-=b;
        cout<<"Result"<<endl;
        cout << b;
    }
    catch(const char* er)
    {
        cout<< "Error: "<< er << endl;
    }

}
