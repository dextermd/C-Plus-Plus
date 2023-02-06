#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

int summa(int a, int b); // 1. Прототип функции
double media(int a, int b, int c);
int maximum(int a, int b);

// Функция ничего не возвращает
void show_max(int a, int b);

int maximum(int a, int b, int c);

void show_max(int a, int b, int c);

void stars();

void line(char symbol, int count);

int count_digits(long long a);

int digit_by_pos(long long n, int pos);

void main()
{
    //setlocale(LC_ALL, "rus");


    // ------------------------------------------------------------------------------------------------------------------- //
    // ------------------------------------------------- Функции --------------------------------------------------------- //
    // ------------------------------------------------------------------------------------------------------------------- //

    /*
    Написать функцию, которая принимает 2 целых числа,
    определяет и возвращает сумму этих чисел
    */

    //// 3. Вызов функции
    //// cout << summa(10, 2);

    //int a, b, res;

    //a = 15;
    //b = 4;

    //// 3. Вызов функции - вариант 1 (вызов возвращаеиого значения на  экран)
    //cout << "\nСумма этих чисел = " << summa(a, b);

    //// 3. Вызов функции - вариант 2 (Сохранение возвращаемого значения в отдельной переменной)
    //res = summa(a, b);
    //cout << "\nRes = " << res;


    // ------------------------------------------------------------------------------------------------------------------- //

    /*
    Написать функцию, которая принимает 3 целых числа,
    определяет и возвращает среднее арифметическое(дробное)
    */

        //int n1 = 6, n2 = 9, n3 = 10;
        //double r;
        //cout << setprecision(2) << fixed;
        //cout << "\nСреднее: " << media(n1, n2, n3) << endl; // 1
        //r = media(n1, n2, n3); 
        //cout << "\nR: " << r << endl; // 2


       // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая возвращает
        максимум из двух чисел целого типа.
        */

        //int a = 150; int b = 200;
        //cout << maximum(a, b);



        // ------------------------------------------------------------------------------------------------------------------- //
    
        /*
        Написать функцию, которая
        выводит на экран
        максимум из двух чисел целого типа.
        */

        //show_max(150, 600);

        // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая определяет (возвращает)
        максимальное из трех целых     чисел.
        */

        // cout << "\nМаксимум из 3 чисел: " << maximum(150, 200, 50);


        // ------------------------------------------------------------------------------------------------------------------- //
    
        //Функция выводит на экран максимальное из трех целых

        //show_max(122, 369, 875);

        // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая выводит на экран символ * 10 раз.
        */

        // stars();


        // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая выводит на экран символ
        (передается первым параметром),
        количество  повторений определяется вторым параметром.
        */

        // line('^', 15);


        // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая принимает целое число, определяет и
        возвращает  количество цифр в этом числе.
        */
        
        //long long n = 2365412;
        //int c;

        //cout << "\nКол-во цифр в числе " << n << " = " << count_digits(n); // Вариант вывода 1
        //c = count_digits(n);
        //cout << "\nКол-во цифр в числе " << n << " = " << c; // Вариант вывода 2


        // ------------------------------------------------------------------------------------------------------------------- //

        /*
        Написать функцию, которая принимает целое число, позицию
        цифры в числе, определяет и    возвращает  цифру, расположенную
        по переданной позиции.
        n = 646531264 
        pos = 4      
        цифра в позиции 4 числа 646531264 равна 5
        */
        
        long long n = 646531264;
        int pos = 6;

        int k = count_digits(n);

        if (pos >= 1 && pos <= k)
        {
            cout << "\nЧисло " << n;
            cout << "\nЦифра по позиции " << pos << " : " << digit_by_pos(n, pos);
        }
        else {
            cout << "\nТакой позиции нет в числе";
        }


        _getch();
    
    }

    
    // 2. Реализация/имплементация функции
    int summa(int a, int b)
    {
        //int s;
        //s = a + b;
        //return s;

        return a + b;
    }
    
    double media(int a, int b, int c)
    {
        //double m;
        //m = double(a + b + c) / 3;
        //return m;
    
        return double(a + b + c) / 3;
    }


    int maximum(int a, int b)
    {
        return (a > b ? a : b);
    }

    void show_max(int a, int b)
    {
        cout << "\nМаксимальное значение из " << a << " и " << b << " = " << (a > b ? a : b);
    }

    int maximum(int a, int b, int c)
    {
        int m;
        m = (a > b ? a : b);
        m = (c > m ? c : m);
        return m;
    }

    void show_max(int a, int b, int c)
    {
        int m;
        m = (a > b ? a : b);
        m = (c > m ? c : m);
        cout << "\nМаксимальное значение из " << a << " , " << b << " , " << c << " = " << m;
    }

    void stars()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "* ";
        }
    }

    void line(char symbol, int count)
    {
        for (int i = 0; i < count; i++)
        {
            cout << symbol << ' ';
        }
    }

    int count_digits(long long a)
    {
        int k = 0;
        while (a) {
            a /= 10;
            k++;
        }

        return k;

    }

    int digit_by_pos(long long n, int pos)
    {
        int k = count_digits(n); // количество цифр
        while (k > pos)
        {
            n /= 10;
            k--;
        }
        return n % 10;
    }
