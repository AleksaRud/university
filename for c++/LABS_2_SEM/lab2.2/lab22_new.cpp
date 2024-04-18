/*Рудович Александра, 1 курс, пи, фск
лаб 2.2
Создать класс массив-шаблон  для решения лаб раб4 однофайловый проект

Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.
*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

template <class T>
class Array
{
private:
    int n, n1=0;
    T* Ar;
    T* ArNew;
    T maxItem;

public:
    Array()
    {
        n = 0;
        Ar = NULL;
    }
    Array(int k)
    {
        n = k;
        Ar = new T[n];
        for (int i = 0; i < n; i++)
            Ar[i] = rand()% 10;
    }
    Array(int k, T* a)
    {
        n = k;
        Ar = new T[n];
        for (int i = 0; i < n; i++)
            Ar[i] = a[i];
    }

    Array(const Array& p)
    {
        n = p.n;
        Ar = new T[n];
        for (int i = 0; i < n; i++)
            Ar[i] = p.Ar[i];
    }
    ~Array()
    {
        delete[]Ar;
        delete[]ArNew;
    }

    void PrintArray()
    {
        for (int i = 0; i < n; i++)
                cout<<setw(3)<< Ar[i];
        cout<<endl;
    }

    void Max_Items()
    {
        maxItem = Ar[0];
        for (int i = 1; i < n; i++)
            if (Ar[i] > maxItem)
                maxItem = Ar[i];
    }

    void DoubleMax()
    {
        ArNew = new T [n*2];

        for (int i = 0; i < n; i++ )
        {
            if ( Ar[i] == maxItem)
                ArNew[n1++] = Ar[i];
            ArNew[n1++] = Ar[i];
        }
    }

    void PrintResult()
    {
        for (int i = 0; i < n1; i++)
            cout<<setw(3)<< ArNew[i];
        cout<<endl;
    }

};

int main()
{
    srand(time(0));
    Array<int> a(20);
    a.PrintArray();
    a.Max_Items();
    a.DoubleMax();
    a.PrintResult();
}
