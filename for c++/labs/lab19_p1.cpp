/*Рудович Александра, 1 курс, пи, фск
11.	Строка состоит из слов. Переставить в ней слова, состоящие только из букв латиницы,
 так, чтобы они были упорядочены по алфавиту. При этом другие слова должны оставаться на месте.
 Слова в исходной строке разделяются некоторым множеством разделителей.
 Слова в новой строке должны разделяться ровно одним пробелом. */




#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;

bool isLetter(char c)
{
    if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return true;
    else return false;
}

int main()
{
    string str, s(" ");
    int k=0, m=0, a;
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
    for(int i = 1; i < k+2; i++)
        pos_of_space[i] = str.find(' ', pos_of_space[i-1]+1);

    for(int i = 0; i < m; i++)
        len_of_word[i] = pos_of_space[i+1] - pos_of_space[i] -1;

    int is_a_word[m];
    int n, g = 1;
    for(int i = 0; i < m; i++)
    {
        n = 0;
        for(int j=0; j < len_of_word[i]; j++)
            n+= isLetter(str[g++]);
        g++;
        if (n == len_of_word[i])
            is_a_word[i] = 1;
        else is_a_word[i] = 0;
        cout << is_a_word[i];
    }
    cout<<endl;

    string str2(str);
    string str1;
    for(int i = 0; i < m; i++)
    {
        if(is_a_word[i] == 0)
        {
            string s1(str2, 0, pos_of_space[i]);
            string s2(str2, pos_of_space[i], pos_of_space[i+1]-pos_of_space[i]);
            string s3(str2, pos_of_space[i+1], str2.size() - pos_of_space[i+1]);
            str1 = s1 + s3;
            cout<<s1<<"  "<<s3<<endl;
            cout<<str1<<endl;
            str2.clear();
            s1.clear();
            s2.clear();
            s3.clear();
            str2 = str1;
        }

    }
    cout <<"str2="<< str2<<endl;
    int p;
    for (int j = m; j > 0; j--)
    {
        string alph(str2, pos_of_space[m-j], pos_of_space[m-j+1] - pos_of_space[m-j]);
        p = 0;
        for (int i = m-j; i < m; i++ )
        {
            string s2(str2, pos_of_space[i],  pos_of_space[i+1] - pos_of_space[i]);
            if ( alph.compare(s2) > 0)
            {
                alph.clear();
                alph = s2;
                p = i;
            }
            s2.clear();
        }
        string s1(str2, pos_of_space[m-j], pos_of_space[m-j+1] - pos_of_space[m-j]);
        string s2(str2, pos_of_space[m-j+1], pos_of_space[p] - pos_of_space[m-j+1]);
        string s3(str2, pos_of_space[p+1], str2.size() - pos_of_space[p+1]);
        str2.clear();
        str2 = alph + s2 + s1 + s3;
        s1.clear();
        s2.clear();
        s3.clear();
        alph.clear();
    }
    cout<<"str2="<<str2<<endl;


    /*string s1(str, 0, pos_of_space[n]);
    string s2(str, pos_of_space[n], M+1);
    string s3(str, pos_of_space[n+1], pos_of_space[k+1]);
    string str_;
    str_ = s2 + s1 + s3;
    string S(str_, 1, a);
    cout<<S;*/
}
