//Рудович Александра, 1 курс, пи



#include <iostream>
using namespace std;
template <class T>
class DynArray

{
    T* arr;
    int n;
public:
    DynArray(int count);
    DynArray(T *a, int k);
    DynArray(const DynArray& Ar);

    ~DynArray();
    friend istream& operator>>(istream& in, DynArray<T>& p)
    {
        for(int i=0; i<p.n; i++)
            in>>p.arr[i];
        return in;
    }
    friend ostream& operator<< (ostream& out, DynArray<T>& p)
    {
        for(int i=0; i<p.n; i++)
            out<< p.arr[i] << "  ";
        out << endl;
        return out;
    }
    DynArray& append(const DynArray<T>& Ar);
    int SumArray();
    void SumItems1(DynArray<T>& Ar, int k);
    void SumItems0(int k);
    DynArray& SumItems( DynArray<T>& Ar, int k);
    int SumElements();

};


template <class T>
DynArray<T>::DynArray(int count)
{
    n = count;
    arr = new T[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
}


template <class T>
DynArray<T>::DynArray(T* a, int k)

{
    arr = a;
    n = k;
}
template <class T>
DynArray<T>::DynArray(const DynArray<T>& Ar)
{
    n = Ar.n;
        arr = new T[n];
    for (int i = 0; i < n; i++)
        arr[i] = Ar.arr[i];
}

template <class T>
DynArray<T>::~DynArray() {
    delete[] arr;
}

template <class T>
DynArray<T>& DynArray<T>::append( const DynArray<T>& Ar) {

    int* tmp = new  int[n + Ar.n];
    int i;
    for (i = 0; i < n; i++)

        tmp[i] = arr[i];
    for (i = 0; i < Ar.n; i++)
        tmp[n + i] = Ar.arr[i];
    delete[] arr;
    arr = tmp;
    n += Ar.n;
    return  *this;
}
template <class T>
int DynArray<T>::SumArray()
{
    int s = 0;
    for (int m = 0; m < n; m++)
        s += arr[m];
    return s;
}

template <class T>
void DynArray<T>::SumItems1(DynArray<T>& Ar, int k)
{
    DynArray <T> Tmp(n);
    for (int m = 0; m < n; m++)
      Ar.arr[m] = Ar.arr[m] + k;
   }

template <class T>
DynArray<T>& DynArray<T>::SumItems(DynArray<T>& Ar, int k)
{
    int* tmp = new int[n];

    for (int m = 0; m < n; m++)
        tmp[m] = Ar.arr[m] + k;
    delete[] arr;
    arr = tmp;
    n = Ar.n;
    return *this;
}

template <class T>
void DynArray<T>::SumItems0(int k)
{
    for (int m = 0; m < n; m++)
        arr[m] = arr[m] + k;
}

template <class T>
int DynArray<T>::SumElements()
{
    int S=0;
    for(int i=0; i<n; i++)
        S+=arr[i];
    return S;
}


int main() {
    DynArray <int> Ar1(5);
    DynArray <int> Ar2(3);
    DynArray <int> Ar3(5);
    cin>>Ar2;
    int s;
    cout<<Ar1<<Ar2;
    int S;
    S = Ar1.SumElements();
    cout<<S<<endl;
    Ar1.append(Ar2);
    cout<<Ar1;
    s   = Ar1.SumArray();
    cout << "s=" << s<<endl;
    Ar3=Ar1.SumItems(Ar1, 10);
    cout << Ar3;
    Ar2.SumItems1(Ar2, 10);
    cout << Ar3;
    Ar1.SumItems0(100);
    cout << Ar3;
    system("pause");
    return 0;
}

