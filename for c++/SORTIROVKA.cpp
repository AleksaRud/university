

#include <iostream>
using namespace std;

int* mass(int* A, int n)
{
    for(int i=0; i<n; i++)
        A[i] = rand() % 100;
    return A;
}

void swapNumbers(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void sortMass(int* A, int n)
{
    for(int i=0; i<n; i++)
        for(int j = i + 1; j<n; j++)
            if(A[i]>A[j])
                swapNumbers(A[i], A[j]);
}
void print_mass(int* A, int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << "  ";
    cout << endl;
}
int main()
{
    int* A;
    int n;
    cin >> n;
    cout<<endl;
    A = new int [n];
    A = mass(A, n);
    print_mass(A, n);
    sortMass(A, n);
    print_mass(A, n);
}
