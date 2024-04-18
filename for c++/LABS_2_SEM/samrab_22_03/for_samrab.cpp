
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
	n = rand()% 8 + 2;
	Ar = new int[n];
	ArNew = new int [n];
	for (int i = 0; i < n; i++)
    {
        Ar[i] = rand()% 100;
        ArNew[i] = Ar[i];
    }

};

Array::Array(int k)
{
    if (k>50) throw "Array's size must be <=50";
	n = k;
	Ar = new int[n];
	ArNew = new int [n];
	for (int i = 0; i < n; i++)
    {
        Ar[i] = rand()% 100;
        ArNew[i] = Ar[i];
    }

};

Array::Array(int k, int* a)
{
    if (k>50) throw "Array's size must be <=50";
	n = k;
	Ar = new int[n];
	ArNew = new int [n];
	for (int i = 0; i < n; i++)
    {
        Ar[i] = a[i];
        ArNew[i] = Ar[i];
    }

};
Array::Array(const Array& p)
{
	n = p.n;
	Ar = new int[n];
	ArNew = new int [n];
	for (int i = 0; i < n; i++)
    {
        Ar[i] = p.Ar[i];
        ArNew[i] = Ar[i];
    }

};

Array::~Array()
{
	delete[]Ar;
	delete[]ArNew;
};



istream& operator>>(istream& in, Array& p)
{
    delete[] p.Ar;
    p.Ar = new int[p.n];
    for(int i=0; i<p.n; i++)
        in>>p.Ar[i];
    return in;
};

ostream& operator<< (ostream& out, Array& p)
{
    for(int i=0; i<p.n; i++)
        out<< p.Ar[i] << "  ";
    out << endl;
    for(int i=0; i<p.n; i++)
        out<< p.ArNew[i] << "  ";
    out << endl;
    return out;
};



