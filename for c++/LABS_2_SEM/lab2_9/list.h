#define __LIST_H__
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
struct item
{	T data;
    item* next;
    item* prev;
};

template<class T>
class List
{
    item<T>* head;
    item<T>* tail;
public:
    List();
    ~List();
    bool empty();
    T pop_back();
    T pop_front();
    void push_front(T dat);
    void push_back(T dat);
    void insert(T dat, int pos);
    T remove(int pos);
    void print();
};
template<class T>
List<T>::List()
{
    head = 0;
    tail = 0;
}
template<class T>
List<T>::~List()
{
    while(!empty())
        pop_front();
}
template<class T>
bool List<T>::empty()
{
    return head == 0 ? true : false;
}
template<class T>
void List<T>::push_front(T dat)
{
    item<T>* tmp = new item<T>;
	tmp->data = dat;
	tmp->next = head;
	tmp->prev = 0;
 	if(head)
		head-> prev = tmp;
	else
		tail = tmp;
	head = tmp;
}
template<class T>
void List<T>::push_back(T dat)
{
    item<T>* tmp = new item<T>;
	tmp->data = dat;
	tmp->next = 0;
	tmp->prev = tail;
 	if(head)
		tail-> next = tmp;
	else
		head = tmp;
	tail = tmp;
}
template<class T>
void List<T>::insert(T dat, int pos)
{   item<T>* tmp = new item<T>;
	tmp->data = dat;
	item<T>* ptmp = head;
	if(ptmp == 0)
	{
		tmp->next = 0;
		tmp->prev = 0;
		head = tmp;
		tail = tmp;
		return;
    }
    int i = 0;
	while ((i<pos)&&(ptmp->next))
	{   ptmp = ptmp->next;
		i++;
	}
    if  (ptmp->next == 0)
		{      ptmp->next = tmp;
			tmp->prev = ptmp;
			tmp->next = 0;
			tail = tmp;
			return;
		}
    ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}
template<class T>
T List<T>::remove (int pos)
{
    item<T>* tmp = head;
	for ( int i = 0;  i<pos;  i++)
	{
	    if(tmp  == 0) return 0;
        tmp  = tmp ->next;
    }
    tmp->next->prev = tmp->prev;
	if(tmp ->prev != 0)
		 tmp->prev->next = tmp->next;
	T res = tmp->data;
	delete tmp;
	return res;
}

template<class T>
T List<T>::pop_front()
{   if (head)
    {
        T res = head->data;
        item<T>* tmp = head;
        if ( head->next)
            head->next->prev = 0;
        else
            tail = 0;
		head = head->next;
		delete tmp;
		return res;
    }
    else
        return 0;
}
template<class T>
T List<T>::pop_back()
{   if (tail)
    {
        T res = tail->data;
        item<T>* tmp = tail;
        if ( tail->next)
            tail->prev->next = 0;
        else
            head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
    }
    else
        return 0;
}
template<class T>
void List<T>::print()
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
