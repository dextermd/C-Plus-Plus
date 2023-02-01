#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void main()
{
    //setlocale(LC_ALL, "rus");

    //  В одномерном массиве осуществить циклический сдвиг значений элементов на k
    //  позиций вправо.Пример работы программы :
    // 1 2 3 4 5 6 7 8 9 10 - исходный массив
    // Введите величину сдвига 3
    // 8 9 10 1 2 3 4 5 6 7 - массив после сдвига

    const int N = 10;
    int arr[N]{ 1,2,3,4,5,6,7,8,9,10 }, num ,t;
    

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " - исходный массив";

    cout << "\nВведите величину сдвига: ";
    cin >> num;
    
        
    for (int i = 0; i < num; i++)
    {
        t = arr[N - 1];

        for (int k = N - 1; k > 0; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[0] = t;
    }
 
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " - массив после сдвига\n";


    _getch();

}