//Рудович Александра

#include <iostream>

#include <iomanip>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main()
{

    stack<int> S;
    queue<int> Q;
    list<int> L;

//1) закидываем в стэк
    for(int i=0; i<10; i++)
        S.push(rand()%100);


//2) закидываем в список + вывод стэка
cout<<"stack: " << endl;

    while(!S.empty())
    {
        int x = S.top();
        L.push_front(x);
        cout<<x<< setw(3);
        S.pop();
    }
    cout<<endl;

//3) дублируем первый элемент + вывод списка
cout<<"list: "<<endl;
    int x = L.front();
    L.push_front(x);
    int k = L.size();
    for(int i = 0; i<k; i++)
    {
        x = L.front();
        L.push_back(x);
        cout<< x<<setw(3);
        L.pop_front();
    }
    cout<<endl;

//4) убираем повторы первого элемента и сортируем
    x = L.front();
    L.remove(x);
    L.push_front(x);
    L.sort();

//вывод отсортированного списка
cout<<"list: "<<endl;
    k = L.size();
    for(int i = 0; i<k; i++)
    {
        x = L.front();
        L.push_back(x);
        cout<< x<<setw(3);
        L.pop_front();
    }
    cout<<endl;

//5) закидываем в очерндь
    while(!L.empty())
    {
        x = L.front();
        Q.push(x);
        L.pop_front();
    }

//6) вывод очереди
    cout<<"queue:"<<endl;
    while(!Q.empty())
    {
        cout<<Q.front()<<setw(3);
        Q.pop();
    }

    cout<<endl;
}
