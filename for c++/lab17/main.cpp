/* Рудович Александра, 1 курс, пи, фск
Сортировка элементов массива по убыванию пузырьковым методом

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

    sort_2(a, n);
    print_res(a, n);
    delete a;
}
