#include "CalcFunc.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include <vector>

void Swap(Info& a, Info& b)
{
    Info temp;
    temp = a;
    a = b;
    b = temp;
}

Product::Product()
{
    size = 0;
    prsize = 0;
    vcsize = 0;
    sdsize = 0;
}

Product::~Product()
{
    list_products.erase(list_products.begin(), list_products.end());
    size = 0;
}

void Product::ChooseProcessor(int num)
{
    Info temp;
    int j = 0;
    for(auto i = processor.begin(); i != processor.end(); i++)
    {
        if(j<=num)
        {
            temp = *i;
            j++;
        }
        else
            break;
    }

    list_products.push_back(temp);
}

void Product::ChooseVideocard(int num)
{
    Info temp = list_products.back();
    list_products.pop_back();
    Info temp1;

    int j = 0;
    for(auto i = videocard.begin() ; i != videocard.end(); i++)
    {
        if(j<=num)
        {
            temp1 = *i;
            j++;
        }
        else
            break;
    }

    temp.name_videocard = temp1.name_videocard;
    temp.material_cost = temp.material_cost + temp1.material_cost;
    if(temp.prod_amount > temp1.prod_amount)
        temp.prod_amount = temp1.prod_amount;
    else
        temp.prod_amount = temp.prod_amount;

    list_products.push_back(temp);
}

void Product::ChooseStorageDevice(int num)
{
    Info temp = list_products.back();
    list_products.pop_back();
    Info temp1;
    int j = 0;
    for(auto i = storage_device.begin(); i != storage_device.end(); i++)
    {
        if(j<=num)
        {
            temp1 = *i;
            j++;
        }
        else
            break;
    }
    temp.name_storage_device = temp1.name_storage_device;
    temp.material_cost = temp.material_cost + temp1.material_cost;
    if(temp.prod_amount > temp1.prod_amount)
        temp.prod_amount = temp1.prod_amount;
    else
        temp.prod_amount = temp.prod_amount;

    list_products.push_back(temp);
    size+=1;
}

void Product::Add(string name_pr, string name_vc, string name_sd, int mat_cost, int amount)
{
    Info tproduct;
    tproduct.name_proc = name_pr;
    tproduct.name_videocard = name_vc;
    tproduct.name_storage_device = name_sd;
    tproduct.material_cost = mat_cost;
    tproduct.prod_amount = amount;
    list_products.push_back(tproduct);
    size+=1;
}

void Product::Delete(int num)
{
    auto i = list_products.begin();
    for(int j = 0; j<num; j++)
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
            if(choce == "1") //by amount
            {
                a = V[i].prod_amount;
                b = V[j].prod_amount;
            }
            if(choce == "2") //by final cost of 1 item
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

void Product::ProdCost()
{
    for(int i=0; i<size; i++)
    {
        Info tprod = list_products.front();
        list_products.pop_front();
        tprod.fin_cost = tprod.material_cost/tprod.prod_amount;

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

    Info tinfo;

    string tname;
    string tcost;
    string tamount;

    for(int i=0; i<t.size; i++)
    {
        tname.assign(str[i], 1, str[i].find_first_of(",")-1);
        tcost.assign(str[i], str[i].find_first_of(",")+1, str[i].find_last_of(",")-str[i].find_first_of(",")-1);
        tamount.assign(str[i], str[i].find_last_of(",")+1, str[i].size() - str[i].find_last_of(","));

        tinfo.material_cost = stoi(tcost);
        tinfo.prod_amount = stoi(tamount);

        if(str[i][0]=='!') //processors
        {
            tinfo.name_proc = tname;
            t.processor.push_back(tinfo);
            t.prsize++;
        }
        if(str[i][0]=='?') //videocards
        {
            tinfo.name_videocard = tname;
            t.videocard.push_back(tinfo);
            t.vcsize++;
        }
        if(str[i][0]=='%') //storage devices
        {
            tinfo.name_storage_device = tname;
            t.storage_device.push_back(tinfo);
            t.sdsize++;
        }

        tinfo.name_proc.clear();
        tinfo.name_videocard.clear();
        tinfo.name_storage_device.clear();
        tname.clear();
        tcost.clear();
        tamount.clear();
    }

    t.size = 0;
    return in;
}

void Product::Save(string file_name)
{
    string for_output;

    for(int i=0; i<size; i++)
    {
        Info tinfo = list_products.front();
        list_products.pop_front();

        for_output = for_output + tinfo.name_proc + ", "
                    + tinfo.name_videocard + ", " + tinfo.name_storage_device + ": "
                    + to_string(tinfo.material_cost) + "   " + to_string(tinfo.prod_amount) + "   "
                    + to_string(tinfo.fin_cost) + '\n';
        list_products.push_back(tinfo);
    }

    file_name = file_name + ".txt";
    ofstream out;
    out.open(file_name);
    out << for_output;
    out.close();
}
