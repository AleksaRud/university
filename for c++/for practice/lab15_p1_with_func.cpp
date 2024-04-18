/* Рудович Александра, 1 курс, пи, фск, лаб15
11.	Найти номера строк заданной матрицы A=(aij) ,  i=1..n, j=1..m, n,m<=100, в которых есть наибольший и наименьший  элементы.

*/


#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

//генерируем массив(случайные значения)
void input_mtr ( int a[100][100], int *n, int *m)
{
    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> *n;
    }
    while ( *n > 100);

    do
    {
        cout << "input n<=100" << endl;
        cout << "m = ";
        cin >> *m;
    }
    while ( *m > 100);

    srand(time(0));

    for ( int i = 0; i < *n; i++)
        for ( int j = 0; j < *m; j++)
            a[i][j] = rand() % 10;
}

//вывод матрицы
void print_mtr ( int a[100][100], int n, int m)
{

    for ( int i = 0; i < n; i++)
        {for ( int j = 0; j < m; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
        }
}
//находим значение наибольших элементов массива
int max_el ( int a[100][100], int n, int m, int max_)
{
    max_ = a[0][0];
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++)
            if ( a[i][j] >= max_)
                max_ = a[i][j];
    return max_;
}

//находим значение наименьших элементов массива
int min_el ( int a[100][100], int n, int m, int min_)
{
    min_ = a[0][0];
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++)
            if ( a[i][j] <= min_)
                min_ = a[i][j];
    return min_;
}

void min_max_ln ( int n_min[], int n_max[], int n)
{
    int g = 0;
    cout << "min and max are in this line(lines): ";
    for ( int i = 0; i < n; i++)
        if ( n_min[i] == n_max[i] && n_min[i] > 0)
        {
            g++;
            cout << i << " ";
        }

    if ( g == 0 )
        cout << "there are not such lines";

}

//выводим номера строк с min значением(если в строке таких значений несколько, то номер выводим один раз)
int *min_ln(int a[100][100], int n_min[], int n, int m, int min_)
{
    int c_min = 0;
    int i;
    n_min = new int [n];
    for ( i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++)
        {
            if ( a[i][j] == min_)
            {

                n_min[i] = 1;
                cout << i << " ";
                c_min++;
                if (c_min > 0)
                    break;
            }
            else
                n_min[i] = 0;

        }
    return n_min;
}

//выводим номера строк с max значением(если в строке таких значений несколько, то номер выводим один раз)
int *max_ln(int a[100][100], int n_max[], int n, int m, int max_)
{
    int c_max = 0;
    int i;
    n_max = new int [n];
    for ( i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++)
        {
            if ( a[i][j] == max_)
            {

                n_max[i] = 1;
                cout << i << " ";
                c_max++;
                if (c_max > 0)
                    break;
            }
            else
                n_max[i] = 0;

        }
    return n_max;
}

int main()
{
    int a[100][100];
    int *n_max=0, *n_min=0;
    int n, m, max_, min_, s;

    input_mtr(a, &n, &m);

    cout << "Do you want to print matrix?(0 - no, 1 - yes)" << endl;
    do
    {
        cin >> s;
    }
    while(s!=0 && s!=1);
    if( s == 1)
        print_mtr(a, n, m);

    max_ = a[0][0];
    max_ = max_el(a, n, m, max_);
    min_ = a[0][0];
    min_ = min_el(a, n, m, min_);
    cout << "max: " << max_ << endl;
    cout << "min: " << min_ << endl;

    cout << "max is in this lines: ";
    n_max = max_ln(a, n_max, n, m, max_);
    cout << endl;

    cout << "min is in this lines: ";
    n_min = min_ln(a, n_min, n, m, min_);
    cout << endl;

    min_max_ln(n_min, n_max, n);

    return 0;
}
