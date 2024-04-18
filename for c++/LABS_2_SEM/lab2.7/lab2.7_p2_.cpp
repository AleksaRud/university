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
class Tel
{
public:
    int* num;
    string* info;
    int size;

    Tel()
    {
        size = 0;
        num = NULL;
        info = NULL;
    }
    Tel(int size_)
    {
        size = size_;
        num = new int [size];
        info = new string [size];
    }
    Tel(int size_of_num_, int* num_)
    {
        size = size_of_num_;
        num = new int [size];
        info = new string [size];
        for(int i=0; i<size; i++)
            num[i] = num_[i];
    }
    Tel(int size_of_num_, int* num_, string* info_)
    {
        size = size_of_num_;
        num = new int [size];
        info = new string [size];
        for(int i=0; i<size; i++)
        {
            num[i] = num_[i];
            info[i] = info_[i];
        }
    }
    Tel(Tel& t)
    {
        size = t.size;
        num = new int[size];
        info = new string[size];
        for(int i=0; i<size; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
    }
    ~Tel()
    {
        delete[]num;
        delete[]info;
    }

    void Add(int num_)
    {
        Tel t(size);
        for(int i = 0; i<size; i++)
        {
            t.num[i] = num[i];
            t.info[i] = info[i];
        }
        delete[]num;
        delete[]info;
        size++;
        num = new int[size];
        info = new string[size];
        for(int i = 0; i<size-1; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
        num[size-1] = num_;
    }
    void Add(int num_, string info_)
    {
        Tel t(size);
        t.num = new int[t.size];
        t.info = new string[t.size];
        for(int i = 0; i<t.size; i++)
        {
            t.num[i] = num[i];
            t.info[i] = info[i];
        }
        delete[]num;
        delete[]info;
        size++;
        num = new int[size];
        info = new string[size];
        for(int i = 0; i<size-1; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
        num[size-1] = num_;
        info[size-1] = info_;
    }
    void Delete(int pos)
    {
        if (pos>size) throw "Uncorrect index";
        Tel t(size);
        t.num = new int[t.size];
        t.info = new string[t.size];
        for(int i = 0; i<t.size; i++)
        {
            t.num[i] = num[i];
            t.info[i] = info[i];
        }
        delete[]num;
        delete[]info;
        size--;
        num = new int[size];
        info = new string[size];
        for(int i = 0; i<pos; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
        for(int i = pos; i<size; i++)
        {
            num[i] = t.num[i+1];
            info[i] = t.info[i+1];
        }
    }
    void Delete(int pos1, int pos2)
    {
        if (pos1>size) throw "Uncorrect index";
        Tel t(size);
        t.num = new int[t.size];
        t.info = new string[t.size];
        for(int i = 0; i<t.size; i++)
        {
            t.num[i] = num[i];
            t.info[i] = info[i];
        }
        delete[]num;
        delete[]info;
        int n = pos2-pos1+1;
        size-=n;
        num = new int[size];
        info = new string[size];
        for(int i = 0; i<pos1; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
        for(int i = pos2; i<size; i++)
        {
            num[i-n] = t.num[i];
            info[i-n] = t.info[i];
        }
    }
    int Find(int num_)
    {
        for(int i = 0; i<size; i++)
            if(num[i] == num_)
                return i;
        cout<<"There are no such numbers"<<endl;
    }
    void Replace(int pos, int num_, string info_)
    {
        if (pos>size) throw "Uncorrect index";
        num[pos] = num_;
        info[pos] = info_;
    }
    void Replace(int pos1, int pos2, int* num_, string* info_)
    {
        if (pos1>size) throw "Uncorrect index";
        if(pos2>size)
            for(int i = pos1; i<size; i++)
            {
                num[i] = num_[i];
                info[i] = info_[i];
            }
        else
            for(int i = pos1; i<pos2; i++)
            {
                num[i] = num_[i];
                info[i] = info_[i];
            }
    }
    void Print()
    {
        cout<<setw(10)<<"Number"<<setw(15)<<"Info"<<endl;
        for(int i=0; i<size; i++)
            cout<<setw(10)<<num[i]<<"   "<<setw(15)<<info[i]<<endl;
        cout<<endl;
    }
};

class EduTel: Tel
{
    string* dopinfo;
public:
    EduTel()
    {
        Tel();
        dopinfo = NULL;
    }
    EduTel(int _size):Tel(_size), dopinfo(new string[size]){}
    EduTel(int size_of_num_, int* num_): Tel(size_of_num_, num){}
    EduTel(int size_of_num_, int* num_, string* info_): Tel(size_of_num_, num_, info_){}
    EduTel(int size_of_num_, int* num_, string* info_, string* dopinfo_)
    {
        Tel(size_of_num_, num_, info_);
        for(int i=0; i<size; i++)
            dopinfo[i] = dopinfo_[i];
    }
    EduTel(Tel& t)
    {
        size = t.size;
        num = new int[size];
        info = new string[size];
        dopinfo = new string[size];
        for(int i=0; i<size; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
        }
    }
    EduTel(EduTel& t)
    {
        size = t.size;
        num = new int[size];
        info = new string[size];
        dopinfo = new string[size];
        for(int i=0; i<size; i++)
        {
            num[i] = t.num[i];
            info[i] = t.info[i];
            dopinfo[i] = t.dopinfo[i];
        }
    }
    ~EduTel()
    {
        delete[]num;
        delete[]info;
        delete[]dopinfo;
    }

    void AddDopInfo(int pos, string dopinfo_)
    {
        if (pos>size) throw "Uncorrect index";
        dopinfo[pos] = dopinfo_;
    }
    void Print()
    {
        cout<<setw(10)<<"Number"<<setw(15)<<"Info"<<setw(30)<<"Additional Info"<<endl;
        for(int i=0; i<size; i++)
            cout<<setw(10)<<num[i] << "   "<<setw(15)<<info[i]<<setw(15)<< "   "<<dopinfo[i]<<endl;
        cout<<endl;
    }
};

int main()
{
    try
    {
        Tel A(5);
        A.Add(12345678, "test1");
        A.Add(87654321, "test2");
        EduTel B(A);
        A.Add(23454323, "School");
        A.Delete(2);
        A.Replace(0, 88982733, "Home");
        B.AddDopInfo(1, "newtest");
        A.Print();
        B.Print();
    }
    catch(const char* e)
    {
        cout << "Error: "<<e<<endl;
    }
}
