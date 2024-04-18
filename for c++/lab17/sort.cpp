#include <iostream>
using namespace std;
void input_parameters(int *n)
{
    do
    {
        cout << "input n<=100" << endl;
        cout << "n = ";
        cin >> *n;
    }
    while ( *n > 100);
}

int* input_mass(int* a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    return(a);
}
void print_mass(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
}

void sort_1(int* a, int n)
{
    int j, i, p, k, M;
    for ( j = n; j > 0; j--)
    {
        M = a[n-j];
        p = 0;
        for ( i = n-j; i < n; i++ )
        {
            if ( a[i] >= M)
            {
                M = a[i];
                p = i;
            }
        }
        k = a[n-j];
        a[n-j] = a[p];
        a[p] = k;
    }
}

void sort_2(int* a, int n)
{
    int j, i, p, t, k, M, m, N = n;
    for ( j = N; j > 0; j--, N--)
    {
        M = a[N-j];
        p = 0;
        for ( i = N-j; i < n; i++ )
        {
            if ( a[i] >= M)
            {
                M = a[i];
                p = i;
            }
        }
        m = a[N-j];
        for ( i = N-j; i < N; i++ )
        {
            if ( a[i] <= m)
            {
                m = a[i];
                t = i;
            }
        }
        k = a[N-j];
        a[N-j] = a[p];
        a[p] = k;

        k = a[N-1];
        a[N-1] = a[t];
        a[t] = k;
    }
}
void print_res(int* a, int n)
{
    for ( int i = 0; i < n; i++)
      cout << a[i] << "  ";
}
