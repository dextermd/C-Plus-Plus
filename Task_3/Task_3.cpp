#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  Задание 3. Написать программу, которая выводит на экран таблицу умножения на k, где k –
    //    номер варианта.Например, для 7 - го варианта :
    //      7 x 2 = 14
    //      7 x 3 = 21
    //      и т.д.


    int n,k = 2;

    cout << "Введите число от 1 до 10: ";
    cin >> n;

    if (n >= 1 && n <= 10)
    {
        while (k >= 1 && k <= 10)
        {
            cout << n << " x " << k << " = " << n * k << endl;
            k++;
        }
    }
    else
        cout << "\nВвели неверное значение!";




    _getch();
}