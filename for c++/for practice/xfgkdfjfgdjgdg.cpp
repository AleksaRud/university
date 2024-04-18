/* Задача 6
Найти в матрице A=(aij) ,  i=1..n, j=1..m, n,m<=150, номера строк с наименьшей суммой элементов.
Петкун Диана 1 группа */

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int n, m, i, j, sum, min, numer;
    cout << "Введите количество строк" << endl;
    cin >> n;
    cout << "Введите количество столбцов" << endl;
    cin >> m;
    srand(time(0));
    int** a = new int* [n];
    for (i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
//================================================
    int* sum_el = new int [n];

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
            sum_el[i] += a[i][j];

    min = sum_el[0];
    for (i = 0; i < n; i++ )
    {
        if ( sum_el[i] <= min)
            min = sum_el[i];
    }

    cout << "Номера строк с наименьшей суммой элементов ";
    for ( int i = 0; i < n; i++ )
    {
        if ( sum_el[i] == min)
            cout << i+1 << " ";
    }


//=================================================================
    for (i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;
    delete[] sum_el;

    return 0;
}
