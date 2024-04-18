#define __FUNC_H__
#include <iostream>
#include <string.h>
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

    void PrintArray();

    void Max_Items();

    void DoubleMax();
    void PrintResult();

};
