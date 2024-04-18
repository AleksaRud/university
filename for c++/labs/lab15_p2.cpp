/* Рудович Александра, 1 курс, пи, фск, лаб15
6.	Найти в матрице A=(aij) ,  i=1..n, j=1..m, n,m<=150, номера строк с наименьшей суммой элементов.
*/


#include <iostream>

using namespace std;


int main()
{
    int a[150][150], sum[150];
    //int c_max = -1, c_min = -1;
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

    //генерируем массив(случайные значения)
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
            //cout << a[i][j] << "  ";
        }
        //cout << endl;
    }

    //cout << endl;

    //находим сумму элементов в строках
    for ( i = 0; i < n; i++)
        {
            S = 0;
            for ( j = 0; j < m; j++)
                S += a[i][j];
            sum[k++] = S;
            cout << "in line  " << i << "  sum = " << S << endl;
        }


    //находим значение наименьшей суммы
    min_sum = sum[0];
    for ( i = 0; i < k; i++ )
            if ( sum[i] <= min_sum)
                min_sum = sum[i];

    cout << "min sum = " << min_sum << endl;

    //выводим номера строк с min суммой
    cout << "min sum is in this line(lines): ";
    for ( i = 0; i < k; i++ )
            if ( sum[i] == min_sum )
                cout << i << " ";

}
