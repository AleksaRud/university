/* перевод числа из одной сс в другую

*/

#include <iostream>

using namespace std;

int main() {

   long long int a, b, n,s,k;
   cout << "input a" << endl;
   cin>>a;
   cout<<"input n 2<=n<=9"<<endl;
   cin>>n;
   b=1;
   while(a>0)
   {
       b=b*10+a%n;
       a=a/n;
   }
   cout<<b<<endl;
   s=0;
   k=b;
   while(k>0){
       s=s*10+k%10;
       k=k/10;
   }
   s=s/10;
   cout<<s<<endl;


}
