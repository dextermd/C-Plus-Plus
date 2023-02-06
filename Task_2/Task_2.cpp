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
    // ---------------------------------------- Задание 2 ------------------------------------------------------ //
    // --------------------------------------------------------------------------------------------------------- //
    // Задание 2: Создать матрицу размером ROW х COL, проинициализировать случайными
    // значениями в диапазоне от - 5 до 20, вывести на экран.Отсортируйте каждую строку / столбец
    // матрицы по возрастанию / убыванию методом Выбора.Организуйте меню для пользователя для
    // выбора что сортировать и в каком направлении, последний пункт – выход из меню.
    // --------------------------------------------------------------------------------------------------------- //

    const int ROW = 3, COL = 5;
    int min, index, menu = 0;
    int arr[ROW][COL];

    srand(time(0));

    cout << "\nМассив до сортировки: \n";

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int random = rand() % 26 + -5;
            arr[i][j] = random;
            cout << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }

    do
    {
        cout << "\n------------- Меню -------------- ";
        cout << "\n1.Сортирова строк по возрастанию.";
        cout << "\n2.Сортирова строк по убыванию.";
        cout << "\n3.Сортирова колонок по возрастанию.";
        cout << "\n4.Сортирова колонок по убыванию.";
        cout << "\n0.Выход из программы\n";
        cout << "\nВыберите пункт меню от 0 до 4: ";
        cin >> menu;
        cout << "\n--------------------------------- ";
        cout << endl;

        switch (menu)
        {
        case 1:
            cout << "\n    Сортирова строк по возрастанию.\n\n";

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
                            min = arr[i][k];
                            index = k;
                        }
                    }
                    arr[i][index] = arr[i][j];
                    arr[i][j] = min;
                }
            }


            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cout << setw(6) << arr[i][j] << " ";
                }
                cout << endl;
            }

            break;
        case 2:
            cout << "\n    Сортирова строк по убыванию.\n\n";

            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    index = j;
                    min = arr[i][j];

                    for (int k = j + 1; k < COL; k++)
                    {
                        if (arr[i][k] > min)
                        {
                            min = arr[i][k];
                            index = k;
                        }
                    }
                    arr[i][index] = arr[i][j];
                    arr[i][j] = min;
                }
            }


            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cout << setw(6) << arr[i][j] << " ";
                }
                cout << endl;
            }
            break;        
        case 3:
            cout << "\n    Сортирова колонок по возрастанию.\n\n";

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

            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cout << setw(6) << arr[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            cout << "\n    Сортирова колонок по убыванию.\n\n";

            for (int i = 0; i < COL; i++)
            {
                for (int j = 0; j < ROW; j++)
                {
                    index = j;
                    min = arr[j][i];

                    for (int k = j + 1; k < ROW; k++)
                    {
                        if (arr[k][i] > min)
                        {
                            min = arr[k][i];
                            index = k;
                        }
                    }

                    arr[index][i] = arr[j][i];
                    arr[j][i] = min;
                }

            }

            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    cout << setw(6) << arr[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }

    } while (menu);
    




    _getch();

}