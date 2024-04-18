/*Рудович Александра, 1 курс, пи, фск*/


#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include <list>
#include <vector>
using namespace std;
struct prizes
{
    string firma;
    string type_of_prize;
    int cost_of_prize;
};

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x2 - *(int*)x1 );
}

void Swap(prizes &s1, prizes &s2)
{
    prizes temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

class TGoods
{
public:
    int num_pr;
    list<prizes> PRIZES;
    int S, M;
    string for_output;
    TGoods()
    {
        num_pr = 0;
    }
    TGoods(prizes T)
    {
        PRIZES.push_back(T);
        num_pr++;
    }

    TGoods(prizes* T, int tn)
    {
        for(int i=0; i<tn; i++)
        {
            PRIZES.push_back(T[i]);
            num_pr++;
        }
    }

    friend istream& operator>>(istream& in, TGoods& t)
    {

        int n=0;
        string str[30], space = " ";

        ifstream in1("ListGoods.txt");
        if (in1.is_open())
        {
            while (getline(in1, str[n]))
            {
                cout<<str[n]<<endl;
                n++;
            }

        }
        in1.close();

        t.S = stoi(str[0]);
        t.M = stoi(str[1]);
        prizes* Pr;
        Pr = new prizes[t.M];
        //cout<<t.TS<<"   "<<t.TM<<endl;
        string* type_of_present;
        string* scost_of_presents;
        string* name_of_shop;
        type_of_present = new string[t.M];
        scost_of_presents = new string[t.M];
        name_of_shop = new string[n-2-t.M];

        int* cost_of_presents;
        cost_of_presents = new int[t.M];

        int j=0,k=0,g=0;
        for(int i=2; i<n; i++)
        {
            if(str[i][0]=='*')
            {
                name_of_shop[j]=str[i];
                //cout<<name_of_shop[j]<<endl;
                j++;
                continue;
            }
            else
            {
                type_of_present[k].assign(str[i], 0, str[i].find_last_of(space));
                scost_of_presents[k].assign(str[i], str[i].find_last_of(space)+1, str[i].size() - str[i].find_last_of(space));
                cost_of_presents[k]=stoi(scost_of_presents[k]);
                //cout<<type_of_present[k]<<endl;
                //cout<<scost_of_presents[k]<<endl;
                //cout<<cost_of_presents[k]<<endl;
                Pr[g].type_of_prize = type_of_present[k];
                Pr[g].cost_of_prize = cost_of_presents[k];
                Pr[g].firma = name_of_shop[j-1];
                g++;
                k++;
                continue;
            }
        }
        //cout<<endl;
        //cout<<endl;


        for(int i=0; i<t.M; i++)
        {
            t.PRIZES.push_back(Pr[i]);
            t.num_pr++;
            //cout<<Pr[i].firma<<":  "<<Pr[i].type_of_prize<<"  " <<Pr[i].cost_of_prize<<endl;
        }


        return in;
    }
//своя сортировка
    void Sort()
    {
        for_output.clear();
        for_output = "";
        vector<prizes> V(num_pr);
        for(int i=0; i<num_pr; i++)
        {
            prizes a = PRIZES.front();
            V[i]=a;
            PRIZES.pop_front();
        }

        for(int i=0; i < num_pr; i++)
        {
            for(int j=i+1; j < num_pr; j++)
                {
                    if( V[i].cost_of_prize<V[j].cost_of_prize)
                    {
                        Swap(V[i], V[j]);
                    }
                }
        }
        for(int i=0; i<num_pr; i++)
        {
            prizes a = V[i];
            for_output = for_output + a.firma+ ":  "+ a.type_of_prize + "  "+ to_string(a.cost_of_prize) + '\n';
            PRIZES.push_back(a);
        }
        //cout<<for_output<<endl;

    }
//стандартная сортировка
    void SSort()
    {
        int* costs;
        costs = new int[num_pr];
        vector<prizes> V(num_pr);
        for(int i=0; i<num_pr; i++)
        {
            prizes a = PRIZES.front();
            V[i]=a;
            PRIZES.pop_front();
            costs[i] = a.cost_of_prize;
        }

        qsort(costs, num_pr, sizeof(int), compare);

        for(int i=0; i < num_pr; i++)
        {
            for(int j=i; j < num_pr; j++)
            {
                if( V[j].cost_of_prize == costs[i])
                {
                    Swap(V[i], V[j]);
                }
            }
        }

        for(int i=0; i<num_pr; i++)
        {
            prizes a = V[i];
            for_output = for_output + a.firma+ ":  "+ a.type_of_prize + "  "+ to_string(a.cost_of_prize) + '\n';
            PRIZES.push_back(a);
        }
        cout<<for_output<<endl;
    }

    void Print()
    {
        for(int i=0; i<num_pr; i++)
        {
            prizes a = PRIZES.front();
            PRIZES.pop_front();
            for_output = for_output + a.firma+ ":  "+ a.type_of_prize + "  "+ to_string(a.cost_of_prize) + '\n';
            PRIZES.push_back(a);
        }
        //cout<<for_output<<endl;


        ofstream out1;
        out1.open("Goods.txt");
        if (out1.is_open())
        {
            out1 << for_output << endl;
        }
        out1.close();

        Sort(); //SSort();

        ofstream out2;
        out2.open("SortGoods.txt");
        if (out2.is_open())
        {
            out2 << for_output << endl;
        }
        out2.close();

    }

    friend ostream& operator<< (ostream& out, TGoods& t)
    {
        for(int i=0; i<t.num_pr; i++)
        {
            prizes a = t.PRIZES.front();
            t.PRIZES.pop_front();
            t.for_output = t.for_output + a.firma+ ":  "+ a.type_of_prize + "  "+ to_string(a.cost_of_prize) + '\n';
            t.PRIZES.push_back(a);
        }
        //cout<<t.for_output<<endl;


        ofstream out1;
        out1.open("Goods.txt");
        if (out1.is_open())
        {
            out1 << t.for_output << endl;
        }
        out1.close();

        t.Sort(); //t.SSort();

        ofstream out2;
        out2.open("SortGoods.txt");
        if (out2.is_open())
        {
            out2 << t.for_output << endl;
        }
        out2.close();
        return out;
    }
};

struct New_prizes
{
    prizes p;
    int new_cost;
};

void Swap_N(New_prizes &s1, New_prizes &s2)
{
    New_prizes temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

class TPizes: protected TGoods
{

    int PR;
    int num;
    pair <string, int> tfc;
    list< pair <string,int> > cost;
    list<prizes> lpr;
    list<New_prizes> NEW_P;
public:
    string for_output_n;
    int OCost, NCost, PCost;
    pair <string, int> Max;
    TPizes(TGoods& t)
    {
        num = t.num_pr;
        for(int i=0; i<num; i++)
        {
            prizes a = t.PRIZES.front();
            lpr.push_back(a);
            t.PRIZES.pop_front();
            t.PRIZES.push_back(a);
            //cout<<a.cost_of_prize<<a.firma<<a.type_of_prize<<endl;
        }

        cin>>PR;

        for(int i=0; i<num; i++)
        {
            prizes t1 = lpr.front();
            lpr.pop_front();
            lpr.push_back(t1);
            New_prizes t2;
            t2.p = t1;
            t2.new_cost = t1.cost_of_prize*(100-PR)*0.01;
            cout<<t2.p.firma<<"  "<<t2.p.type_of_prize<<"  "<<t2.p.cost_of_prize<<"  "<<t2.new_cost<<endl;
            NEW_P.push_back(t2);
        }
    }
    void Sort_New()
    {
        for_output_n.clear();
        for_output_n = "";
        vector<New_prizes> V(num);
        for(int i=0; i<num; i++)
        {
            New_prizes a = NEW_P.front();
            V[i]=a;
            NEW_P.pop_front();
        }

        for(int i=0; i < num; i++)
        {
            for(int j=i+1; j < num; j++)
                {
                    if( V[i].new_cost<V[j].new_cost)
                    {
                        Swap_N(V[i], V[j]);
                    }
                }
        }
        for(int i=0; i<num; i++)
        {
            New_prizes a = V[i];
            for_output_n = for_output_n + a.p.firma+ ":  "+ a.p.type_of_prize + "  "+ to_string(a.p.cost_of_prize) +"  "+ to_string(a.new_cost) + '\n';
            NEW_P.push_back(a);
        }
        cout<<for_output_n<<endl;
    }

    void Cost(TGoods& t)
    {
        OCost=0;
        NCost=0;
        for(int i=0; i<num; i++)
        {
            New_prizes a = NEW_P.front();
            NEW_P.pop_front();
            NEW_P.push_back(a);
            OCost+=a.p.cost_of_prize;
            NCost+=a.new_cost;
        }
        PCost = t.S - NCost;
        //cout<<OCost<<"  "<<NCost<<"  "<<PCost<<endl;
    }
    void Sum()
    {
        for(int i=0; i<num; i++)
        {
            New_prizes a = NEW_P.front();
            NEW_P.pop_front();
            NEW_P.push_back(a);
            New_prizes b = NEW_P.front();
            tfc.first = a.p.firma;
            if(tfc.first != b.p.firma)
            {
                cost.push_back(tfc);
                continue;
            }
            if(tfc.first == b.p.firma)
            {
                tfc.second += a.new_cost;
            }

        }
        for(int i=0;i<cost.size(); i++)
        {
            pair<string, int> a = cost.front();
            cost.pop_front();
            cost.push_back(a);
            cout<<a.first<<"  "<<a.second<<endl;
        }


    }
    void Find_Max()
    {
        Max = cost.front();
        for(int i=0;i<cost.size(); i++)
        {
            pair<string, int> a = cost.front();
            cost.pop_front();
            cost.push_back(a);
            if(Max.second<a.second)
                Max = a;

        }
        cout<<"Max cost in"<<Max.first<<":  "<<Max.second<<endl;
    }
    void Print_N(TGoods& t)
    {
        Cost(t);
        Sum();
        Sort_New();
        Find_Max();
        for_output_n=for_output_n +'\n'+ "Ocost   " +to_string(OCost) +'\n'+ "Ncost   " +to_string(NCost) + '\n'+ "Pcost   " +to_string(PCost) + '\n' + "Max cost in" + Max.first + "  " + to_string(Max.second) + '\n';
        ofstream out3;
        out3.open("Result.txt");
        if (out3.is_open())
        {
            out3 << for_output_n << endl;
        }
        out3.close();
    }
};

int main()
{
    TGoods tg;
    cin>>tg;
    cout<<endl;
    TPizes tp(tg);
    tp.Cost(tg);
    cout<<endl;
    tp.Sum();
    cout<<endl;
    tp.Sort_New();
    tp.Find_Max();
    tp.Print_N(tg);
    //tg.SSort();
    //cout << tg;
    //tg.Print();
    //tg.Sort();
}
