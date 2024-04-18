/* Рудович Александра
число букв в имени 10
остаток от деления на 8 - номер задания - 2
в массив закинуть элем согласно условию
Все большие первого кратного 3 элемента и <= второго элемента
 */

#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    int a[100], b[100];
    int n, i, x1, x2, p=0, t=0, k=0;
    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> n;
    }
    while ( n > 100);
    srand(time(0));
    for ( i = 0; i < n; i++)
    {
        a[i] = rand() % 100+1;
        cout << a[i] << "  ";
        //cin>>a[i];
    }

    cout << endl;
    x1 = -1;
    for ( i = 0; i < n; i++ )
    {
        if ( a[i] % 3 == 0)
            {
                x1 = a[i];
                p = i;
            }
        if (x1 !=  -1)
            break;

    }
    cout << x1<<endl;

    x2 = a[1];
    cout<< x2<<endl;
    if(x1>=x2)
        cout << "x1>x2, there are not such numbers (<=x2 and >x1)";
    for ( i = 0; i < n; i++)
        if( a[i]<=x2 && a[i]>x1)
            b[k++] = a[i];

    for ( i = 0; i<k; i++)
        cout << b[i] << "  ";
}
