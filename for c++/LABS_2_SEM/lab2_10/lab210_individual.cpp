/*Рудович Александра, 1 курс, пи, фск
    лаб 29
    Вариант 10
    Автоматизированная информационная система на железнодорожном вокзале содержит сведения об отправлении поездов дальнего следования.
    Для каждого поезда указывается:
    - номер поезда;
    - станция назначения;
    - время отправления.
    Данные в информационной системе организованы в виде линейного списка.
    Программа должна обеспечивать:
    - первоначальный ввод данных в информационную систему и формирование линейного списка:
    - вывод всего списка в консоль;
    - ввод номера поезда и вывод всех данных об этом поезде;
    - ввод названия станции назначения и вывод данных обо всех поездах, следующих до этой станции.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
using namespace std;
struct info
{
    int train_num;
    string station_name;
    pair <int, int> time_hh_mm;
};

class Trains
{
    list<info> ltr;
    int lsize;
public:
    Trains()
    {
        lsize = 0;
    }
    Trains(info Ttr)
    {
        ltr.push_back(Ttr);
        lsize++;
    }
    Trains(Trains& Tr)
    {
        while(!Tr.ltr.empty())
        {
            info a = Tr.ltr.front();
            Tr.ltr.pop_front();
            ltr.push_back(a);
        }
        lsize=Tr.lsize;
    }
    void Add(info Ttr)
    {
        ltr.push_back(Ttr);
        lsize++;
    }
    void Print()
    {
        cout<<setw(5)<<setfill(' ')<< "Number" << setw(10)<<"Station"<<setw(10)<<"Time"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info a = ltr.front();
            ltr.pop_front();
            ltr.push_back(a);
            cout<<setw(5)<<setfill(' ')<<a.train_num<<setw(10)<<a.station_name<<setw(5)<<" ";
            cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
        }
    }
    void Find_info(int num)
    {
        cout<<setw(5)<<setfill(' ')<< "Number" << setw(10)<<"Station"<<setw(10)<<"Time"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info a = ltr.front();
            if(a.train_num!=num)
            {
                ltr.pop_front();
                ltr.push_back(a);
            }
            else
            {
                cout<<setw(5)<<setfill(' ')<<a.train_num<<setw(10)<<a.station_name<<setw(5)<<" ";
                cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
                return;
            }
        }
        cout<<"There are no train with this number"<<endl;
    }
    void Find_station(string name)
    {
        cout<<setfill(' ')<< setw(5)<<"Station"<<setw(10)<< "Number" <<setw(10)<<"Time"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info a = ltr.front();
            ltr.pop_front();
            ltr.push_back(a);
            if(a.station_name==name)
            {
                cout<<setw(5)<<setfill(' ')<<a.station_name<<setw(10)<<a.train_num<<setw(5)<<" ";
                cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
            }
        }
        cout<<"There are no train to this station"<<endl;
    }
};

int main()
{
    info t[4];
    t[0].train_num = 123; t[0].station_name = "Minsk"; t[0].time_hh_mm.first= 12; t[0].time_hh_mm.second = 34;
    t[1].train_num = 456; t[1].station_name = "Moskov"; t[1].time_hh_mm.first= 8; t[1].time_hh_mm.second = 0;
    t[2].train_num = 988; t[2].station_name = "Brest"; t[2].time_hh_mm.first= 10; t[2].time_hh_mm.second = 30;
    t[3].train_num = 629; t[3].station_name = "Minsk"; t[3].time_hh_mm.first= 15; t[3].time_hh_mm.second = 18;
    Trains LIST;
    for(int i=0; i<4; i++)
        LIST.Add(t[i]);
    LIST.Print();
    LIST.Find_info(456);
    LIST.Find_station("Minsk");
}
