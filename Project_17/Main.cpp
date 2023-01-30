#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    //setlocale(LC_ALL, "rus");

    /*
    Создать одномерный массив размером 20 и проинициализировать его
    значения случайными числами в диапазоне от -10 до 15.
    Вывести массив на экран.
    */

    // rand() % (15 - -10 + 1) + -10;    (от -10 до 15) 
    // rand() % 26 - 10;                 (от -10 до 15) 

    //const int N = 20;
    //int mas[N];

    //for (int i = 0; i < N; i++)
    //{

    //    mas[i] = rand() % 26 - 10;
    //    cout << mas[i] << "  ";
    //}


    // ----------------------------------------------------------------------------------------------- \\
    // Сортировка данных массива (Сортировка выбором)
    // ----------------------------------------------------------------------------------------------- \\
    
    //srand(time(0));
    //const int N = 20;
    //int mas[N], min, index;

    //// Инициализация массива
    //for (int i = 0; i < N; i++)
    //{

    //    mas[i] = rand() % 26 - 10;
    //    cout << mas[i] << "  ";
    //}

    //cout << endl << endl;
    //// Сортировка выбором
    //for (int i = 0; i < N; i++)
    //{
    //    min = mas[i]; // пусть mas[i] - минимальный
    //    index = i; // Начальный интекс минимального значения
    //    // Поиск минимального значения
    //    for (int j = i + 1; j < N; j++)
    //    {
    //        if (mas[j] < min)
    //        {
    //            min = mas[j]; // текущий минимум
    //            index = j; // Текущий интекс минимального значения
    //        }
    //    }

    //    // Обмен  местами минимального значения с mas[i] после поиска.
    //    mas[index] = mas[i];
    //    mas[i] = min;
    //}
    //
    //cout << "\nМассив после сортировки: \n";

    //for (int i = 0; i < N; i++)
    //{
    //    cout << mas[i] << "  ";
    //}

    /*
    Сортировку выбором можно использовать для массивов имеющих
    небольшие размеры, т.к. как число обменов всегда будет меньше
    числа сравнений, время сортировки возрастает относительно количества элементов.     (для нахождения наименьшего элемента
    из n+1 рассматриваемый алгоритм совершает n сравнений )     */


    // ----------------------------------------------------------------------------------------------- \\
    // Сортировка данных массива (Сортировка методом пузырька) (Bubble Sort)
    // ----------------------------------------------------------------------------------------------- \\

    //srand(time(0));
    //const int N = 20;
    //int mas[N], min, t;

    //// Инициализация массива
    //for (int i = 0; i < N; i++)
    //{
    //    mas[i] = rand() % 26 - 10;
    //    cout << mas[i] << "  ";
    //}

    //cout << endl << endl;
    // 
    //// Сортировка - Руслан
    ////for (int i = 0; i < N; i++)
    ////{
    ////    for (int j = i + 1; j < N; j++)
    ////    {
    ////        if (mas[i] > mas[j])
    ////        {
    ////            min = mas[j];
    ////            mas[j] = mas[i];
    ////            mas[i] = min;;
    ////        }
    ////    }
    ////}

    //// Сортировка Bubble (без оптимизации)

    //for (int i = 0; i < N; i++) // i - номер текущего шага
    //{
    //    for (int k = 0; k < N - 1; k++) // k - индекс текущего элемента
    //    {
    //        if (mas[k] > mas[k + 1]) // сравниваем текущий и соседний элемент
    //        {
    //            // Обмен
    //            t = mas[k];
    //            mas[k] = mas[k + 1];
    //            mas[k + 1] = t;
    //        }
    //    }
    //}

    // 
    //cout << "\nМассив после сортировки Bubble Sort: \n";

    //for (int i = 0; i < N; i++)
    //{
    //    cout << mas[i] << "  ";
    //}



    // ----------------------------------------------------------------------------------------------- \\

    /*
    Отсортировать массив методом Пузырька в
    указанном пользователем диапазоне,
    например в массиве размером 10 от 3-го элемента до 7-го.
    */


    //const int N = 10;
    //int mas[N]{ 10, 6, -2, 12, 10, -3, -1, 8, -9, -2 }, t, a = 3, b = 7;

    //// Инициализация массива
    //for (int i = 0; i < N; i++)
    //{
    //    cout << mas[i] << "  ";
    //}

    //for (int i = 0; i < b - a; i++)
    //{
    //    for (int k = a; k < b; k++)
    //    {
    //        if (mas[k] > mas[k+1])
    //        {
    //            t = mas[k];
    //            mas[k] = mas[k + 1];
    //            mas[k + 1] = t;
    //        }
    //    }
    //}
    // 
    //cout << "\nМассив после сортировки Bubble Sort от index 3 До index 7: \n";

    //for (int i = 0; i < N; i++)
    //{
    //    cout << mas[i] << "  ";
    //}





    // ----------------------------------------------------------------------------------------------- \\
    // Двумерные массивы *****************************************************************************
    // ----------------------------------------------------------------------------------------------- \\

    const int ROW = 3, COL = 5;
    int stud[ROW][COL]{
        {10,6,9,8,7},
        {9,7,8,5,9},
        {2,9,10,9,7}
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << setw(4) << stud[i][j];
        }
        cout << endl;
    }




    _getch();

}
