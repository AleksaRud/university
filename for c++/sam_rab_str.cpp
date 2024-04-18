/* Рудович Александра */

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;

int main()
{
    string str, s(" ");
    int n, k=0, m=0, a;
    cout<< "enter string:\n" ;
    getline(cin, str);
    a = str.size();

    for(int i=0; i<a; i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='!'||str[i]=='?'||str[i]==';')
            {k++; str[i] = ' ';}

    //количество слов
    if (str[a]==' ')
        if (str[0]==' ')
            m = k - 1;
        else m = k;
    else m = k + 1;
    cout <<"number of words = " << m << endl;

    str.insert(0, s);
    str.insert(a+1, s);

    int pos_of_space[k+2], len_of_word[m];

    pos_of_space[0] = str.find(' ');
    for(int i=1; i<k+2; i++)
        pos_of_space[i] = str.find(' ', pos_of_space[i-1]+1);

    for(int i=0; i<m; i++)
        len_of_word[i] = pos_of_space[i+1] - pos_of_space[i] -1;

    int M= len_of_word[0];
    for(int i = 0; i<m; i++)
        if(M<len_of_word[i])
            {
                M = len_of_word[i];
                n=i;
            }


    string s1(str, 0, pos_of_space[n]);
    string s2(str, pos_of_space[n], M+1);
    string s3(str, pos_of_space[n+1], pos_of_space[k+1]);
    string str_;
    str_ = s2 + s1 + s3;
    string S(str_, 1, a);
    cout<<S;
}
