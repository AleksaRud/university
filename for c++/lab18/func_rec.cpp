#include <iostream>
using namespace std;

int MakeShift(int Num, int Dig)
{
  if (Num == 0)
    return Dig;
  else
    return(Num / 10 + 10 * MakeShift(Num / 10, Dig));
}

int Shift(int Num)
{
  return(MakeShift(Num / 10, Num % 10));
}

int GetPower(int X, int n)
{
    if  (n == 0)
        return 1;
    else
        return( X * GetPower(X, n - 1));
}

int GetFact(int n)
{
    if  (n == 0)
        return 1;
    else
        return(n*GetFact(n - 1));
}

int GetNOD(int X, int Y)
{
    if (X == Y)
        return X;
    else
        if  (X > Y)
            return(GetNOD(X - Y, Y));
        else
            return(GetNOD(X, Y - X));
}

int GetComb(int n, int m)
{
    if (m == 1)
        return n;
    else
        return(GetComb(n, m - 1)*(n - m + 1) / m);
}

int GetFibNum(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
    else
        return( GetFibNum(n - 1) + GetFibNum(n - 2));
}

int GetSum(int Num)
{
    if (Num == 0)
        return 0;
    else
        return(Num % 10 + GetSum(Num / 10));
}

int GetCount(int Num)
{
    if (Num == 0)
        return 0;
    else
        return(1 + GetCount(Num / 10));
}

int TurnNum(int Num)
{
    if (Num == 0)
        return 0;
    else
        return( GetPower(10, GetCount(Num / 10))*(Num % 10) + TurnNum(Num / 10));
}

int PasteDig(int Num, int Dig, int i)
{
    if (Num == 0)
        return 0;
    else
        if (i == 1)
            return(Dig + 10*PasteDig(Num / 10, Dig, i - 1));
        else
            return(Num % 10 + 10*PasteDig(Num / 10, Dig, i - 1));
}

int DeleteDig(int Num, int i)
{
    if (Num == 0)
        return 0;
    else
        if (i == 1)
            return(DeleteDig(Num / 10, i - 1));
        else
            return(Num % 10 + 10*DeleteDig(Num / 10, i - 1));
}

int DeleteDigs(int Num, int Dig)
{
    if  (Num == 0)
        return 0;
    else
        if (Num % 10 == Dig)
            return(DeleteDigs(Num / 10, Dig));
        else
            return(Num % 10 + 10*DeleteDigs(Num / 10, Dig));
}

void Move(int n, char x, char y,char z)
//х - А y - В  z - C
{ if (n==1)  cout<<" disc 1" <<x<<" ->"<<y;
     else
        if (n>1)
        {
            Move(n-1,x,z,y);
            cout<<"disc"<<n<<x<<" ->"<<y;
            Move(n-1,z,y,x);
        }
}

void qsort(int a[], int l, int r)
{	// сортировка Хоара
		int i = l, j = r, p;
	int x = a[(l + r)/2];
	while (i <= j)
	{
		while (a[i] < x)
			++i;
		while (x < a[j])
			--j;
        if (i <= j)
        {
            p = a[i];
            a[i] = a[j];
            a[j] = p;
            i++;
            j--;
        }
    }
	if (l < j)		qsort(a, l, j);
	if (i < r)		qsort(a, i, r);
}

int FindMax (int *a, int i,int n)
{
    int Max;
	if (i==n) return  a[i];
    else
        if ( Max > FindMax(a,i+1, n) && (i==n))
            Max = a[i];
        else Max = FindMax(a,i+1,n);
}


void rec_sort(int *a, int i, int n)
// рекурсивная функция сортировки вставками
{
    if (i < n)
    {
        int max = a[i], ind = i;
		for (int j = i; j < n; ++j)
			if (a[j] > max)
			{
			    max = a[j];
				ind = j;
            }
        if (ind > i)
        {
            a[i] ^= a[ind];
            a[ind] ^= a[i];
            a[i] ^= a[ind];
        }

		rec_sort(a, i+1, n);
	}
}

bool IsPalindrome(int* a, int i, int n)
{
    if (a[i] == a[n-i])
        if ((i == n) || (n - i == 1))
            return true;
        else
            return IsPalindrome(a, i + 1, n - 1);
    else
        return false;
}

int Search_bin(int *a, int l, int r, int x)
{
    int k,p,i,j;
    k= (l+r) / 2;
    if   (a[k]==x)   return k;
    else
    {
        if  (a[k] <=x)
            l=k+1;
        else r=k-1;
        return Search_bin (a,l,r,x);
    }
 }
