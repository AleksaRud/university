/* Рудович Александра */

#include <iostream>

using namespace std;

int sum_zfr( int a, int b)
{
    a = 0;
    while( b > 0 )
   {
       a = a + b % 10;
       b = b / 10;

   }
   return (a);
}

int main()
{
    int n, s, k;
     do
   {
        cout << "input n" << endl;
        cin >> n;
   }
   while ( n <= 0 );


   do
   {
        n = sum_zfr(s, n);
        s = n;

        cout << s << endl;
   }
    while ( s > 9 );


    return 0;
}
