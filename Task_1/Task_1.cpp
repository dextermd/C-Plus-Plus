#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  Задание 1. Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры :
    //  1 <= a <= 20).Осуществить проверку правильности ввода значения с клавиатуры.

    int n, num;
    unsigned long long result;

    cout << "Введите значение от 1 до 20: ";
    cin >> n;
    if (n >= 1 && n <= 20)
    {
        result = n;
        num = n;
        while (n >= 1 && n <= 20)
        {
            result *= n;
            n++;
            

        }
        cout << "Произведение чисел от " << num << " до 20: " << result;
    }
    else
        cout << "\nВвели неверное значение!";




    _getch();
}