/* Рудович Александра, 1 курс, пи, фск, лаб14
11)	Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.

*/


#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void input_m( int a[], int *n)
{
    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> *n;
    }
    while ( *n > 100);

    srand(time(0));
    //генерируем массив
    for ( int i = 0; i < *n; i++)
        a[i] = rand() % 100;


}

//вывод массива
void print_m ( int a[], int n)
{
    cout << "a:";
    for ( int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;

}
int max_(int a[], int n)
{
    //находим значение наибольших элементов массива
    int M = a[0];
    for ( int i = 0; i < n; i++ )
    {
        if ( a[i] >= M)
            M = a[i];
    }
    cout << "max: " << M << endl;
    return M;

}

void double_max(int a[], int n, int b[], int M)
{
   //дублируем их
    int k=0, i;
    for ( i = 0; i < n; i++ )
    {
        if ( a[i] == M)
            b[k++] = a[i];
        b[k++] = a[i];
    }
    //вывод результата
    cout << "b:";
    for ( i = 0; i < k; i++)
      cout << setw(4) << b[i];

}


int main()
{
    int a[100], b[100];
    int n, M;

    input_m(a, &n);
    print_m(a, n);

    M = max_(a, n);
    double_max(a, n, b, M);
}
