/*Рудович Александра, 1 курс, пи, фск
лаб 2.7

Вариант 11.
 Разработать класс « Телефонов»  для хранения регистрационной информации о номерах телефонов.
 Реализовать функции добавления, удаления, поиска, замены, печати.
 Определить конструкторы и деструктор.
 Определить private-, public- производный класс телефонов учебного заведения, имеющий дополнительную информацию.
 Определить конструкторы, деструкторы и функцию печати.

*/

#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

struct tel_list
{
    int* number;
    string* info;
};

class Telephone
{

    //tel_list* tl;
    int* tnum;
    string* tinfo;
    int lsize;

public:
//конструктор по умолчанию: создаёт пустой список
    Telephone()
    {
        lsize = 0;
        tnum = NULL;
        tinfo = NULL;
    }
//конструктор с параметрами: создаёт пустой список размера lsize1
    Telephone(int lsize1)
    {
        lsize = lsize1;
        tnum = new int[lsize];
        tinfo = new string[lsize];
    }
//конструктор с параметрами: создаёт список, состоящий из одного номера и информации о нём(на основе объекта tl_1 структуры tel_list)
    Telephone(int num, string inf)
    {
        lsize = 1;
        tnum = new int[lsize];
        tinfo = new string[lsize];
        tnum[0] = num;
        tinfo[0] = inf;
    }
//конструктор с параметрами: создаёт список, состоящий из номеров и информации о них(на основе массива структуры tel_list)
    Telephone(int* num, string* inf)
    {
        lsize = sizeof(num)/sizeof(int);
       // tl = new tel_list[lsize];
        tnum = new int[lsize];
        tinfo = new string[lsize];
        for(int i = 0; i<lsize; i++)
        {
            tnum[i] = num[i];
            tinfo[i] = inf[i];
        }
    }
//конструктор копирования
    Telephone(const Telephone& t)
    {
        delete[]tnum;
        delete[]tinfo;
        //lsize = sizeof(t.tl)/(sizeof(int)+sizeof(string));
        //tl = new tel_list[lsize];
        //lsize = t.tnum.size();
        lsize = sizeof(t.tnum)/sizeof(int);
        tnum = new int[lsize];
        tinfo = new string[lsize];
        for(int i=0; i<lsize; i++)
        {
            tnum[i] = t.tnum[i];
            tinfo[i] = t.tinfo[i];
        }
    }
//деструктор
    ~Telephone()
    {
        delete[]tnum;
        delete[]tinfo;
    }
//функция добавления номера и информации о нём(номер и информация даны разными переменнами); добавляет в конец
    void Add(int tel, string in)
    {
        Telephone t;
        t.tnum = new int[lsize];
        t.tinfo = new string[lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tnum[i] = tnum[i];
            t.tinfo[i] = tinfo[i];
        }
        delete[]tnum;
        delete[]tinfo;
        lsize++;
        tnum = new int[lsize];
        tinfo = new string[lsize];
        for(int i=0; i<lsize-1; i++)
        {
            tnum[i] = t.tnum[i];
            tinfo[i] = t.tinfo[i];
        }
        tnum[lsize-1] = tel;
        tinfo[lsize-1] = in;
    }
    /*
//функция добавления номера и информации о нём (через объект структуры); добавляет в конец
    void Add(tel_list tl_1)
    {
        Telephone t;
        t.tl = new tel_list[lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tl[i].number = tl[i].number;
            t.tl[i].info = tl[i].info;
        }
        delete[]tl;

        tl = new tel_list [lsize+1];
        for(int i=0; i<lsize; i++)
        {
            tl[i].number = t.tl[i].number;
            tl[i].info = t.tl[i].info;
        }
        tl[lsize].number = tl_1.number;
        tl[lsize].info = tl_1.info;
        lsize++;
    }
//функция добавления нескольких номеров и информации о них; добавляет в конец
    void Add(tel_list* tl_1)
    {
        Telephone t;
        int n = sizeof(tl_1)/sizeof(tel_list);
        t.tl = new tel_list[lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tl[i].number = tl[i].number;
            t.tl[i].info = tl[i].info;
        }
        delete[]tl;

        tl = new tel_list [lsize+n];
        for(int i=0; i<lsize; i++)
        {
            tl[i].number = t.tl[i].number;
            tl[i].info = t.tl[i].info;
        }
        for(int i=0; i<n; i++)
        {
            tl[lsize+i].number = tl_1[i].number;
            tl[lsize+i].info = tl_1[i].info;
        }
        lsize+=n;
    }
    */
//функция удаления одного номера и информации о нём(находится на позиции pos)
    void Delete(int pos)
    {
        Telephone t;
        t.tnum = new int[lsize];
        t.tinfo = new string[lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tnum[i] = tnum[i];
            t.tinfo[i] = tinfo[i];
        }
        delete[]tnum;
        delete[]tinfo;

        tnum = new int[lsize-1];
        tinfo = new string[lsize-1];
        for(int i=0; i<pos; i++)
        {
            tnum[i] = t.tnum[i];
            tinfo[i] = t.tinfo[i];
        }
        for(int i=pos; i<lsize-1; i++)
        {
            tnum[i] = t.tnum[i+1];
            tinfo[i] = t.tinfo[i+1];
        }
        lsize--;
    }
    /*
//функция удаления нескольких номеров и информации о них(от позиции pos1 до позиции pos2)
    void Delete(int pos1, int pos2)
    {
        Telephone t;
        int n = pos2 - pos1 +1;
        t.tl = new tel_list [lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tl[i].number = tl[i].number;
            t.tl[i].info = tl[i].info;
        }
        delete[]tl;
        tl = new tel_list [lsize-n];
        for(int i=0; i<pos1; i++)
        {
            tl[i].number = t.tl[i].number;
            tl[i].info = t.tl[i].info;
        }
        for(int i=pos1; i<lsize-n; i++)
        {
            tl[i].number = t.tl[i+n].number;
            tl[i].info = t.tl[i+n].info;
        }
        lsize-=n;
    }*/
//функция поиска номера телефона в списке: возвращает номер телефона и информацию о нём(если не найдён - сообщение, что номер не найден)
    int Find(int num)
    {
        for(int i=0; i<lsize; i++)
            if(tnum[i] == num)
                return i;
        cout<<"There are no such telephone numbers"<<endl;
    }
//функция замены номера, который находится на позиции pos, и информации о нём
    void Replace(int pos, int num, string in)
    {
        tnum[pos] = num;
        tinfo[pos] = in;
    }
    /*
//функция замены номеров, начиная с позиции pos, и информации о них
    void Replace(int pos, tel_list* tl_1)
    {
        int n = sizeof(tl_1)/sizeof(tel_list);
        if(n<lsize)
        for(int i = 0; i<n; i++)
        {
            tl[i+pos].number = tl_1[i].number;
            tl[i+pos].info = tl_1[i].info;
        }
        if(n>=lsize)
        for(int i = 0; i<lsize; i++)
        {
            tl[i+pos].number = tl_1[i].number;
            tl[i+pos].info = tl_1[i].info;
        }
    }*/
//печать всего списка телефонных номеров
    string* Print()
    {
        string* tlist;
        tlist = new string [lsize];
        cout<<setw(10) << "Number" << setw(20) << "Information" << endl;
        for(int i=0; i<lsize; i++)
        {
            tlist[i] = to_string(tnum[i]) + " " + tinfo[i];
            cout<< setw(12) << tnum[i] << "          " << tinfo[i] << endl;
        }
        cout << endl;
        return tlist;
    }
};

/*struct edu_tel_list
{
    int number;
    string info;
    string dop_info;
};*/

class EduTel: public Telephone
{
    tel_list* tl;
    int lsize;
    string* dop_info;
public:
    //конструктор по умолчанию: создаёт пустой список
    EduTel()
    {
        lsize = 0;
        tl = NULL;
        dop_info = NULL;
    }
//конструктор с параметрами: создаёт пустой список размера lsize1
    EduTel(int lsize1)
    {
        lsize = lsize1;
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
    }
//конструктор с параметрами: создаёт список, состоящий из одного номера и информации о нём(на основе объекта tl_1 структуры tel_list)
    EduTel(tel_list tl_1, string dop_info1)
    {
        lsize = 1;
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
        tl[0].number = tl_1.number;
        tl[0].info = tl_1.info;
        dop_info[0] = dop_info1;
    }
//конструктор с параметрами: создаёт список, состоящий из номеров и информации о них(на основе массива структуры tel_list)
    EduTel(tel_list* tl_1, string* dop_info1)
    {
        lsize = sizeof(tl_1)/(sizeof(int)+sizeof(string));
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
        for(int i = 0; i<lsize; i++)
        {
            tl[i].number = tl_1[i].number;
            tl[i].info = tl_1[i].info;
            dop_info[i] = dop_info1[i];
        }
    }
//конструктор с параметрами: создаёт список, состоящий из одного номера и информации о нём(на основе объекта tl_1 структуры tel_list)
    EduTel(tel_list tl_1)
    {
        lsize = 1;
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
        tl[0].number = tl_1.number;
        tl[0].info = tl_1.info;
    }
//конструктор с параметрами: создаёт список, состоящий из номеров и информации о них(на основе массива структуры tel_list)
    EduTel(tel_list* tl_1)
    {
        lsize = sizeof(tl_1)/(sizeof(int)+sizeof(string));
        cout<<sizeof(tl_1)<<"  "<<sizeof(tel_list)<<"  " <<lsize<<endl;
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
        for(int i = 0; i<lsize; i++)
        {
            tl[i].number = tl_1[i].number;
            tl[i].info = tl_1[i].info;
        }
    }
//конструктор копирования
    EduTel(const EduTel& t)
    {
        delete[]tl;
        lsize = sizeof(t.tl)/(sizeof(int)+sizeof(string));
        tl = new tel_list[lsize];
        dop_info = new string[lsize];
        for(int i=0; i<lsize; i++)
        {
            tl[i].number = t.tl[i].number;
            tl[i].info = t.tl[i].info;
            dop_info[i] = t.dop_info[i];
        }
    }
//деструктор
    ~EduTel()
    {
        delete[]tl;
        delete[]dop_info;
    }

    /*void Add(int tel, string in)
    {
        EduTel t;
        t.tl = new tel_list[lsize];
        t.dop_info = new string[lsize];
        for(int i=0; i<lsize; i++)
        {
            t.tl[i].number = tl[i].number;
            t.tl[i].info = tl[i].info;
            t.dop_info[i] = dop_info[i];
        }
        delete[]tl;
        delete[]dop_info;
        lsize++;
        tl = new tel_list [lsize];
        dop_info = new string[lsize];
        for(int i=0; i<lsize-1; i++)
        {
            tl[i].number = t.tl[i].number;
            tl[i].info = t.tl[i].info;
            dop_info[i] = t.dop_info[i];
        }
        tl[lsize-1].number = tel;
        tl[lsize-1].info = in;
    }*/

//меняем дополнительную информацию у номера телефона на позиции pos
    void ReplaceDopInfo(int pos, string S)
    {
        dop_info[pos] = S;
    }
//печать всего списка телефонных номеров
    void Print()
    {
        cout<<lsize<<endl;
        cout<<setw(10) << "Number" << setw(20) << "Information" << setw(20) << "Information" << endl;
        for(int i=0; i<lsize; i++)
            cout<< setw(12) << tl[i].number << "          " << tl[i].info << "          " << dop_info[i] <<endl;
        cout << endl;
    }
};


int main()
{
    string* for_print;

    Telephone A;
    A.Add(123344556, "Home");
    A.Add(245321123, "Work");
    A.Add(345643119, "School");
    A.Add(888888888, "Pizza");
    A.Delete(2);
    A.Replace(1, 735572546, "Home New");
    A.Find(13353626);
    for_print = A.Print();


    for(int i=0; i<sizeof(for_print)/sizeof(string); i++)
        cout<<for_print[i]<<endl;
    //EduTel B(for_print);
    //B.Add(245321123, "Work");
    //B.Add(345643119, "School");
    //B.Add(888888888, "Pizza");
    //B.Delete(2);
    //B.Replace(1, 735572546, "Home New");
    //B.ReplaceDopInfo(0, "new adress: Minsk");
    //B.Print();
}
