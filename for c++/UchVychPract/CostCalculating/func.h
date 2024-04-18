#define __LIST_H__
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include <vector>

using namespace std;
struct Info
{
    string name_base;
    string name_videocard;
    string name_storage_device;
    int material_cost;
    int prod_volume;
    int fin_cost;
};

void Swap(Info& a, Info& b)
{
    Info temp;
    temp = a;
    a = b;
    b = temp;
}

class Product
{
private:
    list<Info> laptop_base;
    int lbsize;
    list<Info> videocard;
    int vcsize;
    list<Info> storage_device;
    int sdsize;

    list<Info> list_products;
    int salary;
    int rent;
    int other_costs;
    int size;

public:
    Product();
    ~Product();
    void ChooseBase(string choce);
    void ChooseVideocard(string choce);
    void ChooseStorageDevice(string choce);
    void Add(string name_lb, string name_vc, string name_sd, int mat_cost, int volume);
    void Delete();
    void Sort(string choce);
    int TotalVolume();
    int InderectCost();
    void ProdCost();
    void Search(string choce);

    friend istream& operator>> (istream& in, Product& t);
    friend ostream& operator<< (ostream& out, Product& t);
    void PrintResult();
};

Product::Product()
{
    size = 0;
    lbsize = 0;
    vcsize = 0;
    sdsize = 0;
}

Product::~Product()
{
    list_products.erase(list_products.begin(), list_products.end());
    size = 0;
}

void Product::ChooseBase(string choce)
{
    int num;
    if(choce == "2")
    {
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        cout << setw(5) << "|" << setw(20) << "Laptop base" << setw(5) << "|" << setw(20) << "Cost of materials" << setw(5) << "|";
        cout << setw(20) << "Production volume" << setw(5) << "|" << endl;
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        for(int i=0; i<lbsize; i++)
        {
            Info tinfo = laptop_base.front();
            laptop_base.pop_front();
            cout << i+1 << ". " << setw(2) << "|" << setw(20) << tinfo.name_base << setw(5) << "|" << setw(20) << tinfo.material_cost << setw(5) << "|";
            cout << setw(20) << tinfo.prod_volume << setw(5) << "|" << endl;
            laptop_base.push_back(tinfo);
        }
        cout << lbsize+1 << ". Random" <<endl;

        string snum;
        int s;
        do
        {
            cout << "Choose current laptop base or random" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(lbsize+1)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(lbsize+1).length()) || (s == -1) || (snum == "0"));
        num = stoi(snum);

        cout << endl;
        if(num == lbsize+1)
            num = rand()%lbsize + 1;
    }
    if(choce == "1")
    {
        num = rand()%lbsize + 1;
    }

    Info temp;
    int j = 0;
    for(auto i = laptop_base.begin(); i != laptop_base.end(); i++)
    {
        if(j<num)
        {
            temp = *i;
            j++;
        }
        else
            break;
    }

    list_products.push_back(temp);
}

void Product::ChooseVideocard(string choce)
{
    int num;
    if(choce == "2")
    {
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        cout << setw(5) << "|" << setw(20) << "Videocard" << setw(5) << "|" << setw(20) << "Cost of materials" << setw(5) << "|";
        cout << setw(20) << "Production volume" << setw(5) << "|" << endl;
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        for(int i=0; i<vcsize; i++)
        {
            Info tinfo = videocard.front();
            videocard.pop_front();
            cout << i+1 << ". " << setw(2) << "|" << setw(20) << tinfo.name_videocard << setw(5) << "|" << setw(20) << tinfo.material_cost << setw(5) << "|";
            cout << setw(20) << tinfo.prod_volume << setw(5) << "|" << endl;
            videocard.push_back(tinfo);
        }
        cout << vcsize+1 << ". Random" <<endl;

        string snum;
        int s;
        do
        {
            cout << "Choose current videocard or random" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(vcsize+1)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(vcsize+1).length()) || (s == -1) || (snum == "0"));
        num = stoi(snum);

        cout << endl;
        if(num == vcsize+1)
            num = rand()%vcsize + 1;
    }
    if(choce == "1")
    {
        num = rand()%vcsize + 1;
    }

    Info temp = list_products.back();
    list_products.pop_back();
    Info temp1;

    int j = 0;
    for(auto i = videocard.begin() ; i != videocard.end(); i++)
    {
        if(j<num)
        {
            temp1 = *i;
            j++;
        }
        else
            break;
    }

    temp.name_videocard = temp1.name_videocard;
    temp.material_cost = temp.material_cost + temp1.material_cost;
    if(temp.prod_volume > temp1.prod_volume)
        temp.prod_volume = temp1.prod_volume;
    else
        temp.prod_volume = temp.prod_volume;

    list_products.push_back(temp);
}

void Product::ChooseStorageDevice(string choce)
{
    int num;
    if(choce == "2")
    {
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        cout << setw(5) << "|" << setw(20) << "Storage device" << setw(5) << "|" << setw(20) << "Cost of materials" << setw(5) << "|";
        cout << setw(20) << "Production volume" << setw(5) << "|" << endl;
        cout << setw(80) << setfill('=') << "=" << setfill(' ') <<endl;
        for(int i=0; i<sdsize; i++)
        {
            Info tinfo = storage_device.front();
            storage_device.pop_front();
            cout << i+1 << ". " << setw(2) << "|" << setw(20) << tinfo.name_storage_device << setw(5) << "|" << setw(20) << tinfo.material_cost << setw(5) << "|";
            cout << setw(20) << tinfo.prod_volume << setw(5) << "|" << endl;
            storage_device.push_back(tinfo);
        }
        cout << sdsize+1 << ". Random" <<endl;


        string snum;
        int s;
        do
        {
            cout << "Choose current storage device or random" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(sdsize+1)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(sdsize+1).length()) || (s == -1) || (snum == "0"));
        num = stoi(snum);

        cout << endl;
        if(num == sdsize+1)
            num = rand()%sdsize + 1;
    }

    if(choce == "1")
    {
        num = rand()%sdsize + 1;
    }

    Info temp = list_products.back();
    list_products.pop_back();
    Info temp1;
    int j = 0;
    for(auto i = storage_device.begin(); i != storage_device.end(); i++)
    {
        if(j<num)
        {
            temp1 = *i;
            j++;
        }
        else
            break;
    }
    temp.name_storage_device = temp1.name_storage_device;
    temp.material_cost = temp.material_cost + temp1.material_cost;
    if(temp.prod_volume > temp1.prod_volume)
        temp.prod_volume = temp1.prod_volume;
    else
        temp.prod_volume = temp.prod_volume;

    list_products.push_back(temp);
    size+=1;
}

void Product::Add(string name_lb, string name_vc, string name_sd, int mat_cost, int volume)
{
    Info tproduct;
    tproduct.name_base = name_lb;
    tproduct.name_videocard = name_vc;
    tproduct.name_storage_device = name_sd;
    tproduct.material_cost = mat_cost;
    tproduct.prod_volume = volume;
    list_products.push_back(tproduct);
    size+=1;
}

void Product::Delete()
{
    string snum;
    int s;
    do
    {
        cout << "Input number of laptop you want to delete (number > 0)" << endl;
        cin >> snum;
        s = snum.length();
        for(int i=0; i<s; i++)
        {
            if((snum[i] > '9') || (snum[i]<'0'))
            {
                s = -1;
                cout << "Incorrect input! Try again" <<endl;
                break;
            }
        }
    }
    while((s > to_string(size).length()) || (s == -1) || (snum == "0"));
    int num = stoi(snum);

    auto i = list_products.begin();
    for(int j = 0; j<num-1; j++)
        i++;
    list_products.erase(i);
    size-=1;
}

void Product::Sort(string choce)
{
    vector<Info> V(size);
    for(int i = 0; i < size; i++)
    {
        Info temp = list_products.front();
        V[i] = temp;
        list_products.pop_front();
    }

    for(int i = 0; i < size; i++)
    {
        for(int j=i+1; j < size; j++)
        {
            int a, b;
            if(choce == "1")
            {
                a = V[i].prod_volume;
                b = V[j].prod_volume;
            }
            if(choce == "2")
            {
                a = V[i].fin_cost;
                b = V[j].fin_cost;
            }

            if(a > b)
            {
                Swap(V[i], V[j]);
            }
        }
    }

    for(int i=0; i<size; i++)
    {
        Info temp = V[i];
        list_products.push_back(temp);
    }

}

int Product::TotalVolume()
{
    int total_volume = 0;
    for(int i=0; i<size; i++)
    {
        Info tprod = list_products.front();
        list_products.pop_front();
        total_volume += tprod.prod_volume;
        list_products.push_back(tprod);
    }

    return total_volume;
}

int Product::InderectCost()
{
    int total_cost;
    total_cost = salary + rent + other_costs;
    return total_cost;
}

void Product::ProdCost()
{
    int inderect_cost;
    inderect_cost = InderectCost();
    int total_volume;
    total_volume = TotalVolume();

    for(int i=0; i<size; i++)
    {
        Info tprod = list_products.front();
        list_products.pop_front();

        double proc = double(tprod.prod_volume)/double(total_volume);
        tprod.fin_cost = (tprod.material_cost + inderect_cost*proc)/tprod.prod_volume;

        list_products.push_back(tprod);
    }
}

istream& operator>> (istream& in, Product& t)
{
    string str[30];
    ifstream in1("Input_Info.txt");
    if (in1.is_open())
    {
        while (getline(in1, str[t.size]))
        {
            t.size++;
        }
    }
    in1.close();

    t.salary = stoi(str[0]);
    t.rent = stoi(str[1]);
    t.other_costs = stoi(str[2]);

    Info tinfo;

    string tname;
    string tcost;
    string tvolume;

    for(int i=3; i<t.size; i++)
    {
        tname.assign(str[i], 1, str[i].find_first_of(",")-1);
        tcost.assign(str[i], str[i].find_first_of(",")+1, str[i].find_last_of(",")-str[i].find_first_of(",")-1);
        tvolume.assign(str[i], str[i].find_last_of(",")+1, str[i].size() - str[i].find_last_of(","));

        tinfo.material_cost = stoi(tcost);
        tinfo.prod_volume = stoi(tvolume);

        if(str[i][0]=='!')
        {
            tinfo.name_base = tname;
            t.laptop_base.push_back(tinfo);
            t.lbsize++;
        }
        if(str[i][0]=='?')
        {
            tinfo.name_videocard = tname;
            t.videocard.push_back(tinfo);
            t.vcsize++;
        }
        if(str[i][0]=='%')
        {
            tinfo.name_storage_device = tname;
            t.storage_device.push_back(tinfo);
            t.sdsize++;
        }

        tinfo.name_base.clear();
        tinfo.name_videocard.clear();
        tinfo.name_storage_device.clear();
        tname.clear();
        tcost.clear();
        tvolume.clear();
    }

    t.size = 0;
    return in;
}

ostream& operator<< (ostream& out, Product& t)
{
    string for_output;
    cout << setw(110) << setfill('=') << "=" << setfill(' ') <<endl;
    cout << setw(5) << "|" << setw(15) << "Laptop base" << setw(3) << "|";
    cout << setw(20) << "Videocard" << setw(3) << "|";
    cout << setw(15) << "Storage Device" << setw(3) << "|";
    cout << setw(20) << "Cost of materials" << setw(3) << "|";
    cout << setw(20) << "Production volume" << setw(3) << "|" << endl;
    cout << setw(110) << setfill('=') << "=" << setfill(' ') <<endl;
    for(int i=0; i<t.size; i++)
    {
        Info tinfo = t.list_products.front();
        t.list_products.pop_front();
        cout << setw(3) << i+1 << setw(2) << "|" << setw(15) << tinfo.name_base << setw(3) << "|";
        cout << setw(20) << tinfo.name_videocard << setw(3) << "|";
        cout << setw(15) << tinfo.name_storage_device << setw(3) << "|";
        cout << setw(20) << tinfo.material_cost << setw(3) << "|";
        cout << setw(20) << tinfo.prod_volume << setw(3) << "|" << endl;
        for_output = for_output + tinfo.name_base + "," + tinfo.name_videocard + "," + tinfo.name_storage_device + "," + to_string(tinfo.material_cost) + "," + to_string(tinfo.prod_volume) + '\n';
        t.list_products.push_back(tinfo);
    }
    cout << setw(110) << setfill('=') << "=" << setfill(' ') <<endl;
    cout << setw(20) << "Inderect costs" << setw(90) << "|" << endl;
    cout << setw(14) << "Salary:" << setw(10) << t.salary << setw(86) << "|"<<endl;
    cout << setw(14) << "Cost of rent:" << setw(10) << t.rent << setw(86) << "|"<<endl;
    cout << setw(14) << "Other costs:" << setw(10) << t.other_costs << setw(86) << "|"<<endl;
    cout << setw(110) << setfill('=') << "=" << setfill(' ') <<endl;

    ofstream out1;
    out1.open("DataBase.txt");
    out1 << for_output;
    out1.close();

    return out;
}

void Product::PrintResult()
{
    string for_output;
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
    cout << setw(5) << "|" << setw(12) << "Laptop base" << setw(2) << "|";
    cout << setw(17) << "Videocard" << setw(2) << "|";
    cout << setw(15) << "Storage Device" << setw(2) << "|";
    cout << setw(18) << "Cost of materials" << setw(2) << "|";
    cout << setw(18) << "Production volume" << setw(2) << "|";
    cout << setw(24) << "Final cost of 1 product" <<endl;
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
    for(int i=0; i<size; i++)
    {
        Info tinfo = list_products.front();
        list_products.pop_front();
        cout << setw(3) << i+1 << setw(2) << "|" << setw(12) << tinfo.name_base << setw(2) << "|";
        cout << setw(17) << tinfo.name_videocard << setw(2) << "|";
        cout << setw(15) << tinfo.name_storage_device << setw(2) << "|";
        cout << setw(18) << tinfo.material_cost << setw(2) << "|";
        cout << setw(18) << tinfo.prod_volume << setw(2) << "|";
        cout << setw(24) << tinfo.fin_cost <<endl;
        for_output = for_output + tinfo.name_base + ", " + tinfo.name_videocard + ", " + tinfo.name_storage_device + ": " + to_string(tinfo.material_cost) + "   " + to_string(tinfo.prod_volume) + "   " + to_string(tinfo.fin_cost) + '\n';
        list_products.push_back(tinfo);
    }
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
    ofstream out;
    out.open("Result.txt");
    out << for_output;
    out.close();
}

void Product::Search(string choce)
{
    string for_search;
    if(choce == "1")
    {
        for(int i=0; i < lbsize; i++)
        {
            Info tinfo = laptop_base.front();
            laptop_base.pop_front();
            cout << i+1 << ". " << tinfo.name_base << endl;
            laptop_base.push_back(tinfo);
        }

        string snum;
        int s;
        do
        {
            cout << "Choose current laptop base" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(lbsize)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(lbsize).length()) || (s == -1) || (snum == "0"));
        int num = stoi(snum);
        int j=1;
        for(auto i=laptop_base.begin(); i != laptop_base.end(); i++)
        {
            if(j == num)
            {
                Info tinfo = *i;
                for_search = tinfo.name_base;
                break;
            }
            j++;
        }
    }
    if(choce == "2")
    {
        for(int i=0; i < vcsize; i++)
        {
            Info tinfo = videocard.front();
            videocard.pop_front();
            cout << i+1 << ". " << tinfo.name_videocard << endl;
            videocard.push_back(tinfo);
        }

        string snum;
        int s;
        do
        {
            cout << "Choose current videocard" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(vcsize)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(vcsize).length()) || (s == -1) || (snum == "0"));
        int num = stoi(snum);
        int j=1;
        for(auto i = videocard.begin(); i != videocard.end(); i++)
        {
            if(j == num)
            {
                Info tinfo = *i;
                for_search = tinfo.name_videocard;
                break;
            }
            j++;
        }
    }
    if(choce == "3")
    {
        for(int i=0; i < sdsize; i++)
        {
            Info tinfo = storage_device.front();
            storage_device.pop_front();
            cout << i+1 << ". " << tinfo.name_storage_device << endl;
            storage_device.push_back(tinfo);
        }

        string snum;
        int s;
        do
        {
            cout << "Choose current storage device" << endl;
            getline(cin, snum);
            s = snum.length();
            for(int i=0; i<s; i++)
            {
                if((snum[i] > '9') || (snum[i]<'0') || (snum[i] > to_string(sdsize)[i]))
                {
                    s = -1;
                    cout << "Incorrect input! Try again" <<endl;
                    break;
                }
            }
        }
        while((s > to_string(sdsize).length()) || (s == -1) || (snum == "0"));
        int num = stoi(snum);
        int j=1;
        for(auto i = storage_device.begin(); i != storage_device.end(); i++)
        {
            if(j == num)
            {
                Info tinfo = *i;
                for_search = tinfo.name_storage_device;
                break;
            }
            j++;
        }
    }
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
    cout << setw(5) << "|" << setw(12) << "Laptop base" << setw(2) << "|";
    cout << setw(17) << "Videocard" << setw(2) << "|";
    cout << setw(15) << "Storage Device" << setw(2) << "|";
    cout << setw(18) << "Cost of materials" << setw(2) << "|";
    cout << setw(18) << "Production volume" << setw(2) << "|";
    cout << setw(24) << "Final cost of 1 product" <<endl;
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
    for(int i=0, j=1; i<size; i++)
    {
        Info tinfo = list_products.front();
        list_products.pop_front();
        if((choce == "1") && (tinfo.name_base == for_search))
        {
            cout << setw(3) << j << setw(2) << "|" << setw(12) << tinfo.name_base << setw(2) << "|";
            cout << setw(17) << tinfo.name_videocard << setw(2) << "|";
            cout << setw(15) << tinfo.name_storage_device << setw(2) << "|";
            cout << setw(18) << tinfo.material_cost << setw(2) << "|";
            cout << setw(18) << tinfo.prod_volume << setw(2) << "|";
            cout << setw(24) << tinfo.fin_cost <<endl;
            j++;
        }
        if((choce == "2") && (tinfo.name_videocard == for_search))
        {
            cout << setw(3) << j << setw(2) << "|" << setw(12) << tinfo.name_base << setw(2) << "|";
            cout << setw(17) << tinfo.name_videocard << setw(2) << "|";
            cout << setw(15) << tinfo.name_storage_device << setw(2) << "|";
            cout << setw(18) << tinfo.material_cost << setw(2) << "|";
            cout << setw(18) << tinfo.prod_volume << setw(2) << "|";
            cout << setw(24) << tinfo.fin_cost <<endl;
            j++;
        }
        if((choce == "3") && (tinfo.name_storage_device == for_search))
        {
            cout << setw(3) << j << setw(2) << "|" << setw(12) << tinfo.name_base << setw(2) << "|";
            cout << setw(17) << tinfo.name_videocard << setw(2) << "|";
            cout << setw(15) << tinfo.name_storage_device << setw(2) << "|";
            cout << setw(18) << tinfo.material_cost << setw(2) << "|";
            cout << setw(18) << tinfo.prod_volume << setw(2) << "|";
            cout << setw(24) << tinfo.fin_cost <<endl;
            j++;
        }
        list_products.push_back(tinfo);
    }
    cout << setw(120) << setfill('=') << "=" << setfill(' ') <<endl;
}
