#define __STACK_H__
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
struct item
{
    T data;
    item* prev;
};
template<class T>
class Stack
{
    item<T>* head;
public:
    Stack();
    ~Stack();
    void push(T dat);
    void pop();
    T top();
    bool empty();
    void print();
};
template<class T>
Stack<T>::Stack()
{
    this->head=0;
}
template<class T>
Stack<T>::~Stack()
{
    while(!empty())
        pop();
}
template<class T>
void Stack<T>::push(T dat)
{
    item<T>* tmp = new item<T>;
    tmp->data=dat;
    tmp->prev=head;
    head=tmp;
}
template<class T>
void Stack<T>::pop()
{
    if(head==0)
    {
        cout<<"Stack is empty";
        return;
    }
    item<T>* old = head;
    head = head->prev;
    delete old;
}
template<class T>
T Stack<T>::top()
{
    if(head==0)
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    T res = head->data;
    return res;
}
template<class T>
bool Stack<T>::empty()
{
    if(head==0) return 1;
    return 0;
}
template<class T>
void Stack<T>::print()
{
    item<T>* temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<setw(3);
        temp=temp->prev;
    }
    cout<<endl;
}
