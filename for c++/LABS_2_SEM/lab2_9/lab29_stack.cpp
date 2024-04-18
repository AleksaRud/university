/*Рудович Александра, 1 курс, пи, фск
    лаб 29
    1.	Класс стек_шаблон
    4.2	Написать программу, которая подсчитывает количество элементов стека, у которых равные "соседи", используя .  стек-шаблон
*/

#include <iostream>
#include <iomanip>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> S;
    for(int i=0; i<15; i++)
        S.push(rand()%20+1);
    S.print();
    int K=0;
    while(!S.empty())
    {
        int N = S.top();
        S.pop(); S.pop();
        int P = S.top();
        if(N==P) K++;
    }

    cout<<"K = "<< K << endl;
}
