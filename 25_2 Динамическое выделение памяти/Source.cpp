#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;

int* memory(int size);
void init(int* m, int size, int  = 1, int b = 10);
void show(int* m, int size);
void destroy(int*& m);


int main()
{

    //setlocale(LC_ALL, "rus");

    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************** Динамическое выделение памяти ******************************************* //
    // 6. Динамическое выделение памяти
    // Выделение дтнамической памяти под одно значение целого типа
#if 0
    int* p = new int; // new - С++ выделение памяти
    if (p)
    {
        cout << "\nАдрес: " << p;
        *p = 25;
        cout << "\nЗначение : " << *p;
        // ....
        delete p; // delete Освобождение памяти, обязательно надо делать в конце иначе будет утечка памяти.

        cout << "\nАдрес: " << p;

        p = nullptr;

        cout << "\nАдрес: " << p;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }


    if (!p) // if(p == nullptr)
    {
        p = new int;
        *p = -321;
        cout << "\nЗначение : " << *p;
        delete p;
        p = nullptr;
    }
    else {
        cout << "\nПамять не освобождена";
    }

#endif

    // Выделение динамической памяти под одномерный массив
#if 0
    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* mas = new int[size];
    if (mas)
    {
        cout << "\nАдрес : " << mas;
        for (int i = 0; i < size; i++)
        {
            //mas[i] = rand() % 20;
            *(mas + i) = rand() % 20;
            cout << *(mas + i) << "  ";
        }
        // ...
        delete[]mas;
        mas = nullptr;
        cout << "\nАдрес : " << mas;
    }

#endif

    // Выделение динамической памяти под одномерный массив с использованием функции
    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* m = memory(size);
    if (m)
    {
        cout << "\n m = " << m << endl;
        init(m, size, -5, 20);
        show(m, size);
        // ...

        destroy(m);
        cout << "\n m = " << m << endl;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }

    _getch();
}

int* memory(int size)
{
    int* p = new int[size];
    return p;
}

void init(int* m, int size, int a, int b)
{
    for (int i = 0; i < size; i++)
    {
        *(m + i) = rand() % (b - a + 1) + a;
    }
}

void show(int* m, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(m + i) << "  ";
    }
}

void destroy(int*& m)
{
    delete[]m;
    m = nullptr;
    cout << "\n Function m = " << m << endl;
}
