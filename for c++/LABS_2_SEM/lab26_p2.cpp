/* Рудович Александра, 1 курс, пи, фск

лаб 2.6
Разработать класс массив и класс матриц для решения своих заданий 1 семестра используя перегрузка операторов
Лабораторные 3 и 4
Использовать исключения!!!

11.	Найти номера строк заданной матрицы A=(aij) ,  i=1..n, j=1..m, n,m<=100, в которых есть наибольший и наименьший  элементы.

*/


#include <iostream>
#include <time.h>
#include <iomanip>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
using namespace std;


class Matrix
{
private:
    int n, m; // размерности матрицы
    int** Matr; // указатель на матрицу
    int* n_min;
    int* n_max;
    int max_, min_;
public:
    Matrix();
    Matrix(int n1, int m1);
    Matrix(const Matrix& p);
    ~Matrix();
    friend istream& operator>>(istream& in, Matrix& p);
    friend ostream& operator<<(ostream& out, Matrix& p);
    friend void Max(Matrix& p);
    friend void Min(Matrix& p);
    friend void MinLn(Matrix& p);
    friend void MaxLn(Matrix& p);
    friend void MinMaxLn(Matrix& p);
    friend void Solve(Matrix& p);
};

Matrix::Matrix()
{
    n = 0; m = 0;
    Matr = NULL;
    n_max = NULL;
    n_min = NULL;
};

Matrix::Matrix(int n1, int m1)
{
    if(n1>100 || m1>100 || n1<0 || m1<0) throw "Out of range";
    n = n1; m = m1;
    //генерируем массив(случайные значения)
    Matr = new int* [n];
    n_max = new int [n];
    n_min = new int [n];
    for (int i = 0; i < n; i++)
        Matr[i] = new int[m];

    srand(time(0));
    int t, q;
    cout << "Elements will be large numbers or not? (1 - yes, 0 - no)" << endl;
    do
    {
        cin >> t;
    }
    while(t!=0 && t!=1);
    if( t == 1)
        q = 100;
    else
        q = 10;
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
            Matr[i][j] = rand() % q;
};

Matrix::Matrix(const Matrix& p)
{
    n = p.n;
    m = p.m;
    for ( int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
            Matr[i][j] = p.Matr[i][j];
};

Matrix::~Matrix()
{
    for (int i=0; i<n; i++)
        delete[]Matr[i];
    delete[]Matr;
    delete[]n_min;
    delete[]n_max;
};

istream& operator>>(istream& in, Matrix& p)
{
    for (int i=0; i<p.n; i++)
        delete p.Matr[i];
    delete p.Matr;

    cout << "Input matrix" << endl;
    for ( int i = 0; i < p.n; i++)
        for (int j = 0; j < p.m; j++)
            in >> p.Matr[i][j];

    return in;
};

ostream& operator<< (ostream& out, Matrix& p)
{
    out << " matrix " << endl;
    for (int i = 0; i < p.n; i++)
    {
        for (int j = 0; j < p.m; j++)
            out <<setw(4) << p.Matr[i][j] << setw(4);
        out << endl;
    }
    return out;
};
//находим значение наибольших элементов массива
void Max( Matrix& p)
{
    p.max_ = p. Matr[0][0];
    for ( int i = 0; i < p.n; i++ )
        for ( int j = 0; j < p.m; j++)
            if ( p.Matr[i][j] >= p.max_)
                p.max_ = p.Matr[i][j];
};

//находим значение наименьших элементов массива
void Min(Matrix& p)
{
    p.min_ = p.Matr[0][0];
    for ( int i = 0; i < p.n; i++ )
        for ( int j = 0; j < p.m; j++)
            if ( p.Matr[i][j] <= p.min_)
                p.min_ = p.Matr[i][j];
};


//выводим номера строк с min значением(если в строке таких значений несколько, то номер выводим один раз)
void MinLn(Matrix& p)
{
    int c_min = 0;
    for ( int i = 0; i < p.n; i++ )
        for ( int j = 0; j < p.m; j++)
        {
            if ( p.Matr[i][j] == p.min_)
            {
                p.n_min[i] = 1;
                cout << i << setw(3);
                c_min++;
                if (c_min > 0)
                    break;
            }
            else
                p.n_min[i] = 0;
        }
    cout<<endl;
};

    //выводим номера строк с max значением(если в строке таких значений несколько, то номер выводим один раз)
void MaxLn(Matrix& p)
{
    int c_max = 0;

    for (int i = 0; i < p.n; i++ )
        for ( int j = 0; j < p.m; j++)
        {
            if ( p.Matr[i][j] == p.max_)
            {
                p.n_max[i] = 1;
                cout << i << setw(3);
                c_max++;
                if (c_max > 0)
                    break;
            }
            else
                p.n_max[i] = 0;
        }
    cout << endl;
};

    //выводим номера строк с наибольшим и наименьшим элементами
void MinMaxLn (Matrix& p)
{
    int g = 0;
    cout << "min and max are in this line(lines): ";
    for ( int i = 0; i < p.n; i++)
        if ( p.n_min[i] == p.n_max[i] && p.n_min[i] > 0)
        {
            g++;
            cout << i << setw(3);
        }

    if ( g == 0 )
        cout << "there are not such lines" << endl;
};

void Solve(Matrix& p)
{
    Max(p); Min(p);
    cout<< "Min are in these lines: ";
    MinLn(p);
    cout<< "Max are in these lines: ";
    MaxLn(p);
    MinMaxLn(p);
    cout << endl;
};

int main()
{
    try
    {
        Matrix MA(10, 10);
        cout << MA;
        Solve(MA);
    }
    catch(const char* s)
    {
        cout << "Error: " << s << endl;
    }
}

