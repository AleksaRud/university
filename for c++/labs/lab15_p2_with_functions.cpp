/* Рудович Александра, 1 курс, пи, фск, лаб15
6.	Найти в матрице A=(aij) ,  i=1..n, j=1..m, n,m<=150, номера строк с наименьшей суммой элементов.
*/


#include <iostream>

using namespace std;

//генерируем массив(случайные значения)
int input_mtr ( int a[150][150], int n, int m)
{
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
            a[i][j] = rand() % 100;
}

//находим значение наименьшей суммы
int min_sum_f ( int sum[150], int k)
{
    int min_sum = sum[0];
    for ( int i = 0; i < k; i++ )
            if ( sum[i] <= min_sum)
                min_sum = sum[i];
    return min_sum;
}

int minsum_ln (int sum[150], int k, int min_sum )
{
    for ( int i = 0; i < k; i++ )
            if ( sum[i] == min_sum )
                cout << i << " ";
}

int main()
{
    int a[150][150], sum[150];
    int n, m, i, j, min_sum, S, k = 0;

    do
    {
        cout << "input n<=150" << endl;
        cout << "n = ";
        cin >> n;
    }
    while ( n > 150);

    do
    {
        cout << "input m<=150" << endl;
        cout << "m = ";
        cin >> m;
    }
    while ( m > 150);

    input_mtr(a, n, m);

    //находим сумму элементов в строках
    for ( i = 0; i < n; i++)
        {
            S = 0;
            for ( j = 0; j < m; j++)
                S += a[i][j];
            sum[k++] = S;
            cout << "in line  " << i << "  sum = " << S << endl;
        }

    min_sum = min_sum_f(sum, k);
    cout << "min sum = " << min_sum << endl;

    //выводим номера строк с min суммой
    cout << "min sum is in this line(lines): ";
    minsum_ln(sum, k, min_sum);

}
