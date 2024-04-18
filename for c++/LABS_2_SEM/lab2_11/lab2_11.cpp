/*Рудович Александра, 1 курс, пи, фск
лаб 2 11
11. Класс Город(условие придумано своё)

    Исходный текстовый файл input.txt содержит строки с информацией об одном городе и состоит из четырёх полей:
    - название города;
    - тип посещаемого места (парк, кафе и т.д.);
    - название посещаемого места (может отсутствовать);
    - посещаемость(тыс. чел./день).
    Допускается ситуация, когда несколько строк файла совпадают (10 одинаковых кафе в одном городе).
    Все поля разделены запятыми, отсутствие названия места обозначается двумя запятыми, стоящими подряд. Необходимо:
    - прочитать содержимое файла в один или несколько контейнеров, наиболее подходящих, на Ваш взгляд;
    - после этого реализовать ответы на следующие запросы:
    1. Посчитать количество различных типов мест в каждом городе.
    2. Для конкретного типа места (вводится пользователем) вывести все города, в которых оно есть, и названия мест.
       Города и названия не должны повторяться.
    3. Определить, сколько типов мест имеют определённое название места(название вводится пользователем).
    4. Вывести информацию о наиболее и наименее посещаемом месте каждого типа.
    Реализацию запросов выполнить через меню. Предусмотреть ситуацию, когда пользователь вводит отсутствующую информацию.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include <set>

using namespace std;
struct info
{
    string town_name;
    string place;
    string place_name;
    int traffic;
};

class Town
{
    list<info> lt;
    int lsize;
    list<string> place_type;
    list<string> town_type;
    list<string> place_name_type;
public:
    Town()
    {
        lsize = 0;
    }
    Town(info tt)
    {
        lt.push_back(tt);
        lsize++;
    }
    Town(Town& t)
    {
        while(!t.lt.empty())
        {
            info a = t.lt.front();
            t.lt.pop_front();
            lt.push_back(a);
        }
        lsize=t.lsize;
    }
    void add(info t)
    {
        lt.push_back(t);
        lsize++;
    }
    void print()
    {
        cout<<setw(10)<< "Town" << setw(15)<<"Place"<<setw(20)<<"Place name"<<setw(15)<<"Traffic"<<setw(5)<<endl;
        for(int i=0; i<lsize; i++)
        {
            info temp = lt.front();
            lt.pop_front();
            lt.push_back(temp);
            cout<<setw(10)<<temp.town_name<<setw(15)<<temp.place<<setw(20)<<temp.place_name<<setw(13)<<temp.traffic<<endl;
        }
        cout<<endl;
    }

    void allTypes()
    {
        set<string> types;
        list<string> t, t1, t2;
        for(int i=0; i<lsize; i++)
        {
            info temp = lt.front();
            lt.pop_front();
            lt.push_back(temp);
            t.push_back(temp.place);
            t1.push_back(temp.town_name);
            t2.push_back(temp.place_name);

        }
        types.insert(t.begin(),t.end());
        cout<<"Types of places:  ";
        for(auto i=types.begin(); i!=types.end();i++)
        {
            cout<<*i<<"   ";
            place_type.push_back(*i);
        }
        cout<<endl;
        types.erase(types.begin(),types.end());
        types.insert(t1.begin(),t1.end());
        cout<<"Towns' names:  ";
        for(auto i=types.begin(); i!=types.end();i++)
        {
            cout<<*i<<"   ";
            town_type.push_back(*i);
        }
        cout<<endl;
        types.erase(types.begin(),types.end());
        types.insert(t2.begin(),t2.end());
        cout<<"Places' names:  ";
        for(auto i=types.begin(); i!=types.end();i++)
        {
            cout<<*i<<"   ";
            place_name_type.push_back(*i);
        }
        cout<<endl;
        t.erase(t.begin());
        t1.erase(t1.begin());
        t2.erase(t2.begin());
        cout<<endl;
    }
//1
    void typesNum()
    {
        allTypes();
        int N =0;
        int* num;
        num = new int[lsize];
        for(auto i=town_type.begin(); i!=town_type.end();i++)
        {
            num[N]=place_type.size();
            for(auto j=place_type.begin(); j!=place_type.end(); j++)
            {
                int b=0;
                for(int k=0; k<lsize; k++)
                {
                    info temp=lt.front();
                    lt.pop_front();
                    lt.push_back(temp);

                    if(temp.town_name==*i)
                    {
                        if(temp.place==*j)
                            b+=1;
                    }
                }
                if(b==0)
                    num[N]--;
            }
            N++;
        }

        cout<<setw(10)<< "Town" << setw(25)<<"Numbers of places"<<endl;
        for(int i=0; i<N; i++)
        {
            string a = town_type.front();
            town_type.pop_front();
            town_type.push_back(a);
            cout<<setw(10)<<a<<setw(15)<<num[i]<<endl;
        }
        cout<<endl;
    }
//2
    void getPlaceTownName()
    {
        allTypes();
        string Place;
        cout<<"Input place type"<<endl;
        cin>>Place;
        bool is_place=false;
        list<string> tn, pln;
        for(auto i=place_type.begin(); i!=place_type.end();i++)
        {
            if(*i == Place)
            {
                for(int j=0; j<lsize; j++)
                {
                    info temp=lt.front();
                    lt.pop_front();
                    lt.push_back(temp);

                    if(temp.place==*i)
                    {
                        tn.push_back(temp.town_name);
                        pln.push_back(temp.place_name);
                    }
                }
                is_place=is_place||true;
            }
            else is_place=is_place||false;
        }
        if(!is_place) throw "There is no such place";
        set<string> set_name;
        set_name.insert(tn.begin(),tn.end());
        cout<<"Towns:"<<endl;
        for(auto i=set_name.begin(); i!=set_name.end();i++)
        {
            cout<<*i<<setw(15);
        }
        cout<<endl;
        set_name.erase(set_name.begin(),set_name.end());
        set_name.insert(pln.begin(),pln.end());
        cout<<"Place's names:"<<endl;
        for(auto i=set_name.begin(); i!=set_name.end();i++)
        {
            cout<<*i<<setw(15);
        }
        cout<<endl;
        set_name.erase(set_name.begin(),set_name.end());
        tn.erase(tn.begin());
        pln.erase(pln.begin());

    }
//3
    void getPlaceNameCount()
    {
        allTypes();
        string Place_Name;
        cout<<"Input name of place"<<endl;
        cin>>Place_Name;
        bool is_name=false;
        list<string> plt;
        for(auto i=place_name_type.begin(); i!=place_name_type.end();i++)
        {
            if(*i == Place_Name)
            {
                for(int j=0; j<lsize; j++)
                {
                    info temp=lt.front();
                    lt.pop_front();
                    lt.push_back(temp);

                    if(temp.place_name==*i)
                    {
                        plt.push_back(temp.place);
                    }
                }
                is_name=is_name||true;
            }
           else is_name=is_name||false;
        }
        if(!is_name) throw "There is no such place with this name";
        set<string> set_name;
        set_name.insert(plt.begin(),plt.end());
        cout<<"Number of places with this name:"<<setw(5)<<set_name.size() <<endl;

        set_name.erase(set_name.begin(),set_name.end());
        plt.erase(plt.begin());
    }
//4
    void getMaxMinTrafficInfo()
    {
        info Max, Min;
        Max = lt.front();
        Min = lt.front();
        for(int i=0; i<lsize; i++)
        {
            info temp = lt.front();
            lt.pop_front();
            lt.push_back(temp);
            if(Max.traffic<temp.traffic)
                Max = temp;
            if(Min.traffic>temp.traffic)
                Min = temp;
        }
        cout<<"Information about place with max traffic"<<endl;
        cout<<setw(10)<<Max.town_name<<setw(10)<<Max.place<<setw(20)<<Max.place_name<<setw(10)<<Max.traffic<<endl;
        cout<<endl;
        cout<<"Information about place with min traffic"<<endl;
        cout<<setw(10)<<Min.town_name<<setw(10)<<Min.place<<setw(20)<<Min.place_name<<setw(10)<<Min.traffic<<endl;
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
    string stn,spl,spln,spn;
    for(int i =0; i<num; i++)
    {
        int j;
        for(j=0; j<str[i].size();j++)
        {
            if(str[i][j]==',') break;
            stn+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==',') break;
            spl+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==',') break;
            spln+= str[i][j];
        }
        for(j= j+1; j<str[i].size();j++)
        {
            if(str[i][j]==',') break;
            spn+= str[i][j];
        }
        t[i].town_name = stn;
        t[i].place = spl;
        if(spln=="") spln="*no_name*";
        t[i].place_name = spln;
        t[i].traffic = stoi(spn);
        stn.clear();
        spl.clear();
        spln.clear();
        spn.clear();
    }

    Town LIST;
    for(int i=0; i<num; i++)
        LIST.add(t[i]);


    cout<<setw(35)<<"Menu"<<endl;
    cout<<endl;
    cout<<"0. Show all info"<<endl;
    cout<<"1. Count different types of places in each town"<<endl;
    cout<<"2. For certain type of place show towns and place's names"<<endl;
    cout<<"3. For certain name of places count different types of places with this name"<<endl;
    cout<<"4. Show all information about places with max and min traffic"<<endl;
    cout<<endl;
    string choce;
    do
    {
        cout<<"Choose 0, 1, 2, 3 or 4. To close, input end"<<endl;
        cin>>choce;
        cout<<endl;
        if(choce=="0")
            LIST.print();
        if(choce=="1")
            LIST.typesNum();
        if(choce=="2")
            try
            {
                LIST.getPlaceTownName();
            }
            catch(const char* s)
            {
                cout<<s<<endl;
                cout<<endl;
            }
        if(choce=="3")
            try
            {
                LIST.getPlaceNameCount();
            }
            catch(const char* s)
            {
                cout<<s<<endl;
                cout<<endl;
            }
        if(choce=="4")
            LIST.getMaxMinTrafficInfo();
    }
    while(choce!="end");

}
