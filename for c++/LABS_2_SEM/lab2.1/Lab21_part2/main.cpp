/*Рудович Александра, 1 курс, пи, фск
лаб 2.1    часть 2
Разработать свой класс для обработки чисел с констукторами и методами для обработки

2. Многофайловый проект: файл   - основная программа; файл с методами  класса;  заголовочный файл .h*/


#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
#include <string>
#include <iomanip>
#include "func.h"
using namespace std;


int main()
{
    Number N1;
    N1.Input();
    N1.Sum(); N1.Print();
    N1.Comp(); N1.Print();
    N1.Div(); N1.Print();
    N1.Mod(); N1.Print();
    N1.Pov(); N1.Print();

    Number N2;
    N2.Sum(); N2.Print();
    N2.Comp(); N2.Print();
    N2.Div(); N2.Print();
    N2.Mod(); N2.Print();
    N2.Pov(); N2.Print();

    Number N3(12, 5);
    N3.Sum(); N3.Print();
    N2.Comp(); N3.Print();
    N3.Div(); N3.Print();
    N3.Mod(); N3.Print();
    N3.Pov(); N3.Print();

}
