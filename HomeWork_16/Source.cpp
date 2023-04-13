#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


struct Movie {
    char title[30];
    char director[30];
    char genre[30];
    double rating;
    int price;
};


using namespace std;

void show(int* arr, int size);

void init(int* arr, int size);

void destroy(int*& arr);

bool is_odd(int a);

bool is_even(int a);

bool is_positiv(int a);

bool is_negativ(int a);

void change_arr(int*& arr, int& size, bool(*pf)(int));

void set_movie(Movie& movie);

int main()
{

    //setlocale(LC_ALL, "rus");

#if 0

    // ---------------------------------------------------------------------------------------------------------------- //

    /*
        Задание 1: Напишите функцию, которая принимает одномерный динамический массив целых,
        его размер и при каждом вызове оставляет в нем значения по определенному признаку,
        который передается третьим параметром в качестве указателя на функцию.
        Функция меняет размер исходного массива и размер.
        Продемонстрировать работу функции на формировании массива четных, нечетных,
        положительных, отрицательных значений на основе исходного массива.
     */

    int size = 10;
    int* arr = new int[size];

    if (arr)
    {
        init(arr, size);

        cout << "\nИсходный массив: ";
        show(arr, size);

        cout << endl;
        change_arr(arr, size, is_negativ);

        cout << "\nФормированый массив: ";
        show(arr, size);

    }

#endif

#if 1
    // ---------------------------------------------------------------------------------------------------------------- //

    /*
    *
    Задание 2: Создайте структуру «Фильм» :
         Название фильма
         Режиссер
         Жанр
         Рейтинг популярности
         Цена диска
        Напишите основные функции для работы с этой структурой :
     Вывод на экран данных об объекте
         Инициализации одного экземпляра структуры с клавиатуры.
        Продемонстрируйте работу функций на примере экземпляра структуры и массива из 10 фильмов
        (массив инициализирован на этапе разработки).
    */
    int size = 10;
    Movie* m;
    
    

    


#endif

    _getch();
}


void show(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}

void init(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (-10 - 10 + 1) + -10;
    }
}

void destroy(int*& arr)
{
    delete[]arr;
    arr = nullptr;
}

bool is_odd(int a) {
    return a % 2;
}

bool is_even(int a)
{
    return a % 2 == 0;
}

bool is_positiv(int a)
{
    return a >= 0;
}

bool is_negativ(int a)
{
    return a < 0;
}

void change_arr(int*& arr, int &size, bool(*pf)(int))
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if ((*pf)(arr[i]))
        {
            count++;
        }
    }

    cout << "\nКоличество значений: " << count << endl;

    int* t = new int[count];

    if (t)
    {
        int k = 0;

        for (int i = 0; i < size; i++)
        {
            if ((*pf)(arr[i]))
            {
                t[k++] = arr[i];
            }
        }

        delete[]arr;
        size = count;
        arr = t;
    }
}


void set_movie(Movie& movie)
{
    cout << "\n";
}