/*Рудович Александра, 1 курс, пи, фск
лаб 2.7

Создать базовый класс Figure, который включает в себя:
- два числа типа double, которые являются либо длиной и шириной, либо основанием и высотой;
- конструктор с параметрами.
Первый производный класс Rectangle, который включает в себя:
- статическое поле имя фигуры;
- конструктор с параметрами;
- метод расчета площади square;
- метод расчета периметра perimeter();
- метод просмотра (наименование фигуры, площадь и периметр).
Второй производный класс Triangle, который включает в себя:
- статическое поле имя фигуры;
- конструктор с параметрами;
- метод расчета площади square;
- метод расчета периметра perimeter();
- метод просмотра (наименование фигуры, площадь и периметр

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
protected:
    double a, b;
    Figure(double a1, double b1): a(a1), b(b1) {};
};

class Rectangle: protected Figure
{

public:
    static string name;
    Rectangle(double a1, double b1): Figure(a1,b1) {}
    int square()
    {
        return a*b;
    }
    int perimeter()
    {
        return 2*(a+b);
    }
    void show()
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
    int square()
    {
        return a*b*0.5;
    }
    int perimeter()
    {
        return (a + 2*sqrt(b*b + 0.25*a*a));
    }
    void show()
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
