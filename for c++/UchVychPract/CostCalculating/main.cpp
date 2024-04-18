//Рудович Александра, пи, 1 курс
//Создание автоматизированной системы для расчета себестоимости оборудования

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include <vector>
#include "func.h"

using namespace std;

string Choce()
{
    string choce;
    int s;
    do
    {
        getline(cin, choce);
        s = choce.length();
        if((s != 1) || (choce[0] < '0') || (choce[0] > '9'))
            cout << "Incorrect input! Try again" << endl;
    }
    while((s != 1) || (choce[0] < '0') || (choce[0] > '9'));
    return choce;
}

void MainMenu()
{
    cout << setw(20) << "Menu" << endl;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << "1. Create new list of laptops" << endl;
    cout << "Input 0 or 1" << endl;
}
void CreatingList(Product& P, string& choce)
{
    if(choce == "1")
    {
        choce.clear();
        cout << setw(60) << "Creating list" << endl;
        cout << endl;
        cout << "Adding new laptop to the list" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "1. Generate 1 random laptop" << endl;
        cout << "2. Choose from list" << endl;
        cout << "3. Add my own" << endl;
        cout << "4. Add some random laptops" << endl;
        cout << "Input 0, 1, 2, 3 or 4" << endl;

        do
        {
            choce = Choce();
            if((choce != "0") &&(choce != "1") && (choce != "2")&&(choce != "3")&& (choce != "4"))
                cout << "Incorrect input! Try again" << endl;
        }
        while((choce != "0") &&(choce != "1") && (choce != "2")&&(choce != "3")&& (choce != "4"));

        if(choce == "4")
        {

            int s;
            string snum;
            int num;
            do
            {
                cout << "Input the size of list" << endl;
                getline(cin, snum);
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
            while((s == -1) || (snum == "0"));
            num = stoi(snum);
            for(int i = 0; i < num; i++)
            {
                P.ChooseBase("1");
                P.ChooseVideocard("1");
                P.ChooseStorageDevice("1");
            }
        }


        if((choce == "1") || (choce == "2") || (choce == "3"))
        {
            do
            {
                if(choce == "3")
                {
                    string name_lb;
                    cout << "Input laptop base" << endl;
                    cin >> name_lb;
                    cout << endl;

                    string name_vc;
                    cout << "Input videocard" << endl;
                    cin >> name_vc;
                    cout << endl;

                    string name_sd;
                    cout << "Input storage device" << endl;
                    cin >> name_sd;
                    cout << endl;

                    cin.ignore(32767, '\n');
                    int s;
                    string scost;
                    int cost;
                    do
                    {
                        cout << "Input cost of materials" << endl;
                        getline(cin, scost);
                        s = scost.length();
                        for(int i=0; i<s; i++)
                        {
                            if((scost[i] > '9') || (scost[i]<'0'))
                            {
                                s = -1;
                                cout << "Incorrect input! Try again" <<endl;
                                break;
                            }
                        }
                    }
                    while((s == -1) || (scost == "0"));
                    cost = stoi(scost);
                    cout << endl;

                    int volume;
                    string svolume;
                    do
                    {
                        cout << "Input production volume" << endl;
                        getline(cin, svolume);
                        s = svolume.length();
                        for(int i=0; i<s; i++)
                        {
                            if((svolume[i] > '9') || (svolume[i]<'0'))
                            {
                                s = -1;
                                cout << "Incorrect input! Try again" <<endl;
                                break;
                            }
                        }
                    }
                    while((s == -1) || (svolume == "0"));
                    volume = stoi(svolume);
                    cout << endl;

                    P.Add(name_lb, name_vc, name_sd, cost, volume);
                    system("cls");
                }
                if(choce == "1" || choce == "2")
                {
                    P.ChooseBase(choce);
                    P.ChooseVideocard(choce);
                    P.ChooseStorageDevice(choce);
                    system("cls");
                }

                cout << setw(60) << "Creating list" << endl;
                cout << endl;
                cout << "Adding new laptop to the list" << endl;
                cout << "0. Back to main menu" << endl;
                cout << "1. Generate random" << endl;
                cout << "2. Choose from list" << endl;
                cout << "3. Add my own" << endl;
                cout << "4. Show the generated list" << endl;
                cout << "Input 0, 1, 2, 3 or 4" << endl;
                choce.clear();

                do
                {
                    choce = Choce();
                    if((choce != "0") &&(choce != "1") && (choce != "2")&&(choce != "3") && (choce != "4"))
                        cout << "Incorrect input! Try again" << endl;
                }
                while((choce != "0") &&(choce != "1") && (choce != "2")&&(choce != "3") && (choce != "4"));
            }
            while((choce != "4") && (choce != "0"));
        }

    }
}

int main()
{
    Product Prod;
    cin >> Prod;
    string ch;
    MainMenu();
    do
    {
        ch = Choce();
        if((ch != "0") && (ch != "1"))
            cout << "Incorrect input! Try again" << endl;
    }
    while((ch != "0") && (ch != "1"));

    system("cls");
    if(ch == "0")
    {
        cout << "Press any key to close the window" << endl;
        cout << endl;
        return 0;
    }

    CreatingList(Prod, ch);

    if(ch == "4")
    {
        system("cls");

        cout << setw(60) << "List of laptops" << endl;
        cout << Prod;
        cout << endl;
        cout << "Press any button to continue" << endl;

        do
        {
            cin.ignore(32767, '\n');
            cout << "Do you want to change the list?" << endl;
            cout << "1. Add another laptop" << endl;
            cout << "2. Delete one laptop" << endl;
            cout << "3. Continue" << endl;
            cout << "Input 1, 2 or 3" << endl;

            do
            {
                ch.clear();
                ch = Choce();
                if((ch != "1") && (ch != "2") && (ch != "3"))
                    cout << "Incorrect input! Try again" << endl;
            }
            while((ch != "1") && (ch != "2")&& (ch != "3"));

            if(ch == "2")
            {
                Prod.Delete();
                system("cls");
                cout << Prod;
                cout << endl;
                cout << endl;
            }

            if(ch == "1")
            {
                system("cls");
                CreatingList(Prod, ch);
                system("cls");
                cout << setw(60) << "List of laptops" << endl;
                cout << Prod;
                cout << endl;
                cout << "Press any button to continue" << endl;
            }

        }
        while(ch != "3");
        system("cls");
        Prod.ProdCost();
        do
        {

            Prod.PrintResult();

            cout << endl;
            cout << setw(60) << "Options" << endl;
            cout << "0. Back to menu" << endl;
            cout << "1. Sort by volume" << endl;
            cout << "2. Sort by final cost of 1 product" << endl;
            cout << "3. Search by criterion" << endl;
            cout << "4. Exit" << endl;
            cout << "Input 0, 1, 2, 3 or 4" << endl;

            ch.clear();
            do
            {
                ch = Choce();
                if((ch != "0") &&(ch != "1") && (ch != "2") && (ch != "3") && (ch != "4"))
                    cout << "Incorrect input! Try again" << endl;
            }
            while((ch != "0") &&(ch != "1") && (ch != "2") && (ch != "3") && (ch != "4"));

            system("cls");
            if((ch == "1") || (ch == "2"))
            {
                Prod.Sort(ch);
                Prod.PrintResult();
            }
            if(ch == "3")
            {
                cout << "Choose the criterion" << endl;
                cout << "1. Laptop base" << endl;
                cout << "2. Videocard" << endl;
                cout << "3. Storage device" << endl;
                ch.clear();
                do
                {
                    ch = Choce();
                    if((ch != "0") &&(ch != "1") && (ch != "2") && (ch != "3"))
                        cout << "Incorrect input! Try again" << endl;
                }
                while((ch != "0") &&(ch != "1") && (ch != "2") && (ch != "3"));
                system("cls");
                Prod.Search(ch);
            }
            cout << "Press any button to continue" << endl;
            cin.ignore(32767, '\n');
            system("cls");
        }
        while(ch != "4");


        if(ch == "4")
        {
            cout << "Are you sure go exit? Please save file with your list of laptops, if you don't want to lose it" << endl;
            cout << "1. Save file" << endl;
            cout << "2. I don't need it. Continue" << endl;
            ch.clear();
            do
            {
                ch = Choce();
                if((ch != "1") && (ch != "2"))
                    cout << "Incorrect input! Try again" << endl;
            }
            while((ch != "1") && (ch != "2"));
            system("cls");

            if(ch == "1")
            {
                cout << setw(60) << "Your list" << endl;
                cout << endl;
                Prod.PrintResult();
                cout << "Copy file 'Result.txt' to another folder and after that continue" << endl;
            }

            return 0;
        }
    }

    if(ch == "0")
    {
        cout << "Are you sure go back? Please save file with your list of laptops, if you don't want to lose it" << endl;
        cout << "1. Save file" << endl;
        cout << "2. I don't need it. Continue" << endl;
        ch.clear();
        do
        {
            ch = Choce();
            if((ch != "1") && (ch != "2"))
                cout << "Incorrect input! Try again" << endl;
        }
        while((ch != "1") && (ch != "2"));
        system("cls");

        if(ch == "1")
        {
            cout << setw(60) << "Your list" << endl;
            cout << endl;
            Prod.PrintResult();
            cout << "Copy file 'Result.txt' to another folder and after that continue" << endl;
        }
        system("cls");

        main();
    }
}
