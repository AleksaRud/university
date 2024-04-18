/*Рудович Александра, 1 курс, пи, фск
лаб 2.2
Создать класс массив  для решения лаб раб4 многофайловый проект

Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.
*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include "func.h"
using namespace std;

int main()
{
    srand(time(0));
    Array a(20);
    a.PrintArray();
    a.Max_Items();
    a.DoubleMax();
    a.PrintResult();
}
