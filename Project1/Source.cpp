#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    // setlocale(LC_ALL, "rus");

    //  Задание 2. В одномерном массиве, состоящем из N целых чисел вычислить и вывести на экран :
    //    - количество четных элементов
    //    - сумму четных элементов
    //    - количество нечетных элементов
    //    - сумму нечетных элементов
    // 
    //    - сумму элементов с четными индексами
    //    - сумму элементов с нечетными индексами
    // 
    //    - количество четных элементов с четными индексами
    //    Рассчитать средние арифметические значения для четных и для нечетных значений массива
    //    отдельно.


    const int N = 15;
    int arr[N]{ 5, 9, 25, 5, -4, 123, 78, 0, 45, 365, 20, -50, -2, 66, 98 };
    int count_even = 0, summa_even = 0, count_odd = 0, summa_odd = 0, summa_even_index = 0, summa_odd_index = 0, count_even_and_even_index = 0;
    bool even, index_even, even_and_even;

    cout << "\nДанные массива: \n";

    for (int i = 0; i < N; i++)
    {
        arr[i] % 2 == 0 ? even = true : even = false;
        i % 2 == 0 ? index_even = true : index_even = false;

        even&& index_even ? count_even_and_even_index++ : count_even_and_even_index;
        even ? count_even++, summa_even += arr[i] : count_odd++, summa_odd += arr[i];
        index_even ? summa_even_index += arr[i] : summa_odd_index += arr[i];

        cout << arr[i] << " ";
    }

    cout << endl << setprecision(2) << fixed;

    cout << "\nКоличество четных элементов массива: " << count_even;
    cout << "\nСумма четных элементов массива: " << summa_even;
    cout << "\nСредние арифметические значения для четных элементов массива: " << summa_even / count_even;

    cout << endl << endl;

    cout << "\nКоличество нечетных элементов массива: " << count_odd;
    cout << "\nСумма нечетных элементов массива: " << summa_odd;
    cout << "\nСредние арифметические значения для нечетных элементов массива: " << summa_odd / count_odd;

    cout << endl << endl;

    cout << "\nСумма элементов с четными индексами массива: " << summa_even_index;
    cout << "\nСумма элементов с нечетными индексами массива: " << summa_odd_index;

    cout << endl << endl;

    cout << "\nКоличество четных элементов с четными индексами массива: " << count_even_and_even_index;

    _getch();
}