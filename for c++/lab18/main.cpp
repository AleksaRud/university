/*Рудович Александра, 1 курс, пи, фск*/

#include <iostream>
#include "rec.h"
using namespace std;

int main()
{
    int a[] = {1, 5, 6, 2, 4, 3};
    int b[] = {2, 5, 3, 5, 6};
    int c[] = {2, 6, 5, 3, 5, 6, 2};
    int Num = 24, Dig = 3;
    int X = 3, n = 5, Y = 546, m = 4, i = 5;
    int ms, s, gp, gf, nod, comb, fibnum, sum, gc, tn, pd, dg, dg1, Max, palindrome1, palindrome2, k;

    for(int j = 0; j < 6; j++)
        cout << a[j] << "  ";
    cout << endl;
    for(int j = 0; j < 5; j++)
        cout << b[j] << "  ";
    cout << endl;
    for(int j = 0; j < 7; j++)
        cout << c[j] << "  ";
    cout << endl;

    ms = MakeShift(Num, Dig);
    s = Shift(Num);
    gp = GetPower(X, n);
    gf = GetFact(n);
    nod = GetNOD(X, Y);
    comb = GetComb(n, m);
    fibnum = GetFibNum(n);
    sum = GetSum(Num);
    gc = GetCount(Num);
    tn = TurnNum(Num);
    pd = PasteDig(Num, Dig, i);
    dg = DeleteDig(Num, i);
    dg1 = DeleteDigs(Num, Dig);
    Move(n, '2', '3', '5');

    qsort(a, 0, 6);
    for(int j = 0; j < 6; j++)
        cout << a[j] << "  ";
    cout << endl;

    Max = FindMax (a, 0, 6);

    rec_sort(b, 0, 5);
    for(int j = 0; j < 5; j++)
        cout << b[j] << "  ";
    cout << endl;

    palindrome1 = IsPalindrome(a, 0, 6);
    palindrome1 = IsPalindrome(c, 0, 7);
    cout << palindrome1 << endl;
    cout << palindrome2 << endl;
    k = Search_bin(a, 0, 6, 3);
    cout << ms << "  " << s << "  " << gp << "  " << gf << "  " << nod << "  " << comb << "  " << fibnum << endl;
    cout << sum << "  " << gc << "  " << tn << "  " << pd << "  " << dg << "  " << dg1 << "  " << Max << "  " << k << endl;

}
