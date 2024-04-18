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
bool isFirstLessSecond(char* s1, char* s2)
{
    int min_len = (strlen(s1) > strlen(s2)) ? strlen(s2) : strlen(s1);
    for(int i = 0; i < min_len; i++)
    {
        if(s1[i] > s2[i])
            return false;
        if(s1[i] < s2[i])
            return true;
    }
    return(strlen(s1) == min_len);

}

void swapWords(char **s1, char **s2)
{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    char str[100];
    char space = ' ';

    cout<< "enter string:\n" ;
    cin.getline(str, 100);


    for(int i=0; i<strlen(str); i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='!'||str[i]=='?'||str[i]==';')
            str[i] = ' ';

    int m=0;
    //количество слов
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]==' ') continue;
        if(i==0)
            m++;
        else
            if(str[i-1]== ' ')
                m++;
    }
    cout <<"number of words = " << m << endl;

    char* str_[m];

    for(int i=0,k=0; i<strlen(str); )
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        int word_len=1;
        int j;
        for(j=i+1; j<strlen(str) && str[j]!=' '; j++)
        {

            word_len++;
        }

        str_[k] = new char[word_len];
        copy(str + i, str + i + word_len, str_[k]);
        str_[k][word_len] = '\0';

        i = j;
        k++;
    }

    bool is_full_latine[m];
    for(int i = 0; i < m; i++)
    {
        is_full_latine[i] = true;
        for(int j = 0; j < strlen(str_[i]); j++)
            is_full_latine[i] = is_full_latine[i] && isLetter(str_[i][j]);

    }

    for(int i=0; i < m; i++)
    {
        if( !is_full_latine[i]) continue;
        for(int j=i+1; j < m; j++)
        {
            if( !is_full_latine[j]) continue;

            if(!isFirstLessSecond(str_[i], str_[j]))
                swapWords(&str_[i], &str_[j]);

        }
    }


    char str_result[100]="";

    strcat(str_result, str_[0]);

    for(int i = 1; i < m; i++)
    {
        strcat(str_result, " ");
        strcat(str_result, str_[i]);
    }

    cout <<"RESULT:"<<endl;
    cout << str_result;

}
