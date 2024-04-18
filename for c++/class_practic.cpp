#include <iostream>

using namespace std;


class Number
{
    int a, b, c;
public:
    Number()
    {
        a = 10; b = 5;
    }
    Number(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    Input();
    int Solve();
    Print();
};

Number::Input()
{
    cout<<"a and b"<<endl;
    cin>>a>>b;
}

int Number::Solve()
{
    c = a + b;
}

Number::Print()
{
    cout<<a<<'\t'<<b<<'\t'<<c<<endl;
}

int main()
{
    Number N1;
    N1.Input();
    N1.Solve();
    N1.Print();

    Number N2;
    N2.Solve();
    N2.Print();

    Number N3(123, 345);
    N3.Solve();
    N3.Print();
}
