/*Рудович Александра, 1 курс, пи, фск

1.	Задан текстовый файл Data.txt, содержащий список в следующем виде :
ФИО пробел ДАТА пробел МЕСЯЦ  пробел  ГОД
 Например
Джеймс_Гослинг		19 мая 1955
Де́ннис_Макалистэйр_Ри́тчи 9 сентября 1941
Байрон_Ада_Августа	 10 декабря 1815
Джон_фон_Нейман 		 3 декабря 1903
Дейкстра_Эдсгер_Вибе 	 11 мая 1930
Уильям_Генри_Гейтс	 28 октября 1955
Андерс_Хейлсберг		15 декабря 1960
Составить программу получения:
•	возраста  каждого человека
•	общий средний возраст всех
•	общего списка, состоящего из фамилии, даты рождения, возраста.
•	Список записать в файл Result.txt
•	Общий средний возраст записать первой строкой в файл Result.txt.
•	упорядочить список по убыванию возраста, используя свою любую сортировку
•	упорядоченный список записать в файл ResultSortMy.txt
•	упорядочить список по возрастанию возраста, используя  стандартную qsort
•	Упорядоченный список записать в файл ResultSort.txt
•	Для проверки результатов информацию созданных списков вывести на экран

 */


#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;


struct person
{
    string FIO;
    int date;
    string month;
    int year;
};

struct personInfo
{
    string surname;
    string birthday;
    int age;
};

int Age(int d, int m, int y, int td, int tm, int ty)
{
    int A;
    A = ty + tm/12 + td/30 - y - m/12 - d/30;
    return A;
}

int monthToNumber(string m)
{

    string month[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	for (int i = 0; i < 12; i++)
        if ( m == month[i])
            return i + 1;
}

void swapWords(string &s1, string &s2)
{
    string temp;
    temp = s1;
    s1.clear();
    s1 = s2;
    s2.clear();
    s2 = temp;
}

void swapNumbers(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}


int main()
{
    string str[30], space = " ";

    ifstream in("Data.txt");
    if (in.is_open())
    {
        int i=0;
        while (getline(in, str[i]))
        {
            cout << str[i]  <<endl;
            i++;
        }

    }
    in.close();

    int i = 0, num_of_person;
    while(i < 30)
    {
        if(str[i] == "")
        {
            num_of_person = i;
            break;
        }
        i++;
    }

    string* datas;
    datas = new string[num_of_person];
    string* monthes;
    monthes = new string[num_of_person];
    string* years;
    years = new string[num_of_person];
    for(int i = 0; i<num_of_person; i++)
    {
        datas[i].assign(str[i], str[i].find(space)+1, str[i].find(space, str[i].find(space)+1) - str[i].find(space)-1);
        monthes[i].assign(str[i], str[i].find(space, str[i].find(space)+1) + 1, str[i].find_last_of(space) - str[i].find(space, str[i].find(space)+1) - 1);
        years[i].assign(str[i], str[i].find_last_of(space) + 1, str[i].size() - str[i].find_last_of(space)-1);
    }

    person* Persons;
    Persons = new person [num_of_person];
    for(int i = 0; i < num_of_person; i++)
    {
        Persons[i].FIO.assign(str[i], 0, str[i].find(space));
        Persons[i].date = stoi(datas[i]);
        Persons[i].month = monthes[i];
        Persons[i].year = stoi(years[i]);
    }

    int today_date = 14;
    int today_month = 12;
    int today_year = 2022;

    personInfo* person_;
    person_ = new personInfo[num_of_person];
    for(int i = 0; i < num_of_person; i++)
    {
        person_[i].surname.assign(Persons[i].FIO, 0, Persons[i].FIO.find("_"));
        person_[i].birthday = datas[i] + " " + monthes[i] + " " + years[i];
        person_[i].age = Age(Persons[i].date, monthToNumber(Persons[i].month), Persons[i].year, today_date, today_month, today_year);
    }

    string spisok;
    for(int i=0; i<num_of_person; i++)
        spisok = spisok + person_[i].surname + "  " + person_[i].birthday + "  " + to_string(person_[i].age) + '\n';

    ofstream out1;
    out1.open("Result.txt");
    if (out1.is_open())
    {
        out1 << spisok << endl;
    }
    out1.close();

    int mid_age = 0;
    for(int i = 0; i < num_of_person; i++)
        mid_age += person_[i].age;
    mid_age /= num_of_person;

    spisok = to_string(mid_age) + '\n' + spisok;
    ofstream out2;
    out2.open("Result.txt");
    if (out2.is_open())
    {
        out2 << spisok << endl;
    }
    out2.close();
    spisok.clear();

    for(int i=0; i < num_of_person; i++)
    {
        for(int j=i+1; j < num_of_person; j++)
        {
            if( person_[j].age > person_[i].age)
            {
                 swapWords(person_[i].surname, person_[j].surname);
                 swapWords(person_[i].birthday, person_[j].birthday);
                 swapNumbers(person_[i].age, person_[j].age);
            }
        }
    }

    for(int i=0; i<num_of_person; i++)
        spisok = spisok + person_[i].surname + "  " + person_[i].birthday + "  " + to_string(person_[i].age) + '\n';

    ofstream out3;
    out3.open("ResultSortMy.txt");
    if (out3.is_open())
    {
        out3 << spisok << endl;
    }
    out3.close();
    spisok.clear();

    int* ages;
    ages = new int[num_of_person];
    for(int i = 0; i<num_of_person; i++)
        ages[i] = person_[i].age;

    qsort(ages, num_of_person, sizeof(int), compare);

    for(int i=0; i < num_of_person; i++)
    {
        for(int j=i; j < num_of_person; j++)
        {
            if( person_[j].age == ages[i])
            {
                 swapWords(person_[i].surname, person_[j].surname);
                 swapWords(person_[i].birthday, person_[j].birthday);
                 swapNumbers(person_[i].age, person_[j].age);
            }
        }
    }

    for(int i=0; i<num_of_person; i++)
        spisok = spisok + person_[i].surname + "  " + person_[i].birthday + "  " + to_string(person_[i].age) + '\n';

    ofstream out4;
    out4.open("ResultSort.txt");
    if (out4.is_open())
    {
        out4 << spisok << endl;
    }
    out4.close();

    cout<<endl;

    string line;
    ifstream in1("Result.txt");
    if (in1.is_open())
    {
        while (getline(in1, line))
        {
            cout << line  <<endl;
        }

    }
    in1.close();

    cout<<endl;

    ifstream in2("ResultSortMy.txt");
    if (in2.is_open())
    {
        while (getline(in2, line))
        {
            cout << line  <<endl;
        }

    }
    in2.close();

    cout<<endl;

    ifstream in3("ResultSort.txt");
    if (in3.is_open())
    {
        while (getline(in3, line))
        {
            cout << line  <<endl;
        }

    }
    in3.close();
}
