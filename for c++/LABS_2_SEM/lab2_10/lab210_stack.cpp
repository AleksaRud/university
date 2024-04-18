/*Рудович Александра, 1 курс, пи, фск
    лаб 2 10

    Написать программу, которая подсчитывает количество элементов стека, у которых равные "соседи", используя .  стек-шаблон
*/

#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;
template<class T>
void Print(stack<T> ts)
{
    stack<T> ts1;
    while(!ts.empty())
    {
        T a = ts.top();
        ts.pop();
        cout<<a<<" ";
        ts1.push(a);
    }
    while(!ts1.empty())
    {
        T a = ts1.top();
        ts1.pop();
        ts.push(a);
    }
}
int main()
{
    stack<int> S;
    for(int i=0; i<15; i++)
        S.push(rand()%20+1);
    Print(S);

    int K=0;
    while(!S.empty())
    {
        int N = S.top();
        S.pop();
        if(S.empty()) break;
        S.pop();
        int P = S.top();
        cout<<N<<"  "<<P<<endl;
        if(N==P) K+=1;
        cout<<K<<endl;
    }

    cout<<"K = "<< K << endl;
}
