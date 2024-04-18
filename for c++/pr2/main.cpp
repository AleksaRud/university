#include <iostream>

using namespace std;
//переместить вторую цифру с конца в начало

int main()
{
    int a,b,x;
    cin>>a;
    x=a;
    b=-2;
    while (x>0)
       {
           x=x/10;
           b++;
       }
    x=b;
    b=1;
    while (x>0)
        {
            b=10*b;
            x--;
        }

    b=(a%100-a%10)*b+a/100*10+a%10;
    cout<<b;
}
