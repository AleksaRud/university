/*Рудович Александра, 1 курс пи фск, группа 14

	В представлении десятичного  целого  числа в n-ой системе счисления (2<=n<=9) найти количество цифр

*/

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;


class Number
{
    int a, b = 0, n;    // а - целое десятичное число
                        // n - показательсистемы счисления
                        // b - число цифр

public:
    Number()
    {
        a = 10; n = 2;
    }
    Number(int a1, int n1)
    {
        a = a1;
        n = n1;
    }
    void Input();
    int Solve();
    void Print();
};

void Number::Input()
{

    cout<<"input a > 0"<<endl;
    cin>>a;
    if (a<=0)
        throw exception("Division by zero!");


    cout<<"input n 2<=n<=9"<<endl;
    cin>>n;
    if (n > 9 || n < 2)
        throw runtime_error("Uncorrect number, (n) must be <=9 and >=2");

}

int Number::Solve()
{
    int c = a;
    while(c>0)
    {
        b++;
        c=c/n;
    }
    return b;
}

void Number::Print()
{
    cout <<a << "  in  " << n << "  number system it has  " << b << "  numbers  " << endl;
}

int main()
{
    try
    {
        Number N;
        N.Input();
        N.Solve();
        N.Print();
    }
    catch(runtime_error Er)
    {
        cout << "Error. " << Er.what() << endl;
    }

catch(exception Er)
    {
        cout << "Error. " << Er.what() << endl;
    }
}
