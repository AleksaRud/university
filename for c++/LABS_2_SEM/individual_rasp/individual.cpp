/*Рудович Александра, 1 курс, пи, фск
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
        cout<<setw(5)<<setfill(' ')<< "Number" << setw(15)<<"Station"<<setw(10)<<"Time"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info a = ltr.front();
            ltr.pop_front();
            ltr.push_back(a);
            cout<<setw(5)<<setfill(' ')<<a.train_num<<setw(15)<<a.station_name<<setw(5)<<" ";
            cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
        }
        cout<<endl;
    }
    void Find_info(int num)
    {
        cout<<setw(5)<<setfill(' ')<< "Number" << setw(15)<<"Station"<<setw(10)<<"Time"<<setw(5)<<endl;
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
                cout<<setw(5)<<setfill(' ')<<a.train_num<<setw(15)<<a.station_name<<setw(5)<<" ";
                cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
                cout<<endl;
                return;
            }
        }
        cout<<"There are no train with this number"<<endl;
    }
    void Find_station(string name)
    {
        int k=0;
        cout<<setfill(' ')<< setw(8)<<"Station"<<setw(10)<< "Number" <<setw(10)<<"Time"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info a = ltr.front();
            ltr.pop_front();
            ltr.push_back(a);
            if(a.station_name==name)
            {
                cout<<setw(8)<<setfill(' ')<<a.station_name<<setw(8)<<a.train_num<<setw(6)<<" ";
                cout<<setw(2) << setfill('0')<<a.time_hh_mm.first<<" : "<<setw(2) << setfill('0')<< a.time_hh_mm.second<<setw(5)<<endl;
                k++;
            }
        }
        if(k==0)
            cout<<"There are no train to this station"<<endl;
        cout<<endl;
    }
};

int main()
{
    string str[30], space = " ";int num;
    ifstream in("Input.txt");
    if (in.is_open())
    {

        while (getline(in, str[num]))
        {

            num++;
        }

    }
    in.close();

    info *t;
    t = new info [num];
    string stn,ssn,stf,sts;
    for(int i =0; i<num; i++)
    {
        int j;
        for(j=0; j<str[i].size();j++)
        {
            if(str[i][j]==' ') break;
            stn+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==' ') break;
            ssn+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==' ') break;
            sts+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==' ') break;
            stf+= str[i][j];
        }
        t[i].train_num = stoi(stn);
        t[i].station_name = ssn;
        t[i].time_hh_mm.first = stoi(stf);
        t[i].time_hh_mm.second = stoi(sts);
        stn.clear();
        ssn.clear();
        stf.clear();
        sts.clear();
    }

    Trains LIST;
    for(int i=0; i<num; i++)
        LIST.Add(t[i]);
    LIST.Print();
    LIST.Find_info(688);
    LIST.Find_station("Minsk");
}
