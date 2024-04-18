#define __REC_H__

/* Циклический сдвиг числа Num*10 + Dig
  на один разряд вправо (рекурсивная функция).  */
int MakeShift(int Num, int Dig);

/*Функция осуществляет циклический сдвиг
  числа Num на один разряд вправо. */
int Shift(int Num);

/*Возведение целого числа X в натуральную
  степень n. */
int GetPower(int X, int n);

/*Вычисление n! */
int GetFact(int n);

/*Вычисление НОД(X, Y)*/
int GetNOD(int X, int Y);

/* Нахождение количества сочетаний из n по m */
int GetComb(int n, int m);

/*Вычисление n-го члена последовательности Фибоначи. */
int GetFibNum(int n);

/*Нахождение суммы цифр числа Num*/
int GetSum(int Num);

/*Нахождение количества цифр числа Num*/
int GetCount(int Num);

/*Нахождение числа-перевертыша числа Num.*/
int TurnNum(int Num);

/*Вставка i-й цифры справа в число*/
int PasteDig(int Num, int Dig, int i);

/*Удаление i-й цифры справа из числа.*/
int DeleteDig(int Num, int i);

/*Удаление всех цифр Dig из числа. */
int DeleteDigs(int Num, int Dig);

/*Ханойские башни*/
void Move(int n, char x, char y,char z);

/*Сортировка Хоора.*/
void qsort(int a[], int l, int r);

/*Поиск max элемента в массиве.*/
int FindMax (int *a, int i,int n);

/*рекурсивная функция сортировки вставками*/
void rec_sort(int *a, int i, int n);

/*Проверка на симметричность*/
bool IsPalindrome(int* a, int i, int n);

/*Бинарный поиск элемента в упорядоченном массиве*/
int Search_bin(int *a, int l, int r,int x);
