#include <iostream>

using namespace std;

int main()
{
    int  n, i;
    double s, x;
    double p, d, k;
    do
    {
        cout << "input integer n > 0" << endl << "n = ";
        cin >> n;
    }
    while (n <= 0);

    cout << endl;
    cin >>x;

    s = 0.0;
    k = 1.0;
    p = 1.0;
    for (i=1; i<=n; i++)
        {
            d = 2 * x;
            p = (-1) * p * d * d;
            k = k * ( 2*i - 1) * (2*i);
            cout<< d<<"  "<<p <<"  "<<k<<"  ";
            p = p / k;
            s = s + p;
            cout<<p<<"  "<<s<<endl;
        }
}
