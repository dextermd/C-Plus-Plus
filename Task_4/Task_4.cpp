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
    // ---------------------------------------- Задание 4 ------------------------------------------------------ //
    // --------------------------------------------------------------------------------------------------------- //
    // Задание 4: Напишите программу, которая создает двухмерный массив размером N строк N
    // столбцов(квадратная матрица), инициализирует матрицу случайными значениями в выбранном
    // пользователем диапазоне(вводится с клавиатуры).Определить и вывести на экран
    // максимальное и минимальное значения на главной и вспомогательной диагоналях матрицы.
    // --------------------------------------------------------------------------------------------------------- //

    const int ROW = 4, COL = 4;
    int arr[ROW][COL], first[ROW], second[ROW], a, b;

    srand(time(0));

    cout << "\nВведите диапозон чисел для массива: ";
    cin >> a >> b;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            
            int random = a > b ? (rand() % (a - b + 1) + b) : (rand() % (b - a + 1) + a);
            arr[i][j] = random;
        }
    }

    for (int i = 0; i < ROW; i++)
    {

        for (int j = 0; j < COL; j++)
        {

            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl << endl;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j + i == ROW / 2 + 1 )
            {

                cout << setw(4) << arr[i][j] << " ";
                first[i] = arr[i][j];

            }
            else if (i - j == ROW / 2 - 2)
            {
                cout << setw(4) << arr[i][j] << " ";
                second[i] = arr[i][j];
            }
            else {
                cout << "     ";
            }
        }
        cout << endl;
    }

    cout << endl;

    int first_max, first_min;
    first_max = first[0];
    first_min = first[0];

    for (int i = 1; i < ROW; i++)
    {
        if (first_max < first[i])
        {
            first_max = first[i];
        }
        else if (first_min > first[i])
        {
            first_min = first[i];
        }
    }

    cout << "\nГлавной диагональ матрицы Min = " << first_min << " и Max = " << first_max;


    cout << endl;

    int second_max, second_min;
    second_max = second[0];
    second_min = second[0];

    for (int i = 0; i < ROW; i++)
    {
        if (second_max < second[i])
        {
            second_max = second[i];
        }
        else if (second_min > second[i])
        {
            second_min = second[i];
        }
    }
    cout << "\nВспомогательная диагональ матрицы Min = " << second_min << " и Max = " << second_max;


    _getch();

}