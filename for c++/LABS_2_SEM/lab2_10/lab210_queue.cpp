/*Рудович Александра, 1 курс, пи, фск
    лаб 2 10

    5.1	Задан текстовый файл Input.txt, в котором есть некоторые числа.
    Создать очередь, в которой будут числа- палиндромы.
    Построить новую очередь, продублировав четные числа.
    Результат записать в текстовый  файл result.txt. " Используя  очередь-шаблон.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <queue>
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
template<class T>
void Print(queue<T> tq)
{
    queue<T> tq1;
    while(!tq.empty())
    {
        T a = tq.front();
        tq.pop();
        cout<<a<<" ";
        tq1.push(a);
    }
    while(!tq1.empty())
    {
        T a = tq1.front();
        tq1.pop();
        tq.push(a);
    }
    cout<<endl;
}
int main()
{
    queue<int> q1, q2, q3;
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
    Print(q1);
    while(!q1.empty())
    {
        int a = q1.front();
        q1.pop();
        if(isPalindrom(a)) q2.push(a);
    }
    Print(q2);
    while(!q2.empty())
    {
        int a = q2.front();
        q2.pop();
        q3.push(a);
        if(a%2==0)
            q3.push(a);
    }
    Print(q3);
    str.clear();
    str = "";
    while(!q3.empty())
    {
        int a = q3.front();
        q3.pop();
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
