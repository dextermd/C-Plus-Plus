#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "dynamic_arr.h"

using namespace std;

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

void showDynamArr(int* m, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(m + i) << "  ";
    }
    cout << endl;
}


void destroy(int*& m)
{
    delete[]m;
    m = nullptr;
}

int* mas_odd(int* m, int size, int& size2)
{
    size2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (m[i] % 2)
        {
            size2++;
        }
    }

    int* odd = new int[size2];

    if (odd)
    {
        int k = 0;

        for (int i = 0; i < size; i++)
        {
            if (m[i] % 2)
            {
                odd[k++] = m[i];
            }

        }
    }

    return odd;
}

int* push_back(int* m, int size, int &size2, int value)
{
    size2 = size + 1;
    int* res = new int[size2];
    
    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = m[i];
        }

        res[size2 - 1] = value; // запись  значения в конец нового массива
    }
    return res;
}

int* push_start(int* m, int size, int& size2, int value)
{
    size2 = size + 1;
    int* res = new int[size2];

    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i+1] = m[i];
        }

        res[0] = value; // запись  значения в конец нового массива
    }

    return res;
}

void mas_odd(int*& m, int& size)
{
    int size2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (m[i] % 2)
        {
            size2++;
        }
    }

    size = size2++;
    int* odd = new int[size2];

    if (odd)
    {
        int k = 0;

        for (int i = 0; i < size; i++)
        {
            if (m[i] % 2)
            {
                odd[k++] = m[i];
            }
        }

    }
    // Освобождение памяти исходного массива
    delete[]m;
    // Адрес нового массива записываем вместо адреса исходного массива
    m = odd;
    // Меняем размер массива
    size = size2;
}

void push_back(int*& m, int& size, int value)
{
    int size2 = size + 1;
    int* res = new int[size2];

    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = m[i];
        }

        res[size2 - 1] = value; // запись  значения в конец нового массива
    }

    delete[]m;
    m = res;
    size = size2;
}

void add_by_index(int*& m, int& size, int index, int value)
{
    size++;
    int* res = new int[size];

    if (res)
    {
        for (int i = 0; i < index; i++)
        {
            res[i] = m[i];
        }
        
        for (int i = index; i < size; i++)
        {
            res[i + 1] = m[i];
        }
        res[index] = value;
    }

    delete[]m;
    m = res;

}


//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
int** memory(int row, int col)
{
    // Выделение памяти под одномерный массив адресов(=указателей) строк матрицы
    int** mas = new int* [row];
    // Выделение памяти под каждую строку матрицы(=под одномерный массив)
    for (int i = 0; i < row; i++)
    {
        mas[i] = new int[col];
    }
    return mas;
}
//---------------------------------------------
void init(int** mas, int row, int col, int a, int b)
{
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    //Инициализация значений матрицы на экран
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mas[i][j] = rand() % (b - a + 1) + a;
        }
    }
}
//---------------------------------------------
void show(int** mas, int row, int col)
{
    //вывод на экран
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(6) << mas[i][j];
        }
        cout << endl;
    }
}
//---------------------------------------------
void destroy(int**& mas, int row)
{
    //Освобождение памяти:
        // Освобождаем память, выделенную под строки матрицы
    for (int i = 0; i < row; i++) {
        delete[]mas[i];
    }
    // Освобождаем память, выделенную под адреса строк
    delete[]mas;
    mas = nullptr;
}

void add_end_str(int**& m, int& row, int col, int* add)
{
    //// Вариант 1 - с полным перераспределением памяти
    
    //int** m2 = new int* [row + 1]; // выделение памяти под адресса строк в новом массиве
    //for (int i = 0; i < row; i++)
    //{
    //    m2[i] = new int[col]; // выделение памяти под каждую строку в новом масстиве (кроме последней - добавляемой (add))
    //    for (int j = 0; j < col; j++)
    //    {
    //        m2[i][j] = m[i][j]; // копирование данных исходного массива
    //    }
    //}

    //// выделение памяти под новую строку
    //m2[row] = new int[col];

    //for (int j = 0; j < col; j++)
    //{
    //    m2[row][j] = add[j]; // копирование даннных добавляемой троки
    //}

    //// Освобождение памяти под исходный массив

    //for (int i = 0; i < row; i++)
    //{
    //    delete[]m[i];
    //}
    //delete[]m;

    //// Запись нового адреса вместо исходного адреса
    //m = m2;
    //// Меняем кол-во строк
    //row++;

    // --------------------------------------------------------------------------------------------------------
    // Вариант 2 - с копированием  адресов строк исходного массива

    int** m2 = new int* [row + 1];
    // Копирование адресов строк исходного массива в новый массив адресов
    for (int i = 0; i < row; i++)
    {
        m2[i] = m[i];
    }

    m2[row] = new int[col];
    for (int j = 0; j < col; j++)
    {
        m2[row][j] = add[j]; //копирование данных добавляемой троки
    }

    delete[]m;
    m = m2; // запись нового адреса вместо старого
    row++;
}
