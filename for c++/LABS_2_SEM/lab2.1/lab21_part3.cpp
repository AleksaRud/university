/*Рудович Александра, 1 курс, пи, фск
лаб 2.1    часть 3
Разработать свой класс для обработки чисел с констукторами и методами для обработки

3 Класс чисел шаблон (однофайловый проект)*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

template <class T>
class Number
{
    T a, b, c;
    string d;

public:
    Number()
    {
        a = 10; b = 5;
    }

    Number(T a1, T b1)
    {
        a = a1;
        b = b1;
    }

    Input()
    {
        cout<<"a and b"<<endl;
        cin>>a>>b;
    }

    T Sum()
    {
        c = a + b;
        d = "+";
        return c;
    }

    T Comp()
    {
        c = a * b;
        d = "*";
        return c;
    }

    T Div()
    {
        c = a / b;
        d = "/";
        return c;
    }

    T Mod()
    {
        c = a % b;
        d = "mod";
        return c;
    }

    T Pov()
    {
        c = 1;
        for(int i = 1; i <= b; i++)
            c = c * a;
        d = "^";
        return c;
    }

    Print()
    {
        cout << a << "  " << d << "  " << b << "  =  " << c << endl;
    }

};


int main()
{
    Number<int> N1;
    N1.Input();
    N1.Sum(); N1.Print();
    N1.Comp(); N1.Print();
    N1.Div(); N1.Print();
    N1.Mod(); N1.Print();
    N1.Pov(); N1.Print();

    Number<int> N2;
    N2.Sum(); N2.Print();
    N2.Comp(); N2.Print();
    N2.Div(); N2.Print();
    N2.Mod(); N2.Print();
    N2.Pov(); N2.Print();

    Number<int> N3(12, 5);
    N3.Sum(); N3.Print();
    N2.Comp(); N3.Print();
    N3.Div(); N3.Print();
    N3.Mod(); N3.Print();
    N3.Pov(); N3.Print();

}
