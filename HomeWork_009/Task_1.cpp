#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;


void main()
{
    //setlocale(LC_ALL, "rus");

    // --------------------------------------------------------------------------------------------------------- //
    // ---------------------------------------- Задание 1 ------------------------------------------------------ //
    // --------------------------------------------------------------------------------------------------------- //
    //    Задание 1: Дана двумерная матрица, размером ROW х COL, инициализирована на этапе
    //    разработки.Отсортировать последовательно каждую строку / столбец матрицы по возрастанию,
    //    использовать метод Выбора.Вывести матрицу до сортировки и результат каждой сортировки на
    //    экран.
    // --------------------------------------------------------------------------------------------------------- //

    const int ROW = 3, COL = 5;
    int min, index;
    int arr[ROW][COL]{
        {10,-6,9,8,7},
        {9,7,8,-5,9},
        {2,9,-10,9,7}
    };

    cout << "\nМассив до сортировки: \n";

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            index = j;
            min = arr[i][j];

            for (int k = j + 1; k < COL; k++)
            {
                if (arr[i][k] < min)
                {
                    min = arr[i][k]; // текущий минимум
                    index = k; // Текущий интекс минимального значения
                }

            }

            arr[i][index] = arr[i][j];
            arr[i][j] = min;
        }

    }

    cout << "\nМассив после сортировки строк: \n";

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            index = j;
            min = arr[j][i];

            for (int k = j + 1; k < ROW; k++)
            {
                if (arr[k][i] < min)
                {
                    min = arr[k][i]; 
                    index = k; 
                }

            }

            arr[index][i] = arr[j][i];
            arr[j][i] = min;
        }

    }

    cout << "\nМассив после сортировки столбцов: \n";

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    _getch();

}