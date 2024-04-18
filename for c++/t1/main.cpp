#include <iostream>

using namespace std;

int main()
{
   // cout << "hi";
   int a,b,n,k2;
   cout<<"input a"<<endl;
   cin>>a;
   b=1;
   k2=-1;
   while(b<a)
   {
       b=b*2;
       k2++;
   }
   n=k2+1;
   cout<<k2<<"    "<<n;
}
