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
    cout << "\n Function m = " << m << endl;
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

int** memory(int row, int col)
{
    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    return arr;
}

void init(int** m, int row, int col, int, int b)
{
}

void showDynamArr(int** m, int row, int col)
{
}

void destroy(int**& m, int row)
{

}
