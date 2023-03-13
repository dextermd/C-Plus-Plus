#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;

// void show(int arr[], int size);

void show(int* m, int size);

void arr_multiple(int arr[], int size, int& min, int& max, int& summa, float& media);

int arr_get_max(int *(arr), int size);

void init(int* m, int size, int a, int b);

int* memory(int size);

void destroy(int*& m);

void push_start(int*& m, int &size, int value);

void delete_first(int*& m, int& size);

void delete_last(int*& m, int& size);

void delete_index(int*& m, int& size, int idx);

int main()
{

    //setlocale(LC_ALL, "rus");

    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 1 *************************************************** //
    /* Напишите функцию, которая принимает одномерный массив целых чисел,
    его размер и возвращает : максимальное, минимальное значения массива, сумму
    элементов массива и среднее арифметическое.Использовать передачу параметров по
    ссылке для возврата нескольких значений из функции. */

#if 0

    const int N = 10;
    int arr[N]{ 5,9,3,4,7,6,9,8,2,3 };
    int min, max, summa;
    float media;
    
    arr_multiple(arr, N, min, max, summa, media);
    show(arr, N);

    cout << "\nМинимальное значения массива: " << min;
    cout << "\nМаксимальное значения массива: " << max;
    cout << "\nСумма значений массива: " << summa;
    cout << "\nСреднее арифметическое: " << media;

#endif

    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 2 *************************************************** //
    /* Напишите функцию нахождения максимального элемента одномерного
    массива.Функция принимает массив, его размер и возвращает максимальное значение.
    В коде функции использовать арифметику указателей(не использовать[]). */

#if 0

    const int N = 10;
    int arr[N]{ 5,9,3,4,7,6,20,8,2,3 };

    show(arr, N);
    cout << "\nМаксивальное значение массива = " << arr_get_max(arr, N);

#endif


    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 3 *************************************************** //
    /* Используя два скалярных указателя на статические одномерные массивы
    целых чисел, скопировать один массив в другой.Использовать в программе арифметику
    указателей для продвижения по массивам, а также оператор разыменования(не
    использовать[]). */

#if 0

    const int N = 10;
    int arr1[N]{ 5,9,3,4,7,6,1,8,2,3 };
    int arr2[N]{ 10,45,85,99,14,68,55,89,36,35 };
    int* p_arr1 = arr1;
    int* p_arr2 = arr2;

    cout << "\nМассивы до перемещения: " << endl;

    for (int i = 0; i < N; i++)
    {
        cout << *(arr1 + i) << "  ";
    }

    cout << endl;

    for (int i = 0; i < N; i++)
    {
        cout << *(arr2 + i) << "  ";
    }

    for (int i = 0; i < N; i++)
    {
        int t_num;
        t_num = *p_arr2;
        *p_arr2 = *p_arr1; 
        *p_arr1 = t_num;
        p_arr1++;
        p_arr2++;
    }

    cout << "\nМассивы после перемещения: " << endl;

    for (int i = 0; i < N; i++)
    {
        cout << *(arr1+i) << "  ";
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        cout << *(arr2 + i) << "  ";
    }

#endif 

    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 4 *************************************************** //
    /* Напишите функцию добавления элемента в начало одномерного массива
    целого типа. (Меняется исходный массив и его размер) */

#if 0

    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* m = memory(size);

    if (m)
    {
        cout << "\n m = " << m << endl;
        init(m, size, -5, 20);
        show(m, size);
        

        push_start(m, size, 1000);

        cout << "\nРазмер нового массива: " << size << endl;
        show(m, size);

        destroy(m);
        cout << "\n m = " << m << endl;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }

#endif 


    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 5 *************************************************** //
    /* Напишите функцию удаления первого элемента одномерного массива
    целого типа. (Меняется исходный массив и его размер) */


#if 0

    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* m = memory(size);

    if (m)
    {
        cout << "\n m = " << m << endl;
        init(m, size, 10, 20);
        show(m, size);

        delete_first(m, size);

        cout << "\nРазмер нового массива: " << size << endl;
        show(m, size);

        destroy(m);
        cout << "\n m = " << m << endl;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }


#endif 


    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 6 *************************************************** //
    /*Задание 6: Напишите функцию удаления последнего элемента одномерного массива
    целого типа. (Меняется исходный массив и его размер)*/


#if 0

    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* m = memory(size);

    if (m)
    {
        cout << "\n m = " << m << endl;
        init(m, size, 10, 20);
        show(m, size);

        delete_last(m, size);

        cout << "\nРазмер нового массива: " << size << endl;
        show(m, size);

        destroy(m);
        cout << "\n m = " << m << endl;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }


#endif 


    // ---------------------------------------------------------------------------------------------------------------- //
    // ************************************************** Задание 7 *************************************************** //
    /* Задание 7: Напишите функцию удаления элемента одномерного массива целого типа по
    переданному индексу. (Меняется исходный массив и его размер) */

#if 0

    int size;
    cout << "\nВведите размер массива: ";
    cin >> size;

    int* m = memory(size);

    if (m)
    {
        cout << "\n m = " << m << endl;
        init(m, size, 10, 20);
        show(m, size);

        delete_index(m, size, 2);

        cout << "\nРазмер нового массива: " << size << endl;
        show(m, size);

        destroy(m);
        cout << "\n m = " << m << endl;
    }
    else {
        cout << "\nОшибка выделения памяти";
    }


#endif 



    _getch();
}

void destroy(int*& m)
{
    delete[]m;
    m = nullptr;
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
    cout << endl;
}

void arr_multiple(int arr[], int size, int& min, int& max, int& summa, float& media)
{
    min = arr[0];
    max = arr[0];
    summa = 0;
    media = 0.;
    for (int i = 0; i < size; i++)
    {
        summa += arr[i];
        min < arr[i] ? min : min = arr[i];
        max > arr[i] ? max : max = arr[i];
        
    }
    media = (double)summa / size;
}

int arr_get_max(int *(arr), int size)
{
    int max = *(arr);

    for (int i = 0; i < size; i++)
    {
        max > *(arr + i) ? max : max = *(arr + i);
    }

    return max;
}


void push_start(int*& m, int &size, int value)
{
    size++;
    int* res = new int[size];

    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i + 1] = m[i];
        }
        res[0] = value;
    }

    delete[]m;
    m = res;
}

void delete_first(int*& m, int& size)
{
    size--;
    int* res = new int[size];

    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = m[i + 1];
        }

    }
    delete[]m;
    m = res;
}

void delete_last(int*& m, int& size)
{
    size--;
    int* res = new int[size];

    if (res)
    {
        for (int i = 0; i < size; i++)
        {
            res[i] = m[i];
        }
    }
    delete[]m;
    m = res;
}


void delete_index(int*& m, int& size, int idx)
{

    int* res = new int[size];

    if (res)
    {
        for (int i = 0; i < idx; i++)
        {
            res[i] = m[i];
        }

        for (int i = idx; i < size; i++)
        {
            res[i - 1] = m[i];
        }
    }

    delete[]m;
    m = res;
    size--;
}
