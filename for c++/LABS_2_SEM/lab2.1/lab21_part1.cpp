/*Рудович Александра, 1 курс, пи, фск
лаб 2.1    часть 1
Разработать свой класс для обработки чисел с констукторами и методами для обработки

1. Однофайловый проект*/


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
    int Sum();
    int Comp();
    int Div();
    int Mod();
    int Pov();
    Print();
};

Number::Input()
{
    cout<<"a and b"<<endl;
    cin>>a>>b;
}

int Number::Sum()
{
    c = a + b;
    d = "+";
    return c;
}

int Number::Comp()
{
    c = a * b;
    d = "*";
    return c;
}

int Number::Div()
{
    c = a / b;
    d = "/";
    return c;
}

int Number::Mod()
{
    c = a % b;
    d = "mod";
    return c;
}

int Number::Pov()
{
    c = 1;
    for(int i = 1; i <= b; i++)
        c = c * a;
    d = "^";
    return c;
}

Number::Print()
{
    cout << a << "  " << d << "  " << b << "  =  " << c << endl;
}

int main()
{
    Number N1;
    N1.Input();
    N1.Sum(); N1.Print();
    N1.Comp(); N1.Print();
    N1.Div(); N1.Print();
    N1.Mod(); N1.Print();
    N1.Pov(); N1.Print();

    Number N2;
    N2.Sum(); N2.Print();
    N2.Comp(); N2.Print();
    N2.Div(); N2.Print();
    N2.Mod(); N2.Print();
    N2.Pov(); N2.Print();

    Number N3(12, 5);
    N3.Sum(); N3.Print();
    N2.Comp(); N3.Print();
    N3.Div(); N3.Print();
    N3.Mod(); N3.Print();
    N3.Pov(); N3.Print();

}
