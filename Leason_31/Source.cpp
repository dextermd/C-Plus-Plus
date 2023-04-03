#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm> // STL

using namespace std;

// Data  - Имя типа данных
struct Data {
    int day; // поля - свойства структуры
    int month;
    int year;
};

void show(const Data& d, bool p = false);

char* month_name(int n);


double add(int a, int b) { return a + b; }
double subtr(int a, int b) { return a - b; }
double mult(int a, int b) { return a * b; }
double division(int a, int b) { return (double)a / b; }

// третий параметар - указатель на функцию
double math_operation(int a, int b, double (*pf)(int, int))
{
    return pf(a, b);
    //return (*pf)(a, b);
}


// Функции для передачи фактического параметра для выбора критерии сортировки
bool cmp_incr(int a, int b) { return a > b; }
bool cmp_incr(double a, double b) { return  a > b; }

bool cmp_desc(int a, int b) { return a < b; }
bool cmp_desc(double a, double b) { return a < b; }

bool cmp_str_incr(const char* a, const char* b) { return strcmp(a, b) > 0; }

void sort(int* arr, int size, bool (*pf)(int, int) = cmp_incr);

template<class Type>
void sort(Type* arr, int size, bool (*pf)(Type, Type))
{
    cout << "\n****Шаблон функции sort****\n";
    Type t;

    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size - 1; k++)
        {
            // if (arr[k] > arr[k + 1]) // Критерий сортировки
            // if (arr[k] > arr[k + 1]) // Критерий сортировки
            if (pf(arr[k], arr[k + 1])) // Критерий сортировки зависит от фактического параметра
            {
                t = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = t;
            }
        }
    }
}

int main()
{

    // --------------------------------------------------------------------------------------------------------------- \\
    // -------------------------------------- Указатели на функции --------------------------------------------------- \\

#if 0
    // --------------------------------------------------------------------------------------------------------------- \\

    cout << "\nАдрес функции : " << setprecision(2) << fixed << add << endl;
    
    // Обьявление указателя на функцию:

    double (*p)(int, int);
    cout << "\nОбьем памяти: " << sizeof(p) << endl;

    // Инициализация указателя p:

    p = add;

    cout << "\nСумма: " << (*p)(5, 11);
    cout << "\nСумма: " << p(5, 11);

    p = subtr;
    
    cout << "\nВычитание: " << (*p)(5, 11);
    cout << "\nВычитание: " << p(5, 11);
    
    p = division;

    cout << "\nДеление: " << (*p)(5, 11);
    cout << "\nДеление: " << p(5, 11);
    
    p = mult;
    
    cout << "\nУмножение: " << (*p)(5, 11);
    cout << "\nУмножение: " << p(5, 11) << endl << endl;


    // ----------------------------------------------------------------------------------------------------- \\
    // Массив указателей на функцию
    const int N = 4;
    double (*ptr_arr[N])(int, int);

    ptr_arr[0] = add;
    ptr_arr[1] = subtr;
    ptr_arr[2] = mult;
    ptr_arr[3] = division;

    int a = 25, b = 7;

    cout << "\nВызов функции через указатели на функции (массив указателей): \n";

    for (int i = 0; i < N; i++)
    {
        cout << ptr_arr[i](a, b) << " ";
    }

    cout << endl << endl;

    // ----------------------------------------------------------------------------------------------------- \\
    // Указатели на функцию как параметры функций
    // ----------------------------------------------------------------------------------------------------- \\
    // Написать функцию, которая принимает два целых числа и выполняет одну из
    // арифметических опреаций, в зависимости от третьего параметра(указатель на функцию).

    int k1 = 6, k2 = 10;

    cout << "\nСумма: " << math_operation(k1, k2, add);
    cout << "\nВычитание: " << math_operation(k1, k2, subtr);
    cout << "\nУмножение: " << math_operation(k1, k2, mult);
    cout << "\nДеление: " << math_operation(k1, k2, division);

    cout << endl << endl;

    // ----------------------------------------------------------------------------------------------------- \\
    // Указатели на функцию как параметры функций
    // Написать функцию сортировки одномерного массива
    // Критерий сортировки передается третьим параметром в качестве указателя на функцию

    const int M = 10;
    //double arr[M]{ 25, -6, 9, 78, -69, 45, 360, -123, 69, 456 };
    int arr[M]{ 25, -6, 9, 78, -69, 45, 360, -123, 69, 456 };

    cout << "\nМассива до сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

    sort(arr, M, cmp_incr);

    cout << "\nМассива после сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

    //sort<double>(arr, M, cmp_desc);
    sort<int>(arr, M, cmp_desc);

    cout << "\nМассива после сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

    cout << endl << endl;

    const char* ms[4]{ "Карандаш","Тетрадь","Альбом","Блокнот" };

    for (const char* v : ms)
    {
        cout << v << " ";
    }


    sort(ms, 4, cmp_str_incr);

    cout << "\nМассива после сортировки в алфивитном порядке: \n";

    for (const char* v : ms)
    {
        cout << v << " ";
    }


#endif



    // ----------------------------------------------------------------------------------------------------- \\


#if 0
    // ----------------------------------------------------------------------------------------------------- \\
    // Отсортировать массивы с использованием алгоритмов sort из STL

    const int M = 10;
    //double arr[M]{ 25, -6, 9, 78, -69, 45, 360, -123, 69, 456 };
    int arr[M]{ 25, -6, 9, 78, -69, 45, 360, -123, 69, 456 };

    cout << "\nМассива до сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

    sort(arr, &arr[M]); // По умолчанию знак меньше -> sort из STL  #include <algorithm>

    cout << "\nМассива после сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

    sort(arr, &arr[M], cmp_incr); // По умолчанию знак меньше -> sort из STL  #include <algorithm>

    cout << "\nМассива после сортировки: \n";

    for (int v : arr)
    {
        cout << v << " ";
    }

#endif


#if 1
    // ------------------------------------- Структуры ----------------------------------------------------- \\
    // ----------------------------------------------------------------------------------------------------- \\
    // Описать сруктуры для хранения даты (день,месяц,год)

    // Обьявления обьекта /  экземпляра структуры Data

    Data a;
    cout << "\nОбьем памяти: " << sizeof(a) << endl;
    
    // Инициализация обьекта через доступ к полям структуры
   
    a.day = 3;
    a.month = 4;
    a.year = 2023;

    //cout << a.day << "." << a.month << "." << a.year << endl;
    show(a);

    // Инициалтзация обьекта на этапе  разработки
    Data b{25, 5, 2023};

    //cout << b.day << "." << b.month << "." << b.year << endl;
    show(b);

    cout << endl << endl;

    cout << month_name(4) << endl;

    cout << endl << endl;

    show(b, true);
    // ----------------------------------------------------------------------------------------------------- \\
    // Реализовать функции для вывода данных объекта на экран

    
#endif







    _getch();
}



void show(const Data& d, bool p)
{
    if (p)
    {
        cout << d.day << " " << month_name(d.month) << " " << d.year << endl;
    }
    else {
        cout << d.day << "." << d.month << "." << d.year << endl;
    }
    
}

char* month_name(int n)
{
    // статическая переменая должна быть  обьявлена и одновременно проинициализирована !!!!!!
    static char name[][20]{
        "none", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    return (n >= 1 && n <= 12) ? name[n] : name[0];
}



void sort(int* arr, int size, bool (*pf)(int, int))
{
    cout << "\n****Функция сортировки sort для Int****\n";
    int t;

    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size - 1; k++)
        {
            // if (arr[k] > arr[k + 1]) // Критерий сортировки
            // if (arr[k] > arr[k + 1]) // Критерий сортировки
            if (pf(arr[k], arr[k + 1])) // Критерий сортировки зависит от фактического параметра
            {
                t = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = t;
            }
        }
    }
}
