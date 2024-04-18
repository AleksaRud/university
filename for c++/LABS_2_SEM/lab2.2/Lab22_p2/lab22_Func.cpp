
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include <time.h>
#include "func.h"
using namespace std;

Array::Array()
{
	n = 0;
	Ar = NULL;
};
Array::Array(int k)
{
	n = k;
	Ar = new int[n];
	for (int i = 0; i < n; i++)
		Ar[i] = rand()% 10;
};
Array::Array(int k, int* a)
{
	n = k;
	Ar = new int[n];
	for (int i = 0; i < n; i++)
		Ar[i] = a[i];
};
Array::Array(const Array& p)
{
	n = p.n;
	Ar = new int[n];
	for (int i = 0; i < n; i++)
		Ar[i] = p.Ar[i];
};
Array::~Array()
{
	delete[]Ar;
	delete[]ArNew;
};

void Array::PrintArray()
{
	for (int i = 0; i < n; i++)
			cout<<setw(3)<< Ar[i];
    cout<<endl;

};
void Array::Max_Items()
{
	maxItem = Ar[0];
	for (int i = 1; i < n; i++)
		if (Ar[i] > maxItem)
			maxItem = Ar[i];
};


void Array::DoubleMax()
{
    ArNew = new int [n*2];

    for (int i = 0; i < n; i++ )
    {
        if ( Ar[i] == maxItem)
            ArNew[n1++] = Ar[i];
        ArNew[n1++] = Ar[i];
    }
};

void Array::PrintResult()
{
	for (int i = 0; i < n1; i++)
			cout<<setw(3)<< ArNew[i];
    cout<<endl;
};
