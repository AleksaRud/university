/*Рудович Александра, 1 курс, пи, фск
лаб 2.1    часть 4
Разработать свой класс для обработки чисел с констукторами и методами для обработки

4 Класс чисел с функциями друзьями*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
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
    friend int Sum(Number& a1);
    friend int Comp(Number& a1);
    friend int Div(Number& a1);
    friend int Mod(Number& a1);
    friend int Pov(Number& a1);
    Print();
};

Number::Input()
{
    cout<<"a and b"<<endl;
    cin>>a>>b;
}

int Sum(Number &a1)
{
    a1.c = a1.a + a1.b;
    a1.d = "+";
    return a1.c;
}

int Comp(Number &a1)
{
    a1.c = a1.a * a1.b;
    a1.d = "*";
    return a1.c;
}

int Div(Number &a1)
{
    a1.c = a1.a / a1.b;
    a1.d = "/";
    return a1.c;
}

int Mod(Number &a1)
{
    a1.c = a1.a % a1.b;
    a1.d = "mod";
    return a1.c;
}

int Pov(Number &a1)
{
    a1.c = 1;
    for(int i = 1; i <= a1.b; i++)
        a1.c = a1.c * a1.a;
    a1.d = "^";
    return a1.c;
}

Number::Print()
{
    cout << a << "  " << d << "  " << b << "  =  " << c << endl;
}

int main()
{
    Number N1;
    N1.Input();
    Sum(N1); N1.Print();
    Comp(N1); N1.Print();
    Div(N1); N1.Print();
    Mod(N1); N1.Print();
    Pov(N1); N1.Print();

    Number N2;
    Sum(N2); N2.Print();
    Comp(N2); N2.Print();
    Div(N2); N2.Print();
    Mod(N2); N2.Print();
    Pov(N2); N2.Print();

    Number N3(12, 5);
    Sum(N3); N3.Print();
    Comp(N3); N3.Print();
    Div(N3); N3.Print();
    Mod(N3); N3.Print();
    Pov(N3); N3.Print();

}
