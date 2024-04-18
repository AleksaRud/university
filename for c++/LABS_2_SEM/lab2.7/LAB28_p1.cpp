/*Рудович Александра, 1 курс, пи, фск
лаб 2.8

a)	Создать абстрактный класса Figure, который включает в себя данные-элементы:
    -статическое поле first;
    -поле next;
    -два числа два числа типа double, которые являются либо длиной и шириной, либо основанием и высотой.
    функции-члены класса:
    -конструктор с параметрами;
    -чисто виртуальные функции расчета площади, периметра и просмотра;
    -метод просмотра всего списка.
b)	Первый производный класс Rectangle, который включает в себя:
    -статическое поле имя фигуры;
    -конструктор с параметрами;
    -переопределенный метод расчета площади square;
    -переопределенный метод расчета периметра perimeter();
    -переопределенный метод просмотра (наименование фигуры, площадь и периметр).
c)	Второй производный класс Triangle, который включает в себя:
    -статическое поле имя фигуры;
    -конструктор с параметрами;
    -переопределенный метод расчета площади square;
    -переопределенный метод расчета периметра perimeter();
    -переопределенный метод просмотра (наименование фигуры, площадь и периметр).

*/

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

class Figure
{
public:
    static string first;
    string next;
    double a, b;
    Figure(double a1, double b1): a(a1), b(b1) {};
    virtual int square() = 0;
    virtual int perimeter() = 0;
    virtual void show() = 0;
    void show_all()
    {
        cout<<"Figure"<<endl;
        cout<<first<<endl;
        cout<< a << setw(3)<<b<<endl;
        cout<<next<<endl;
    }

};
string Figure::first = "First";

class Rectangle: protected Figure
{

public:
    static string name;
    Rectangle(double a1, double b1): Figure(a1,b1) {}
    virtual int square()
    {
        return a*b;
    }
    virtual int perimeter()
    {
        return 2*(a+b);
    }
    virtual void show()
    {
        cout<< Rectangle::name << endl;
        cout<< "Length: " << a << "   Width: "  << b << endl;
        cout<< "Square: " << square() << endl;
        cout<< "Perimeter: " << perimeter() << endl;
        cout<<endl;
    }
};
string Rectangle::name = "Rectangle";

class Triangle: protected Figure
{
public:
    static string name;
    Triangle(double a1, double b1): Figure(a1,b1) {}
    virtual int square()
    {
        return a*b*0.5;
    }
    virtual int perimeter()
    {
        return (a + 2*sqrt(b*b + 0.25*a*a));
    }
    virtual void show()
    {
        cout<< Triangle::name << endl;
        cout<< "Base: " << a << "   Height: " << b << endl;
        cout<< "Square: " << square() << endl;
        cout<< "Perimeter: " << perimeter() << endl;
        cout<<endl;
    }
};
string Triangle::name = "Triangle";

int main()
{
    Rectangle A(2, 5);
    A.show();
    Triangle B(8, 3);
    B.show();
}
