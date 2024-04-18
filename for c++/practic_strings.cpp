/* Рудович Александра */

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
    char* a = "abc*123*45*67*kl";
    char *p1, *p2, c = '*';
    int n, m;
    p1 = strchr(a, c);
    p2 = strrchr(a, c);
    n = p1 - a;
    m = p2 - a;
    for(int i = n+1; i < m; i++)
        cout << a[i];


}
