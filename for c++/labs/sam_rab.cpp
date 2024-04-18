/* Рудович Александра */

#include <iostream>

using namespace std;

int sum_zfr( int b)
{
    int a = 0;
    while( b > 0 )
   {
       a = a + b % 10;
       b = b / 10;

   }
   return (a);
}

int main()
{
    int n;
     do
   {
        cout << "input n" << endl;
        cin >> n;
   }
   while ( n <= 0 );


   do
   {
        n = sum_zfr(n);


        cout << n << endl;
   }
    while ( n > 9 );


    return 0;
}
