#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k, m, b;

    k = 1; b = n;

    while ( b > 0 )
    {
        b = b/10;
        k = k*10;
    }
    m = n % (k/10);
    cout << m;

}
