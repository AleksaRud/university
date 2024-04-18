/*Рудович Александра, 1 курс, пи, фск
*/


#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
using namespace std;


bool isANumber(char c)
{
    if('0' <= c && c <= '9')
        return true;
    else return false;
}

bool isFullNumber(string str)
{
    bool iFN = true;
    for(int i=0; i<str.size(); i++)
        iFN = iFN && isANumber(str[i]);
    return iFN;
}

int numberOfWords(string str)
{
    int m=0;
    for(int i=1; i<str.size(); i++)
    {
        if(str[i]==' ') continue;
        if(str[i-1]== ' ') m++;
    }
    //cout <<"number of words = " << m << endl;
    return m;
}

int firstChet(int a[], int n)
{
    for(int i = 0; i < n; i++)
        if( a[i] % 2 == 0)
            return i;
    return (-1);
}

int lastNechet(int a[], int n)
{
    for(int i = n; i > 0; i--)
        if( a[i] % 2 != 0)
            return i;
    return (-1);
}

int proisvZifr(int a)
{
    int P = 1;
    while( a!=0 )
    {
        P *= (a % 10);
        a = a / 10;
    }
    return P;
}

int sumStolbik(int **a, int n, int m)
{
    int S = 0;
    for (int i = 0; i < n; i++)
        S += a[i][m-1];
    return S;
}

int main()
{
    string str, space = " ";

    ifstream in("Input.txt");
    if (in.is_open())
    {
        while (getline(in, str))
        {
            cout << str  <<endl;
        }
    }
    in.close();

    for(int i=0; i<str.size(); i++)
        if (str[i]==' '||str[i]==','||str[i]=='.'||str[i]==':'||str[i]=='+'||str[i]==';')
            str[i] = ' ';

    if (str[0] != ' ') str.insert(0, space);

    int n = numberOfWords(str);

    string str_[n];
    for(int i=0,k=0; i<str.size(); )
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        int word_len=1;
        int j;
        for(j=i+1; j<str.size() && str[j]!=' '; j++)
        {
            word_len++;
        }

        string s(str, i, word_len);
        str_[k] = s;
        s.clear();
        i = j;
        k++;
    }

    string numbers[n];
    int k=0;
    for(int i = 0; i < n; i++)
    {
        if(isFullNumber(str_[i]))
            numbers[k++] = str_[i];
    }

    string for_output = numbers[0];
    for(int i = 1; i < n; i++)
        for_output = for_output + " " + numbers[i];

    ofstream out1;
    out1.open("Output.txt");
    if (out1.is_open())
    {
        out1 << for_output + '\n' << endl;
    }
    out1.close();
    for_output.clear();



    int* DArray = 0;
    DArray = new int [k];

    for(int i = 0; i < k; i++)
    {
        DArray[i] = stoi(numbers[i]);
        cout<<DArray[i]<< "  ";
    }

    int is_chet = firstChet(DArray, k);
    int is_nochet = lastNechet(DArray, k);
    int Chet, NoChet;
    if(is_chet == -1)
        for_output = "There are no chet";
    else
    {
        Chet = DArray[is_chet];
        for_output = to_string(Chet);
    }

    if(is_nochet == -1)
        for_output = for_output + "   " +  "There are no nechet";
    else
    {
        NoChet = DArray[is_nochet];
        for_output = for_output + "   " +  to_string(NoChet);
    }


    ofstream out2;
    out2.open("Output.txt", ios::app);
    if (out2.is_open())
    {
        out2 << for_output + '\n' << endl;
    }
    out2.close();
    for_output.clear();


    int m;
    if(is_chet == -1)
        m = is_nochet + 1;
    else
    {
       m = (is_nochet > is_chet)? (is_nochet - is_chet - 1) : (is_chet - is_nochet - 1);
    }

    if(is_nochet == -1)
        m = k - is_chet - 1;
    else
    {
        m = (is_nochet > is_chet)? (is_nochet - is_chet  - 1) : (is_chet - is_nochet - 1);
    }


    int** Matr = 0;
    Matr = new int *[m];
    for (int i=0; i<m;i++)
        Matr[i]= new int [3];

    for_output = "Count of numbers between Chet and NoChet:  " + to_string(m);
    ofstream out3;
    out3.open("Output.txt", ios::app);
    if (out3.is_open())
    {
        out3 << for_output + '\n' << endl;
    }
    out3.close();
    for_output.clear();
    cout<<endl;

    for(int i = 0, j =(is_nochet > is_chet)? (is_chet + 1) : (is_nochet + 1) ; i < m; i++, j++)
    {
        Matr[i][0] = DArray[j];
        Matr[i][1] = (is_nochet > is_chet)? (i + is_chet + 1) : ( i+ is_nochet + 1);
        Matr[i][2] = proisvZifr(Matr[i][0]);

        for_output = for_output + to_string(Matr[i][0]) + '\t' + to_string(Matr[i][1]) + '\t' + to_string(Matr[i][2]) + '\n';
        cout <<setw(10) << Matr[i][0] << setw(5) << Matr[i][1] << setw(5) << Matr[i][2] << endl ;
    }

    ofstream out4;
    out4.open("Output.txt", ios::app);
    if (out4.is_open())
    {
        out4 << for_output + '\n' << endl;
    }
    out4.close();
    for_output.clear();
    cout<<endl;

    int x;
    do
    {
        cout << "input 1<=x<= 3" << endl;
        cout << "x = ";
        cin >> x;
    }
    while ( x > 3);

    int Sum = sumStolbik(Matr, m, x);
    cout << Sum;

    for_output = "Sum of " + to_string(x) + " stolbik = " + to_string(Sum);

    ofstream out5;
    out5.open("Output.txt", ios::app);
    if (out5.is_open())
    {
        out5 << for_output + '\n' << endl;
    }
    out5.close();
    for_output.clear();
    cout<<endl;

    cout << "End of program" << endl;
}
