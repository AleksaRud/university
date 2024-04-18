/* Рудович Александра, 1 курс, пи, фск */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include <vector>
using namespace std;

class Test
{
public:
    string str[30];
    int num;
    virtual void Sum() = 0;
    virtual void Count_done() = 0;
    friend istream& operator>>(istream& in, Test& t)
    {
        t.num=0;
        ifstream in1("Olimp.txt");
        if (in1.is_open())
        {
            while (getline(in1, t.str[t.num]))
            {
                cout<<t.str[t.num]<<endl;
                t.num++;
            }

        }
        in1.close();
        return in;
    }
};
struct command
{
    string name;
    string country;
    int SUM;
    int count_done;
    int goals[10];
    string g;
};

void Swap(command &s1, command &s2)
{
    command temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

class Prises: public Test
{
    list<command> lc;
    list<command> Win_lc;
    int lsize;
public:
    string for_output;
    Prises()
    {
        lsize = 0;
    }
    Prises(command tlc[], int n)
    {
        string sg="";
        int j;
        for(int k=0; k<n; k++)
        {
            j=0;
            for(int i = 0; i<10; i++)
            {
                for(j=j+1; j<tlc[k].g.size();j++)
                {
                    if(tlc[k].g[j]==' ') break;
                    sg+=tlc[k].g[j];
                }
                int K=0;
                if(sg=="") break;
                for(int l=0; l<sg.size();l++)
                {

                    if(sg[l]=='0')
                        K=K*10 + 0;
                    if(sg[l]=='1')
                        K=K*10 + 1;
                    if(sg[l]=='2')
                        K=K*10 + 2;
                    if(sg[l]=='3')
                        K=K*10 + 3;
                    if(sg[l]=='4')
                        K=K*10 + 4;
                    if(sg[l]=='5')
                        K=K*10 + 5;
                    if(sg[l]=='6')
                        K=K*10 + 6;
                    if(sg[l]=='7')
                        K=K*10 + 7;
                    if(sg[l]=='8')
                        K=K*10 + 8;
                    if(sg[l]=='9')
                        K=K*10 + 9;

                }

                tlc[k].goals[i]=K;

                sg.clear();
            }
        lc.push_back(tlc[k]);
        lsize = n;
        }
    }

    virtual void Sum()
    {
        for(int i=0; i<lsize; i++)
        {
            command a = lc.front();
            a.SUM=0;
            for(int j=0; j<10; j++)
            {
                a.SUM+=a.goals[j];
            }

            lc.pop_front();
            lc.push_back(a);
        }
    }
    virtual void Count_done()
    {
        for(int i=0; i<lsize; i++)
        {
            command a = lc.front();
            a.count_done=0;
            for(int j=0; j<10; j++)
            {
                if(a.goals[j]>0)
                a.count_done++;
            }
            lc.pop_front();
            lc.push_back(a);
        }
    }

    void Sort()
    {
        for_output.clear();
        for_output = "";
        vector<command> V(lsize);
        for(int i=0; i<lsize; i++)
        {
            command a = lc.front();
            V[i]=a;
            lc.pop_front();
        }

        for(int i=0; i < lsize; i++)
        {
            for(int j=i+1; j < lsize; j++)
                {
                    if( V[i].SUM<V[j].SUM)
                    {
                        Swap(V[i], V[j]);
                    }
                }
        }
        for(int i=0; i<lsize; i++)
        {
            command a = V[i];
            for_output = for_output + a.country + "  "+ '\t'+ a.name + '\t'+ to_string(a.SUM) + '\t' + to_string(a.count_done) + '\n';
            lc.push_back(a);
        }
        cout<<for_output<<endl;

    }

    void Find_Win()
    {
        for_output.clear();
        string prizes[11];
        int n=0;
        ifstream in2("Prizy.txt");
        if (in2.is_open())
        {

            while (getline(in2, prizes[n]))
            {
                cout<<prizes[n]<<endl;
                n++;
            }

        }
        in2.close();
        cout<<endl;

        for(int i=0; i<n; i++)
        {

            command a = lc.front();
            Win_lc.push_back(a);
            lc.pop_front();
            lc.push_back(a);
        }

        for(int i=0; i<n; i++)
        {
            command a = Win_lc.front();
            for_output=for_output + a.country + "  "+'\t'  + a.name + '\t'+ to_string(a.SUM) + '\t' + prizes[i]  +  '\n';
            Win_lc.push_back(a);
            Win_lc.pop_front();

        }
        cout<<for_output<<endl;
    }

};

int main()
{

    Prises TT;
    cin>>TT;
    cout<<endl;
    cout<<endl;
    command *t;
    t = new command [TT.num];
    string sn,sg, sc;

    for(int i =0; i<TT.num; i++)
    {
        int j;
        for(j=0; j<TT.str[i].size();j++)
        {
            if(TT.str[i][j]==' ') break;
            sc+= TT.str[i][j];
        }
        for(j=j+1; j<TT.str[i].size();j++)
        {
            if(TT.str[i][j]==':') break;
            sn+= TT.str[i][j];
        }

        for(j= j+1; j<TT.str[i].size();j++)
        {
            sg+= TT.str[i][j];
        }
        t[i].name = sn;
        t[i].country = sc;
        t[i].g = sg;
        sc.clear();
        sn.clear();
        sg.clear();
    }

    Prises T(t, TT.num);
    T.Sum();
    T.Count_done();
    T.Sort();

    ofstream out1;
    out1.open("Result.txt");
    if (out1.is_open())
    {
        out1 << T.for_output << endl;
    }
    out1.close();

    T.Find_Win();

    ofstream out2;
    out2.open("Diplomy.txt");
    if (out2.is_open())
    {
        out2 << T.for_output + '\n' << endl;
    }
    out2.close();

}
