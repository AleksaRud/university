/*Рудович Александра, 1 курс, пи, фск*/


#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;

struct person
{
    string name;
    int TSUM;
    int SUM;
    int RSUM;
    int SUMD;
};

struct person_n
{
    string name;
    int TSUM;
    int SUM;
    int RSUM;
    int SUMD;
};

bool isANumber(char c)
{
    if('0' <= c && c <= '9')
        return true;
    else return false;
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

void CorrFunc(int sum, int prc, int tsum, int &rsum, int &sumd)
{
    rsum = sum + sum * prc/100;
    sumd = rsum - tsum;
}

int sum(int* a, int n)
{
    int s=0;
    for(int i =0; i<n; i++)
        s+=a[i];
    return s;
}
int main()
{
    string str[30], space = " ";
    int ALLSUM = 3500;
    int PRC = 8;
    ifstream in("spisok.txt");
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


    string* sum_str;
    sum_str = new string[num_of_person];
    string* tsum_str;
    tsum_str = new string[num_of_person];

    for(int i = 0; i<num_of_person; i++)
    {
        sum_str[i].assign(str[i], str[i].find_last_of(space) + 1, str[i].find_last_of(space) - str[i].find(space, str[i].find(space)+1) - 1);
        tsum_str[i].assign(str[i], str[i].find_last_of(".") + 2, str[i].size() - str[i].find_last_of(space)-1);

    }


    person* Persons;
    Persons = new person [num_of_person];
    for(int i = 0; i < num_of_person; i++)
    {
        Persons[i].name = "";
        Persons[i].SUM = stoi(sum_str[i]);
        Persons[i].TSUM = stoi(tsum_str[i]);
        Persons[i].RSUM = 0;
        Persons[i].SUMD = 0;
        for(int j = 0; j<str[i].size(); j++)
        {
            if(!isANumber(str[i][j]))
            {
                Persons[i].name += str[i][j];
                if(isANumber(str[i][j+2]))
                    break;
            }
        }
    }

    cout<<endl;

    for(int i = 0; i<num_of_person; i++)
    {
        cout<<Persons[i].name << '\t' << Persons[i].SUM << '\t' << Persons[i].TSUM<<endl;
    }
    cout<<endl;

    // a)
    for(int i=0; i < num_of_person; i++)
    {
        for(int j=i+1; j < num_of_person; j++)
        {
            if( Persons[j].SUM > Persons[i].SUM)
            {
                 swapWords(Persons[i].name, Persons[j].name);
                 swapNumbers(Persons[i].SUM, Persons[j].SUM);
                 swapNumbers(Persons[i].TSUM, Persons[j].TSUM);
            }
        }
    }

    //b)

    int* sums;
    sums = new int[num_of_person];
    for(int i = 0; i<num_of_person; i++)
        sums[i] = Persons[i].SUM;

    qsort(sums, num_of_person, sizeof(int), compare);

    for(int i=0; i < num_of_person; i++)
    {
        for(int j=i; j < num_of_person; j++)
        {
            if( Persons[j].SUM == sums[i])
            {
                 swapWords(Persons[i].name, Persons[j].name);
                 swapNumbers(Persons[i].SUM, Persons[j].SUM);
                 swapNumbers(Persons[i].TSUM, Persons[j].TSUM);
            }
        }
    }


    for(int i = 0; i<num_of_person; i++)
    {
        cout<<Persons[i].name << '\t' << Persons[i].SUM << '\t' << Persons[i].TSUM<<endl;
    }
    cout<<endl;


    for(int i = 0; i< num_of_person; i++)
    {
        CorrFunc(Persons[i].SUM, PRC, Persons[i].TSUM, Persons[i].RSUM, Persons[i].SUMD);
    }

    for(int i = 0; i<num_of_person; i++)
    {
        cout<<Persons[i].name << '\t' << Persons[i].SUM << '\t' << Persons[i].TSUM<< '\t' << Persons[i].RSUM << '\t' << Persons[i].SUMD<<endl ;
    }
    cout<<endl;


    person_n* Persons_new;
    Persons_new = new person_n [num_of_person];
    for(int i = 0; i < num_of_person; i++)
    {
        Persons_new[i].name =  Persons[i].name;
        Persons_new[i].SUM = Persons[i].SUM;
        Persons_new[i].TSUM = Persons[i].TSUM;
        Persons_new[i].RSUM = Persons[i].RSUM;
        Persons_new[i].SUMD = Persons[i].SUMD;
    }

    for(int i=0; i < num_of_person; i++)
    {
        for(int j=i+1; j < num_of_person; j++)
        {
            if( Persons_new[j].RSUM < Persons_new[i].RSUM)
            {
                 swapWords(Persons_new[i].name, Persons_new[j].name);
                 swapNumbers(Persons_new[i].SUM, Persons_new[j].SUM);
                 swapNumbers(Persons_new[i].TSUM, Persons_new[j].TSUM);
                 swapNumbers(Persons_new[i].RSUM, Persons_new[j].RSUM);
                 swapNumbers(Persons_new[i].SUMD, Persons_new[j].SUMD);
            }
        }
    }
    for(int i = 0; i<num_of_person; i++)
    {
        cout<<Persons_new[i].name << '\t' << Persons_new[i].SUM << '\t' << Persons_new[i].TSUM<< '\t' << Persons_new[i].RSUM<< '\t'<< Persons_new[i].SUMD<< endl;
    }

    string spisok;

    for(int i=0; i<num_of_person; i++)
    {
        spisok = spisok + Persons_new[i].name + '\t' ;
        spisok = spisok + to_string(Persons_new[i].SUM) + '\t' ;
        spisok = spisok + to_string(Persons_new[i].TSUM)+ '\t';
        spisok = spisok + to_string(Persons_new[i].RSUM) + '\t' ;
        spisok = spisok + to_string(Persons_new[i].SUMD) + '\n';
    }


    ofstream out1;
    out1.open("OutSpisok.txt");
    if (out1.is_open())
    {
        out1 << spisok << endl;
    }
    out1.close();

    cout<<endl;

    int* f_sum;
    int* f_tsum;
    int* f_rsum;
    int* f_sumd;

    f_sum = new int [num_of_person];
    f_tsum = new int [num_of_person];
    f_rsum = new int [num_of_person];
    f_sumd = new int [num_of_person];
    for(int i =0; i < num_of_person; i++)
    {
        f_sum[i] = Persons[i].SUM;
        f_tsum[i] = Persons[i].TSUM;
        f_rsum[i] = Persons[i].RSUM;
        f_sumd[i] = Persons[i].SUMD;
    }

    int OSUM = sum(f_sum, num_of_person);
    int OTSUM = sum(f_tsum, num_of_person);
    int ORSUM = sum(f_rsum, num_of_person);
    int OSUMD = sum(f_sumd, num_of_person);
    int RES = ALLSUM - OTSUM + OSUMD;
    cout<< OSUM << endl;
    cout<< OTSUM << endl;
    cout<< ORSUM << endl;
    cout<< OSUMD << endl;
    cout<< RES << endl;
    string other_result;
    other_result = other_result + "Number of persons = " + to_string(num_of_person) +'\n';
    other_result = other_result + "Sum of costs " + to_string(OTSUM) +'\n';
    other_result = other_result + "Sum of money without prc " + to_string(OSUM) +'\n';
    other_result = other_result + "Sum of money with prc " + to_string(ORSUM) +'\n';
    other_result = other_result + "Sum of money that were returned " + to_string(OSUMD) +'\n';
    other_result = other_result + "Money left " + to_string(RES) +'\n';

    ofstream out2;
    out2.open("OutSpisok.txt", ios::app);
    if (out2.is_open())
    {
        out2 << other_result << endl;
    }
    out2.close();

}
