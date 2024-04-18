/* Рудович Александра, 1 курс, пи, фск, лаб14
11)	Дана последовательность A=(ai), i=1..n, n<=100,  Продублировать все наибольшие  элементы.

*/


#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int a[100], b[100];
    int n, k = 0, i, j, p;

    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> n;
    }
    while ( n > 100);

    //генерируем массив(случайные значения или ввод с клавиатуры)
    for ( i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << "  ";
        //cin >> a[i];
    }

    cout << endl;

    for ( i = 0; i < n; i++ )
    {
        p = 0;
        for (j = 2; j <= sqrt(a[i]); j++)

            if ( a[i] % j == 0 )
                p++;
        if (p)
            b[k++] = a[i];
    }


    //вывод результата
    for ( i = 0; i < k; i++)
      cout << b[i] << "  ";

}
