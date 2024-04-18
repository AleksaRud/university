#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>

using namespace std;
int count()

{

    int static c=0;

   return c++;

}




int main()
{
   int  a=12345, b=0, m[10],s=0,max=0;
   while  (a!=0)
    {   if (a%10>max)    max=a%10;
            m[s++]=a%10;
             a=a/10;
        }
    for (int i=s-1;i>=0;i--)
    {         b=b*10+m[i];
          if (m[i]==max)    b=b*10+m[i];
    }
    cout<<b;
}
