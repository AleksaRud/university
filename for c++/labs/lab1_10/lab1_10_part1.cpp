/*Рудович Александра, 1 курс, пи, фск
11. Задан текстовый файл Input.txt, состоящий  из слов.
Разделителями между словами является некоторое множество знаков препинания.
Найти в каждой строке  пары подряд стоящих слов, у которых одинаковое количество прописных букв,
удалить и дописать первое слово из пары в начало строки, второе – в конец строки.
Результат записать в новый файл Output.txt. Упорядочить слова в полученных строках по убыванию длин слов,
результат сортировки записать в файл Out_sort.txt.
 */


#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;


bool isUpLetter(char c)
{
    if('A' <= c && c <= 'Z')
        return true;
    else return false;
}

int numberOfWords(string str)
{
    int m=0;
    for(int i=1; i<str.size(); i++)
    {
        if(str[i]==' ') continue;
        if(str[i-1]== ' ') m++;
    }
    cout <<"number of words = " << m << endl;
    return m;
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

void swapNumbers(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*void throwToStart(string &s1, string &str)
{
    int pos = str.find(s1);
    str.erase(pos, s1.size());
    str = s1 + str;
}

void throwToEnd(string &s1, string &str)
{
    int pos = str.find(s1);
    str.erase(pos, s1.size());
    str = str + s1;
}*/

int main()
{
    string str, space = " ";

    ifstream in("Input.txt");
    if (in.is_open())
    {
        while (getline(in, str))
        {
            cout << str  <<endl;
        }
    }
    in.close();

    for(int i=0; i<str.size(); i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='!'||str[i]=='?'||str[i]==';')
            str[i] = ' ';

    if (str[0] != ' ') str.insert(0, space);

    int n = numberOfWords(str);

    string str_[n];
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

    int num_up_letter[n];
    for(int i = 0; i < n; i++)
    {
        num_up_letter[i] = 0;
        for(int j = 0; j < str_[i].size(); j++)
            num_up_letter[i] += isUpLetter(str_[i][j]);
    }

    int flag[n];
    for (int i=0; i<n-1; i++)
        flag[i] = 0;
    flag[n-1] = 1;

    int i=0;
    while( i<n )
    {
        if(flag[i]==1) break;
        if(num_up_letter[i] == num_up_letter[i+1])
        {
            for(int j = 0; j < i; j++)
            {
                swapWords(str_[j], str_[i]);
                swapNumbers(num_up_letter[j], num_up_letter[i]);
            }


            for(int j = n-1; j > i+1; j--)
            {
                swapWords(str_[j], str_[i+1]);
                swapNumbers(num_up_letter[j], num_up_letter[i+1]);
                swapNumbers(flag[j], flag[i+1]);
            }
        }

        i++;
    }

    string for_output = str_[0];
    for(int i = 1; i < n; i++)
        for_output = for_output + " " + str_[i];

    ofstream out1;
    out1.open("Output.txt");
    if (out1.is_open())
    {
        out1 << for_output << endl;
    }
    out1.close();

    for(int i=0; i < n; i++)
        for(int j=i+1; j < n; j++)
            if( str_[j].size() > str_[i].size())
                swapWords(str_[i], str_[j]);


    string for_out_sort = str_[0];
    for(int i = 1; i < n; i++)
        for_out_sort = for_out_sort + " " + str_[i];

    ofstream out2;
    out2.open("Out_sort.txt");
    if (out2.is_open())
    {
        out2 << for_out_sort << endl;
    }
    out2.close();
    cout << "End of program" << endl;
}
