/*Рудович Александра

положить на лекцию 27

список, стек, дек, вектор

написать шаблон Т функцию, которая выводит элементы некоторого шаблона
void show (string s, T объект)
{   выводит значение переменной строки s (что выводится, список стек и тд);
    объявлен итератор для шаблона контейнера;
    цикл for, который выводит значения по итератору
}

функция предикат, логический тип true - число чётное, false - нечётное
bool chet(int a)

stack<int> S;
deque<int> D;
list<int> L;
vector<int> V;

0) инициализация контейнера
1) вывод любого контейнера
2) сортировка любого контейнера по возрастанию (проверяем для всех методов) + вывод
3) сортировка по убыванию + вывод
4) считаем количество чисел, равных заданному n
5) удаляем все элементы, равные n + вывод
6) удаляем дубликаты (либо вывод, что нету у данного контейнера такого метода)
7) переставить чётные в начало
8) удалить одинаковые соседи (смотрим по парам)
9) частичная сортировка (от какого-то до какого-то элемента)
10) слияние двух контейнеров
11) перевернуть контейнер

кроме заданных функций в начале for не использовать
если метода нету - написать, что его нету
*/

#include <iostream>

#include <iomanip>
#include <stack>
#include <deque>
#include <list>
#include <vector>
using namespace std;

template <typename T> void show(string str, T obj)
{
    cout<< str<<endl;
    typename T::iterator it;
    for(it = obj.begin(); it!=obj.end(); it++)
        cout<< setw(5)<< *it ;
    cout<<endl;
}

bool chet(int a)
{
    return a%2 == 0;
}

int main()
{
//0) инициализация контейнера
    cout<<setw(10)<<"0"<<endl;
    cout<<endl;
    stack<int> S, S2;
    deque<int> D, D2;
    list<int> L, L2;
    vector<int> V(10), V2(10);

    for(int i=0; i<10; i++)
    {
        V[i] = rand()%100;
        D.push_back(rand()%100);
        L.push_back(rand()%100);
        S.push(rand()%100);
        V2[i] = rand()%100;
        D2.push_back(rand()%100);
        L2.push_back(rand()%100);
        S2.push(rand()%100);
    }

//1) вывод любого контейнера
    cout<<setw(10)<<"1"<<endl;
    cout<<endl;
    show("Vector", V);
    show("Deque", D);
    show("List", L);
    cout<< "Stack has no iterator" << endl;
    cout<<endl;

//2) сортировка любого контейнера по возрастанию (проверяем для всех методов) + вывод
    cout<<setw(10)<<"2"<<endl;
    cout<<endl;
    L.sort();
    show("List", L);
    cout<< "Stack has no sorting function" << endl;
    cout<< "Deque has no sorting function" << endl;
    cout<< "Vector has no sorting function" << endl;
    cout<<endl;

//3) сортировка по убыванию + вывод
    cout<<setw(10)<<"3"<<endl;
    cout<<endl;
    L.sort();
    L.reverse(); // или L.sort(greater<int>);

    show("List", L);
    cout<< "Stack has no sorting function" << endl;
    cout<< "Deque has no sorting function" << endl;
    cout<< "Vector has no sorting function" << endl;
    cout<<endl;

//4) считаем количество чисел, равных заданному n
    cout<<setw(10)<<"4"<<endl;
    cout<<endl;
    int n;
    cout<<"Input n:  ";
    cin>>n;
    int kol_el=L.size();
    L.remove(n);
    kol_el -= L.size();
    cout<< "Number of elements =n in list:   " << kol_el<<endl;
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//5) удаляем все элементы, равные n + вывод
    cout<<setw(10)<<"5"<<endl;
    cout<<endl;
    L.remove(n);
    show("List", L);
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//6)удаляем дубликаты (либо вывод, что нету у данного контейнера такого метода)
    cout<<setw(10)<<"6"<<endl;
    cout<<endl;
    cout<< "List has no such method" << endl;
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//7)переставить чётные в начало
    cout<<setw(10)<<"7"<<endl;
    cout<<endl;
    cout<< "List has no such method" << endl;
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//8) удалить одинаковые соседи (смотрим по парам)
    cout<<setw(10)<<"8"<<endl;
    cout<<endl;
    L.unique();
    show("List", L);
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//9) частичная сортировка (от какого-то до какого-то элемента)
    cout<<setw(10)<<"9"<<endl;
    cout<<endl;
    L.sort();

    show("List", L);
    cout<< "Stack has no sorting function" << endl;
    cout<< "Deque has no sorting function" << endl;
    cout<< "Vector has no sorting function" << endl;
    cout<<endl;

//10) слияние двух контейнеров
    cout<<setw(10)<<"10"<<endl;
    cout<<endl;
    L.merge(L2);
    show("List", L);
    cout<< "Stack has no such method" << endl;
    cout<< "Deque has no such method" << endl;
    cout<< "Vector has no such method" << endl;
    cout<<endl;

//11) перевернуть контейнер
    cout<<setw(10)<<"11"<<endl;
    cout<<endl;
    L.reverse();
    show("List", L);
    cout<< "Stack has no sorting function" << endl;
    cout<< "Deque has no sorting function" << endl;
    cout<< "Vector has no sorting function" << endl;
    cout<<endl;
}
