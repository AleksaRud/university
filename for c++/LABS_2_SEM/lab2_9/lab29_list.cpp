/*Рудович Александра, 1 курс, пи, фск
    лаб 29

    3.	Класс список шаблон
    6.1	Задача Иосифа.
    Вокруг считающего стоит N человек, из которых выделен первый, а  остальные  занумерованы  по  часовой стрелке числами от 2 до N.
    Считающий,  начиная с кого-то, ведет счет до M. Человек, на котором остановился счет, выходит из круга.
    Счет продолжается со следующего человека и так до тех пор, пока не останется один человек.
    Определить номер оставшегося человека, если известно M и то, что счет начинался с первого человека.
    Результат записать в текстовый  файл.
      Используя .  список-шаблон.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include "list.h"
using namespace std;

int main()
{
    List<int> L;
    int N, M;
    cout<<"Input N  M"<<endl;
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        L.push_back(i);
    L.print();


    int n=N;
    while(n>1)
    {
        for(int i=0; i<M-1; i++)
        {
            int a = L.pop_front();
            L.push_back(a);
        }
        L.pop_front();
        L.print();
        n--;
    }
    int a = L.pop_front();
    string str = to_string(a);
    ofstream out;
    out.open("Result_iosif.txt");
    if (out.is_open())
    {
        out << str << endl;
    }
    out.close();
    cout << "End of program" << endl;
}
