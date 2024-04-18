/*Рудович Александра, 1 курс, пи, фск
лаб 2.3
Выполнить лаб работу 14 массивы 1 семестра с использованием дружественных функций и перегрузкой ввода-вывода

Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.
*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

class Array
{
private:
    int n, n1=0;
    int* Ar;
    int* ArNew;
    int maxItem;

public:
    Array();
    Array(int k);
    Array(int k, int* a);
    Array(const Array& p);
    ~Array();

    friend istream& operator>>(istream& in, Array& p);
    friend ostream& operator<< (ostream& out, Array& p);

    friend void Max_Items(Array&);
    friend void DoubleMax(Array&);

    void Result()
    {
        for(int i=0; i<n1; i++)
            cout<< ArNew[i]<< setw(3);
    }
};

Array::Array()
{
    n = 0;
    Ar = NULL;
}

Array::Array(int k)
{
    n = k;
    Ar = new int[n];
    for (int i = 0; i < n; i++)
        Ar[i] = rand()% 10;
}

Array::Array(int k, int* a)
{
    n = k;
    Ar = new int[n];
    for (int i = 0; i < n; i++)
        Ar[i] = a[i];
}

Array::Array(const Array& p)
{
    n = p.n;
    Ar = new int[n];
    for (int i = 0; i < n; i++)
        Ar[i] = p.Ar[i];
}

Array::~Array()
{
    delete[]Ar;
    delete[]ArNew;
}

void Max_Items(Array& p)
{
    p.maxItem = p.Ar[0];
    for (int i = 1; i < p.n; i++)
        if (p.Ar[i] > p.maxItem)
            p.maxItem = p.Ar[i];
}

void DoubleMax(Array& p)
{
    p.ArNew = new int [p.n*2];
    for (int i = 0; i < p.n; i++ )
    {
        if ( p.Ar[i] == p.maxItem)
            p.ArNew[p.n1++] = p.Ar[i];
        p.ArNew[p.n1++] = p.Ar[i];
    }
}

istream& operator>>(istream& in, Array& p)
{
    delete[] p.Ar;
    p.Ar = new int[p.n];
    for(int i=0; i<p.n; i++)
        in>>p.Ar[i];
    return in;
}

ostream& operator<< (ostream& out, Array& p)
{
    for(int i=0; i<p.n; i++)
        out<< p.Ar[i] << "  ";
    out << endl;
    return out;
}


int main()
{
    srand(time(0));
    Array a(10);
    cin>>a;
    cout<<a;
    Max_Items(a);
    DoubleMax(a);
    a.Result();
}
