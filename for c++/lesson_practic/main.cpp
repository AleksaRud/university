#include <iostream>

using namespace std;


int main()
{
    int a[10], b[20];
    int n, k = 0, i;
    do
    {
        cout << "input n<=10" << endl;
        cin >> n;
    }
    while ( n > 10);

    for ( i = 0; i < n; i++)

        cin >> a[i];

//удаляет чётные числа
    for ( i = 0; i < n; i++ )
    {
        if ( a[i] % 2 == 1)
           {
              b[k] = a[i];
              k++;
           }
    }

    for ( i = 0; i < k; i++)
      cout << b[i] << "  ";

      /*
      новый массив с удвоенными чётными числами
      for ( i = 0; i < n; i++ )
    {
        if ( a[i] % 2 == 0)
            b[k++] = a[i];
            //k++;

        b[k++] = a[i];
        //k++;
    }

    for ( i = 0; i < k; i++)
      cout << b[i] << "  ";
      */
}
