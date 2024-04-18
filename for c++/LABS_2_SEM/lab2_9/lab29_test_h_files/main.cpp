#include <iostream>
#include <iomanip>
#include "list.h"
#include <fstream>
using namespace std;

int main()
{
    List<int> L;
    int N, M;
    cout<<"Input N  M"<<endl;
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        L.push_back(i);
    L.print();


    int n=N;
    while(n>1)
    {
        for(int i=0; i<M-1; i++)
        {
            int a = L.pop_front();
            L.push_back(a);
        }
        L.pop_front();
        L.print();
        n--;
    }
    int a = L.pop_front();
    string str = to_string(a);
    ofstream out;
    out.open("Result_iosif.txt");
    if (out.is_open())
    {
        out << str << endl;
    }
    out.close();
    cout << "End of program" << endl;
}
