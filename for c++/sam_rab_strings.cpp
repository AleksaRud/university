/* Рудович Александра */

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;

int main()
{
    char* str;
    str = new char[10];
    int n, k=0, m=0, a;
    cout<< "enter string:\n" ;
    cin.getline(str, 100);
    a = strlen(str);

    for(int i=0; i<a; i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='!'||str[i]=='?')
            {k++; str[i] = ' ';}

    //количество слов
    if (str[a]==' ')
        if (str[0]==' ')
            m = k - 1;
        else m = k;
    else m = k + 1;
    cout <<"number of words = " << m << endl;

    char* str2;
    str2 = new char[10];
    strcpy(str2, str);
    cout << str2<< endl;
    cout << str<< endl;
    char* x;
    int sz;
    int wl[m];
    int pos[m];

    for(int i=m; i>0; i--)
    {
        x = strrchr(str2, ' ');
        cout<< strlen(str2)<<" "<< endl;
        cout<<"x= " << x<< "   x -str= "<< x - str<<endl;
        sz = strlen(str2)- (x - str);
        cout<<sz<<endl;
        wl[i] = sz;
        pos[i] = x - str;

        strncpy(str2, str2, sz);
        str2[sz] ='\0';
    }

    int Max = wl[0];
    for(int i = 0; i<m; i++)
        if(Max<wl[i])
            {
                Max = wl[i];
                n=i;
            }


    string strk;
    string s1(str, 0, pos[n]);
    string s2(str, pos[n], pos[n+1]);
    string s3(str, pos[n+1], a - pos[n+1]);
    strk = s2 +s1 +s3;
    cout<<strk;
}
