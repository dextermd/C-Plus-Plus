#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  Задание 5. Посчитать количество целых чисел в диапазоне от 100 до 999, у которых все цифры
    //    разные.Вывести на экран эти числа и их количество.

    int num = 99, k = 0;
    while (num < 999)
    {
        num++;
        if (num % 2 == 0)
        {
            cout << num << " ";
            k++;
        }
    }
    cout << "Кол-во чисел на экране = " << k;
    
    _getch();
}