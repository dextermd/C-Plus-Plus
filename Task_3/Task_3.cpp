#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    //setlocale(LC_ALL, "rus");

    //  Задание 3: Создать матрицу размером ROW х COL, проинициализировать случайными
    //    значениями в диапазоне от -5 до 20, вывести на экран.Сгенерировать случайное число в этом
    //    же диапазоне и определить, есть ли это число в матрице, подсчитать количество его повторений.
    //    Также вывести на экран индексы(строки и столбца) всех вхождений этого числа в матрицу.

    const int ROW = 8, COL = 5;
    int arr[ROW][COL],arr_index[ROW][COL], random, count_random = 0 , index = 1;


    srand(time(0));

    random = rand() % (20 - -5 + 1) + -5;

    for (int i = 0; i < ROW; i++)
    {
        for (int k = 0; k < COL; k++)
        {
            int r = rand() % (20 - -5 + 1) + -5;
            arr[i][k] = r;
            cout << setw(4) << arr[i][k] << " ";

            if (arr[i][k] == random)
            {
                count_random += 1;
                arr_index[i][k] = 1;
            }else{
                arr_index[i][k] = 0;
            }
        }
        cout << endl;
    }

    cout << "\nCлучайное число  = " << random << endl;
    cout << "Количество его повторений " << count_random << endl << endl;

    for (int i = 0; i < ROW; i++)
    {
        for (int k = 0; k < COL; k++)
        {
            if (arr_index[i][k] > 0)
            {
                cout << index << ". " << "ROW = " << i << " COL = " << k << endl;
                index++;
            }
        }
    }

    _getch();

}