/* Рудович Александра, 1 курс, пи, фск, лаб14
11)	Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.

*/


#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

//ввод массива
int* input_m( int a[], int *n)
{
    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> *n;
    }
    while ( *n > 100);

    a = new int [*n];
    srand(time(0));

    for ( int i = 0; i < *n; i++)
        a[i] = rand() % 100;

    return a;
}

//вывод массива
void print_m ( int a[], int n)
{
    cout << "a:";
    for ( int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;

}

//находим значение наибольших элементов массива
int max_(int a[], int n)
{

    int M = a[0];
    for ( int i = 0; i < n; i++ )
    {
        if ( a[i] >= M)
            M = a[i];
    }
    cout << "max: " << M << endl;
    return M;

}

//дублируем и выводим максимальный элемент
void double_max(int a[], int n, int b[], int M)
{

    int k=0, i;
    b = new int [n];
    for ( i = 0; i < n; i++ )
    {
        if ( a[i] == M)
            b[k++] = a[i];
        b[k++] = a[i];
    }

    cout << "b:";
    for ( i = 0; i < k; i++)
      cout << setw(4) << b[i];

}


int main()
{
    int *a=0, *b=0;
    int n, M;

    a = input_m(a, &n);
    print_m(a, n);

    M = max_(a, n);
    double_max(a, n, b, M);
}
