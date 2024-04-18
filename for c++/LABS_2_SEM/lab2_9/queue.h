#define __QUEUE_H__
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
struct item
{	T data;
    item* next;
};

template<class T>
class Queue
{
    item<T>* head;
    item<T>* tail;
public:
    Queue();
    ~Queue();
    bool empty();
    T peek();
    T pop();
    void push(T data);
    void print();
};
template<class T>
Queue<T>::Queue()
{
    head = 0;
    tail = 0;
}
template<class T>
Queue<T>::~Queue()
{
    while(!empty())
        pop();
}
template<class T>
bool Queue<T>::empty()
{
    return head == 0 ? true : false;
}
template<class T>
T Queue<T>::peek()
{
    if 	(! empty() )
        return head->data;
    else return 0;
}
template<class T>
void Queue<T>::push(T data)
{
    item<T>* tmp = new item<T>;
    tmp->data=data;
    tmp->next = 0;
    if(head == 0)
    {
        head = tmp;
        tail = head;
        return;
    }
    tail->next = tmp;
    tail = tmp;
    tail->next=0;
}
template<class T>
T Queue<T>::pop()
{
    if ( !empty ( ) )
    {
        item<T>* tmp = head;
        T tdata = head->data;
        head = head->next;
        delete tmp;
        return tdata;
    }
    else return 0;
}
template<class T>
void Queue<T>::print()
{
    item<T>* temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<setw(3);
        temp=temp->next;
    }
    cout<<endl;
}
