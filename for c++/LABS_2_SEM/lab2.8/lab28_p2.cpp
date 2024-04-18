/*Рудович Александра, 1 курс, пи, фск
лаб 2.8

Вариант 11
К созданному базовому классу Bank добавить:
    -статическое поле Bank *first;
    -поле Bank *next.
В состав класса также входят следующие методы:
    -метод просмотра списка;
    -метод удаления списка.
Создать производный класс Bank1, который содержит следующие данные:
    -добавление к сумме вклада;
    -надбавка к проценту от добавляемой суммы;
    -переопределенная функция расчета итоговой суммы вклада;
    -переопределенная функция просмотра состояния объектов.


*/

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

class Bank
{
public:
    int sum;
    double per_cent;
    Bank(int s, int p): sum(s), per_cent(p) {};
    static string first;
    string next;
    void show_all()
    {
        cout<<first<<endl;
        cout<<next<<endl;
    }
    void del()
    {
        cout<<"Next is deleted"<<endl;
    }
    virtual double it_sum() = 0;
    virtual void show() = 0;
};
string Bank::first = "First";

class Bank1: protected Bank
{
    int dob_sum;
    double nad_proc;
public:
    Bank1(int s1, double p1, int ds, double np): Bank(s1, p1), dob_sum(ds), nad_proc(np) {};
    virtual double it_sum()
    {
        return (sum+dob_sum)*(1 + per_cent+nad_proc);
    }
    virtual void show()
    {
        cout<< sum <<endl;
        cout<< per_cent <<endl;
        cout<< it_sum() << endl;
    }
};


int main()
{
    Bank1 A(100, 0.1, 20, 0.02);
    double SUM = A.it_sum();
    A.show();
}
