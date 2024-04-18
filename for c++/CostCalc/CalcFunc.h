#define CALCFUNC_H
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
    string name_proc;
    string name_videocard;
    string name_storage_device;
    int material_cost;
    int prod_amount;
    int fin_cost;
};

class Product
{
public:
    list<Info> processor;
    int prsize;
    list<Info> videocard;
    int vcsize;
    list<Info> storage_device;
    int sdsize;

    list<Info> list_products;
    int size;

    Product();
    ~Product();
    void ChooseProcessor(int num);
    void ChooseVideocard(int num);
    void ChooseStorageDevice(int num);
    void Add(string name_pr, string name_vc, string name_sd, int mat_cost, int amount);
    void Delete(int num);
    void Sort(string choce);
    void ProdCost();

    friend istream& operator>> (istream& in, Product& t);
    void Save(string file_name);
};

