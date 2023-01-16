#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    // setlocale(LC_ALL, "rus");

    //  Задание 1. Пользователь вводит длины сторон пятиугольника, каждая сторона сохраняется в
    //    массиве, необходимо вычислить периметр пятиугольника(периметр – сумма всех сторон).
    //    Осуществлять проверку правильного ввода данных(положительные ненулевые значения).

    const int N = 5;
    int arr[N], perim = 0;

    cout << "\nВведите длину сторон пятиугольника: \n";

    for (int i = 0; i < N;)
    {
        cout << "\nУгол " << i + 1 << " :";
        cin >> arr[i];
        if (arr[i] > 0)
        {
            perim += arr[i];
            i++;
        }
        else {
            cout << "\nНеверное значение угла " << i + 1 <<  ". Введите еще раз.\n";
        }
    }

    cout << "\nПериметр пятиугольника равен: " << perim;

    _getch();
}