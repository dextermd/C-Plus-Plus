#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "array_functions.h"
#include "help_functions.h"
#include "my_template.h"
#include "color.h"
#include "dynamic_arr.h"

using namespace std;

// void show_2d_array(int arr[][5], int row) 
template<class T>
void show_2d_array(T arr, int row) 
{
    for (int i = 0; i < row; i++)
    {
        for (const int& x : arr[i])
        {
            cout << setw(5) << x;
        }
        cout << endl;
    }
}

int main()
{

    //setlocale(LC_ALL, "rus");

    // ---------------------------------------------------------------------------------------------------------------- //
    // ********************************** Динамическое выделение памяти (матрицы) ************************************* //
    // Зубчатые(ступенчатые) масисвы    /    jagged arrays        
    // Пример динамической матрицы с разной длиной строк.
    // Количество колонок каждой строки запрашивается с клавиатуры.

#if 0

    int row, col;
    cout << "\nВведите кол-во строк: ";
    cin >> row;

    int** arr = new int* [row];

    if (arr)
    {
        // Массив для хранения кол-во колонок каждой строки матрицы
        int* arr_col = new int[row];

        for (int i = 0; i < row; i++)
        {
            cout << "\nВведите кол-во колонок для " << i + 1 << " строки: ";
            // Вариант 1 c использованием col
            //cin >> col;
            //arr_col[i] = col; // сохранения кол-во колонок каждой строки в массиве
            //arr[i] = new int[col];

            // Вариант 2 с использование массива, без использования col
            cin >> arr_col[i]; // Запись в массив кол-во колонок в i-ой строке
            arr[i] = new int[arr_col[i]]; // Выделение памяти под каждую строку

            for (int j = 0; j < arr_col[i]; j++)
            {
                arr[i][j] = rand() % 10 + 1;
                cout << setw(5) << arr[i][j];
            }
        }

        // Вывод матрицы повторно  отдельно
        cout << endl << endl;
        cout << "\nДанные по кол-ву колонок в каждой строке: ";
        for (int k = 0; k < row; k++)
        {
            cout << arr_col[k] << "   ";
        }

        cout << endl << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < arr_col[i]; j++)
            {
                cout << setw(5) << arr[i][j];
            }
            cout << endl;
        }

        if (arr_col)
        {
            delete[]arr_col;
            arr_col = nullptr;
        }
        // ...
        for (int i = 0; i < row; i++)
        {
            delete[]arr[i];
        }
        delete[]arr;
        arr = nullptr;
    }

#endif 


#if 0

    // ---------------------------------------------------------------------------------------------------------------- //
    // ********************************** Динамическое выделение памяти (матрицы) ************************************* //
    /*
    Написать функцию, добавляющую строку двухмерному массиву в конец.
    Меняется количество строк матрицы.
    */

    int row, col;
    cout << "\nВведи количество строк, колонок: ";
    cin >> row >> col;


    
    int** res = memory(row, col);
    if (res)
    {
        init(res, row, col, -20, 20);
        cout << "\nИсходная матрица: \n";
        show(res, row, col);

        int *add = memory(col); // Выделение памяти под добавляемую строку
        if (add)
        {
            init(add, col, 0, 1);
            cout << "\nСтрока для добавления в матрицу: ";
            show(add, col);

            // .....
           add_end_str(res, row, col, add);
           cout << "\nКол-во строк : " << row;
           cout << "\nМатрица с новой строкой: \n";
           show(res, row, col);

           destroy(add);
        }

        destroy(res, row);
    }

#endif 


    // ---------------------------------------------------------------------------------------------------------------- //
    // Трехмерная матрица код скопировали не писали

#if 0

    int DIM1 = 4;
    int DIM2 = 3;
    int DIM3 = 5;
    int*** ar;


    int cnt = 1;

    // Выделение памяти
    ar = new int** [DIM1];
    for (int i = 0; i < DIM1; i++) {
        ar[i] = new int* [DIM2];
        for (int j = 0; j < DIM2; j++) {
            ar[i][j] = new int[DIM3];
        }
    }

    // Инициализация матрицы и вывод на экран
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                ar[i][j][k] = cnt++;// инициализация
                cout << setw(4) << ar[i][j][k];// вывод значений 
            }
            cout << endl;
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            delete[] ar[i][j];
        }
        delete[] ar[i];
    }
    delete[] ar;
    ar = nullptr;

#endif


    // -------------------------------------------------------------------------------------------------------------------------- //
    // Вывод данных для СТАТИЧЕСКИХ масивов, должны знать размер
    // range_based loop

#if 0

    const int N = 5, ROW = 3, COL = 5;
    int m[N]{ 25,-6,8,9,1 };
    int arr[ROW][COL]{
        {25,-6,8,9,23},
        {89,-88,8,4,3 },
        {56,-69,43,80,234},
    };
    
    // Для одномерного массива ------------------------------------------------------------------ для СТАТИЧЕСКИХ
    for (int v : m) // v - имя переменной для прохода по элементам массива
    {
        cout << v << " ";
    }

    cout << endl << endl;

    for (int& x : m) 
    {
        x *= 2;
        cout << x << " ";
    }

    cout << endl << endl << endl;

    // Для двумерного массива ------------------------------------------------------------------ для СТАТИЧЕСКИХ
    for (int i = 0; i < ROW; i++)
    {
        for (const int& x : arr[i]) 
        {
            cout << setw(5) << x;
        }
        cout << endl;
    }
    
    cout << endl << endl << endl;

    show_2d_array(arr, ROW);
   

#endif



    _getch();
}


