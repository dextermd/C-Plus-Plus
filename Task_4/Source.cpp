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



    _getch();
}