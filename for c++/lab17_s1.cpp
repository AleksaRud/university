/* Рудович Александра, 1 курс, пи, фск
Сортировка элементов массива по убыванию:
1. берётся максимальное значение, максимальное перемещается в начало
2. Затем рассматривается массив без первого элемента
3. проделывается та же операция, что и для всего массива и т.д.

*/


#include <iostream>
#include "sort.h"
using namespace std;


int main()
{
    int* a = 0;
    int n;

    input_parameters(&n);
    a = new int[n];
    a = input_mass(a, n);
    print_mass(a, n);

    sort_1(a, n);
    print_res(a, n);
    delete a;
}
