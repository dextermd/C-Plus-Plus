#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    //setlocale(LC_ALL, "rus");

    //  Задание 2. Одномерный массив проинициализировать случайными значениями в диапазоне,
    //    который задает пользователь, вывести массив на экран.Необходимо отсортировать первые две
    //    трети одномерного массива в порядке возрастания, если среднее арифметическое всех
    //    элементов больше нуля; иначе - лишь первую треть.Остальную часть массива не сортировать.
    //    Вывести отсортированный массив на экран.

    const int N = 10;
    int arr[N], a, b, total = {}, t;
    bool low;

    srand(time(0));

    cout << "\nВведите диапазон: ";
    cin >> a >> b;

    for (int i = 0; i < N; i++)
    {
        if (a > b)
        {
            int r = rand() % (a - b + 1) + b;
            arr[i] = r;
        }
        else {
            int r = rand() % (b - a + 1) + a;
            arr[i] = r;
        }
        
        total += arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << "\nСреднее арифметическое: " << total / N << endl;

    total / N <= 0 ? low = true : low = false; 
    low ? total = 2 : total = 5;

    for (int i = 0; i < total; i++)
    {
        for (int k = 0; k < total; k++)
        {
            if (arr[k] > arr[k+1])
            {
                t = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = t;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    _getch();

}