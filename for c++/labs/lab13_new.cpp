/*Рудович Александра, 1 курс, пи, фск

лаб 13 вариант 13

Значение аргумента x изменяется от a до b с шагом h. Для каждого x
найти значения функции Y(x), суммы S(x) и |Y(x)-S(x)| и вывести в виде
таблицы. Значения a,b,h и n вводятся с клавиатуры. Так как значение S(x)
является рядом разложения функции Y(x), то значения S и Y для данного
аргумента x должны совпадать в целой части и в первых двух-четырех позициях после десятичной точки.
Работу программы проверить для a=0,1; b=1,0; h=0,1; n выбрать максимально возможным

S(x) = ((-1)^1) * ((2*x)^(2*1)) / ((2*1)!) + ((-1)^2) * ((2*x)^(2*2)) / ((2*2)!) + ... + ((-1)^k) * ((2*x)^(2*k)) / ((2*k)!)
Y(x) = 2 * ( cos(x)^2 - 1)

n максимальное 19

n = 19  a = 0.1  b = 1.0  h = 0.1
===========================================================
|  x  |     s(x)     ||     y(x)     ||   | y(x)-s(x) |   |
===========================================================
|  0.1|    -0.0199334||    -0.0199334||   2.22045e-16     |
|  0.2|     -0.078939||     -0.078939||   2.77556e-17     |
|  0.3|     -0.174664||     -0.174664||   2.77556e-17     |
|  0.4|     -0.303293||     -0.303293||   1.66533e-16     |
|  0.5|     -0.459698||     -0.459698||   5.55112e-17     |
|  0.6|     -0.637642||     -0.637642||   1.11022e-16     |
|  0.7|     -0.830033||     -0.830033||   7.59393e-14     |
|  0.8|       -1.0292||       -1.0292||   1.15672e-11     |
|  0.9|       -1.2272||       -1.2272||   9.91073e-10     |
|    1|      -1.41615||      -1.41615||   5.38416e-08     |
=========================================================== */




#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double pow(double v, int j)
{
    double g = 1.0;
    for(int i = 1; i <= j; i++)
        g = g * v;
    return g;
}

long long int factorial(int j)
{
    long long int f = 1;
    for (int i = 1; i <= j; i++)
        f = f * i;
    return f;
}

double Sx (double a, int b)
{
    double S = 0.0, p1, p2, p3, p4;
    p1 = pow((2*a), (2*b)); //pow
    p2 = pow((-1) , b) * p1;
    p3 = factorial((2*b)); //factorial
    p4 = p2 / p3;
    S = S + p4;
    return S;
}

int main()
{
    int  n;
    double s, y, y_s, x, a, b, h;
    double p1, p2, p3, p4;
    do
    {
        cout << "input integer n > 0" << endl << "n = ";
        cin >> n;
    }
    while (n <= 0);

    cout << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "h = ";
    cin >> h;
    cout << endl;
    cout << "===========================================================" << endl;
    cout << "|  x  |     s(x)     ||     y(x)     ||   | y(x)-s(x) |   |" << endl;
    cout << "===========================================================" << endl;
    for ( x = a; x <= b; x+=h)
    {
        s = 0.0;
        for ( int k = 1; k <= n; k++ )
        {
            s = s + Sx( x, k);

        }

        y =  2 * ( cos(x) * cos(x) - 1) ;

        if (y > s)
            y_s = y - s;
        else
            y_s = s - y;
		cout << "|" << setw(5) << x << "|" << setw(14) << s << "||" << setw(14) << y << "||" << setw(14) << y_s << "     |" << endl;

    }
    cout << "===========================================================" << endl;
    return 0;
}