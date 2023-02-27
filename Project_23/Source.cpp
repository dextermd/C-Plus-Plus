#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "array_functions.h"
#include "help_functions.h"
#include "my_template.h"

using namespace std;

long long fact(int n)
{
    long long f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }

    return f;
}

long long factorial(int n) 
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 1 || n == 0) // базовая задача
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void show_numbers_up(int n)
{
    if (n > 0)
    {
        show_numbers_up(n - 1);
    }
    cout << n << " ";
}

void show_numbers_down(int n)
{
    if (n >= 0)
    {
        cout << n << " ";
        show_numbers_down(n - 1);
    }
}

void show_number_a_to_b(int a, int b)
{
    cout << a << " ";
    if (a > b)
    {
        show_number_a_to_b(a - 1, b);
    }
    else if (a < b)
    {
        show_number_a_to_b(a + 1, b);
    }
}

void show_symbols(int n, char s)
{
    if (n > 0)
    {
        cout << s << " "; 
        show_symbols(n - 1, s);
    }
}

void show_invers(int n)
{
    if (n)
    {
        cout << n % 10 << " ";
        show_invers(n / 10);
    }
}

int summa_num(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    return n + summa_num(n -1);
}



int summa_digits(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10  + summa_digits(n / 10);
}

long long fibonacci(int n) 
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Макрос
// #define Имя_макроса(Выражение)
#define LINE {for(int i = 0; i < 10; i++) cout << "="; cout << endl;}

// #define Имя_макроса(Параметры)(Выражение) - Параметризированный макрос
#define SUMMA(X,Y) ((X)+(Y))

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

#define SQ(X) ((X) * (X))

#define PRINT(X) cout << X;


int main()
{

    //setlocale(LC_ALL, "rus");
    
    //5 = 1 * 2 * 3 * 4 * 5;
    //cout << "\nФакториал : " << fact(5) << endl;

    // ---------------------------------------------------------------------------------------------------------------- //
    // ****************************************** Рекурсивные функции ************************************************* //
    // Рекурсия - Вычисление факториала числа
    // 5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 1

    // cout << "\nФакториал : " << factorial(5) << endl;



    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - Вывести числа от 0 до n и от n до 0

    // show_numbers_up(10);
    // show_numbers_down(10);


    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - Вывести числа от a до b;

    //show_number_a_to_b(10, 5);
    //cout << endl << endl;
    //show_number_a_to_b(5, 10);
    //cout << endl << endl;
    //show_number_a_to_b(5, 5);


    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - вывести n символов в ряд

    //show_symbols(10, '%');


    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - Вывод числа n завдом наперед

    //show_invers(15684);


    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - Сумма чиссел от 1 до n, где N > 0

    //cout << "\nСумма = " << summa_num(10);

    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия - Сумма цыфр числа;

    // cout << "\nСумма цифр числа = " << summa_digits(3256);


    // ---------------------------------------------------------------------------------------------------------------- //
    // Рекеурсия -  Вывод n - го числа из ряда Фиббоначи (рекурсивно)

    int n = 6;
    cout << fibonacci(n) << endl;
    cout << fibonacci(n + 1) << endl;
    cout << fibonacci(n + 2) << endl;



    _getch();
}