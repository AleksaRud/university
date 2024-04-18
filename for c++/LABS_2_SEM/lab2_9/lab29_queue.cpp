/*Рудович Александра, 1 курс, пи, фск
    лаб 29
    2.	Класс очередь шаблон
    5.1	Задан текстовый файл Input.txt, в котором есть некоторые числа.
    Создать очередь, в которой будут числа- палиндромы.
    Построить новую очередь, продублировав четные числа.
    Результат записать в текстовый  файл result.txt. " Используя  очередь-шаблон.


    появляется проблема: если пытаться занести несколько чисел, трёхзначных и тд, в очередь, числа почему-то склеиваются
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "queue.h"
using namespace std;

bool isPalindrom(int a)
{
    int a_= a, a1=0;
    while(a_>0)
    {
        a1 = a1*10 + a_%10;
        a_=a_/10;
    }
    return (a==a1);
}
int main()
{
    Queue<long int> q1, q2, q3;
    string str;
    ifstream in("Input.txt");
    if (in.is_open())
    {
        while (getline(in, str))
        {
            cout << str  <<endl;
        }
    }
    in.close();
    string s = "";
    int n;
    for(int i =0; i< str.length(); i++)
    {
        if(str[i]==' ') continue;
        s=s + str[i];

        if(str[i+1]==' ' || (i+1)==str.length())
        {
            n = stoi(s);
            q1.push(n);
            s.clear();
            continue;
        }
    }
    cout<<endl;
    q1.print();
    while(!q1.empty())
    {
        int a = q1.pop();
        if(isPalindrom(a)) q2.push(a);
    }
    q2.print();
    while(!q2.empty())
    {
        int a = q2.pop();
        q3.push(a);
        if(a%2==0)
            q3.push(a);
    }
    q3.print();
    str.clear();
    str = "";
    while(!q3.empty())
    {
        int a = q3.pop();
        str= str + to_string(a) + ' ';
    }

    ofstream out;
    out.open("Result.txt");
    if (out.is_open())
    {
        out << str << endl;
    }
    out.close();
    cout << "End of program" << endl;
}
