#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    // setlocale(LC_ALL, "rus");

    //  Задание 3. Написать программу, копирующую элементы 2 - х массивов размером 5 элементов
    //    каждый в один массив, размером 10 элементов, следующим образом : сначала копируются
    //    последовательно из обоих массивов все четные значения массива(без нулевых), затем
    //    последовательно все нечетные значения, и далее последовательно все нулевые значения.Все
    //    массивы вывести на экран.Например,
    //    Исходный массив 1 : -3, 20, 0, 7, 8
    //    Исходный массив 2 : 25, -12, 51, 0, 64
    //    Результат(массив) : 20, 8, -12, 64, -3, 7, 25, 51, 0, 0


    const int N = 5, B = 10;
    int arrOne[N]{ -3, 20, 0, 7, 8 };
    int arrTwo[N]{ 25, -12, 51, 0, 64 };
    int copyArr[B],resultArr[B], k = 0;

    for (int i = 0; i < N; i++)
    {
        copyArr[i] = arrOne[i];
    }

    for (int i = 0; i < N; i++)
    {
        copyArr[i + 5] = arrTwo[i];
    }

    for (int i = 0; i < B;i++)
    {
      if (copyArr[i] % 2 == 0 && copyArr[i] != 0)
        {
          resultArr[k] = copyArr[i];
          k++;
        }
    }

    for (int i = 0; i < B; i++)
    {
        if (copyArr[i] % 2 != 0 && copyArr[i] != 0)
        {
            resultArr[k] = copyArr[i];
            k++;
        }
    }

    for (int i = 0; i < B; i++)
    {
        if (copyArr[i] == 0)
        {
            resultArr[k] = copyArr[i];
            k++;
        }
    }
    

    cout << "\nРезультат(массив) : ";
    for (int i = 0; i < B; i++)
    {
        cout << resultArr[i] << ((i + 1 == B) ? " " : ", ");
    }

    _getch();
}