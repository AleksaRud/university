/*Рудович Александра, 1 курс, пи, фск
11.	Строка состоит из слов. Переставить в ней слова, состоящие только из букв латиницы,
 так, чтобы они были упорядочены по алфавиту. При этом другие слова должны оставаться на месте.
 Слова в исходной строке разделяются некоторым множеством разделителей.
 Слова в новой строке должны разделяться ровно одним пробелом.
 */




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
bool isFirstLessSecond(string s1, string s2)
{
    int min_len = (s1.size() > s2.size()) ? s2.size() : s1.size();
    for(int i = 0; i < min_len; i++)
    {
        if(s1[i] > s2[i])
            return false;
        if(s1[i] < s2[i])
            return true;
    }
    return(s1.size() == min_len);

}
void swapWords(string &s1, string &s2)
{
    string temp;
    temp = s1;
    s1.clear();
    s1 = s2;
    s2.clear();
    s2 = temp;
}

int main()
{
    string str, space = " ";

    cout<< "enter string:\n" ;
    getline(cin, str);

    for(int i=0; i<str.size(); i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='!'||str[i]=='?'||str[i]==';')
            str[i] = ' ';

    if (str[0] != ' ') str.insert(0, space);


    int m=0;
    //количество слов
    for(int i=1; i<str.size(); i++)
    {
        if(str[i]==' ') continue;
        if(str[i-1]== ' ') m++;
    }
    cout <<"number of words = " << m << endl;

    string str_[m];

    for(int i=0,k=0; i<str.size(); )
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        int word_len=1;
        int j;
        for(j=i+1; j<str.size() && str[j]!=' '; j++)
        {
            word_len++;
        }

        string s(str, i, word_len);
        str_[k] = s;
        s.clear();
        i = j;
        k++;
    }

    bool is_full_latine[m];
    for(int i = 0; i < m; i++)
    {
        is_full_latine[i] = true;
        for(int j = 0; j < str_[i].size(); j++)
            is_full_latine[i] = is_full_latine[i] && isLetter(str_[i][j]);

    }

    for(int i=0; i < m; i++)
    {
        if( !is_full_latine[i]) continue;
        for(int j=i+1; j < m; j++)
        {
            if( !is_full_latine[j]) continue;

            if(!isFirstLessSecond(str_[i], str_[j]))
                swapWords(str_[i], str_[j]);
        }
    }

    string str_result = str_[0];

    for(int i = 1; i < m; i++)
        str_result = str_result + " " + str_[i];

    cout <<"RESULT:"<<endl;
    cout << str_result;

}

