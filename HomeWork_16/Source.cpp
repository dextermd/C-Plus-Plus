#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


struct Movie {
    char name[30];
    char director[30];
    char genre[100];
    double rating;
    int price;
};

struct Washer {
    char company[50];
    char color[15];
    char dimensions[50];
    int power;
    int max_speed;
    int max_temperature;
    int price;
};

using namespace std;

void init(Movie& data);

void init(Washer& data);

void show(int* arr, int size);

void show(const Movie& mv);

void show(Movie* movie, int s);

void show(const Washer& ws);

void show(Washer* arr, int s);

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

#if 0
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
        Вывод на экран данных об объекте
         Инициализации одного экземпляра структуры с клавиатуры.
        Продемонстрируйте работу функций на примере экземпляра структуры и массива из 10 фильмов
        (массив инициализирован на этапе разработки).
    */

    Movie movie;

    init(movie);

    const int S = 10;
    Movie movies[S]{
        {"Marrowbone", "Sergio G. Sanchez", "Horror, Thrillers, Dramas", 6.82, 275},
        {"Gone Girl", "David Fincher", "Thrillers, Dramas, Adventures", 7.93, 300},
        {"Fight Club", "David Fincher", "Thrillers, Crime", 8.64, 400},
        {"Predestination", "Michael Spierig", "Science Fiction, Thrillers", 7.4, 200},
        {"Primal Fear", "Gregory King Hoblit", "Thrillers, Dramas, Crime", 7.82, 300},
        {"Saw", "James Wan", "Horror, Thrillers", 7.80, 230},
        {"A Cure for Wellness", "Gore Verbinski", "Thrillers, Detective Stories, Fantasy", 6.40, 150},
        {"Stonehearst Asylum", "Brad Anderson", "Thrillers", 7.15, 50},
        {"Get Out", "Jordan Peele’s ", "Horror, Detective Stories", 7.01, 100},
        movie
    };


    cout << "\nМассив фильмов: \n";
    show(movies, S);


  

#endif

#if 0
    // ---------------------------------------------------------------------------------------------------------------- //

    /*
        Задание 3: Реализуйте структуру «Стиральная машина» :
            фирма - производитель
            цвет
            размеры(ширина, глубина, высота)
            мощность
            максимальная скорость отжима
            максимальная температура нагрева
            стоимость.
        Создайте экземпляры структуры, и проиллюстрируйте работу с ними.Напишите функции для
        работы с этой структурой :
            Вывод на экран данных об объекте
            Инициализации одного экземпляра структуры с клавиатуры.
            Продемонстрируйте работу функций на примере экземпляра структуры и массива из 10 cтиральных машин
            (массив инициализирован на этапе разработки).
        */

    Washer w;

    init(w);

    const int S = 10;
    Washer arr[S]{
        {"Bosh", "White", "59.60х63.60х85", 1000, 900, 60, 600},
        {"Miele", "White", "59.80х59х84.80", 1300, 600, 90, 700},
        {"AEG L", "White", "59.60х63.60х85", 1400, 500, 60, 900},
        {"MAUNFELD", "Silver", "60 x 50 x 84.7", 1400, 600, 90, 400},
        {"ATLANT", "White", "59.60х55.50х84.60", 1600, 900, 70, 550},
        {"LG", "Black", "60х45х85", 1400, 800, 60, 700},
        {"Indesit", "White", "59.60х63.60х85", 1200, 900, 60, 300},
        {"Midea", "White", "59.50х33х85", 1400, 100, 60, 600},
        {"Hotpoint-Ariston", "Black", "59.60х63.60х85", 1400, 400, 100, 200},
        w
    };


    cout << "\nМассив стиральных машин: \n";
    show(arr, S);




#endif
    _getch();
}

void init(Movie& data)
{
    cout << "Инициализируйте один экземпляр фильма\n";
    cout << "\nНазвание фильма:             ";
    cin.getline(data.name, sizeof(data.name));
    cout << "\nРежиссер:            ";
    cin.getline(data.director, sizeof(data.director));
    cout << "\nЖанр:            ";
    cin.getline(data.genre, sizeof(data.genre));
    cout << "\nРейтинг популярности:            ";
    cin >> data.rating;
    cout << "\nЦена диска:              ";
    cin >> data.price;
}


void init(Washer& data)
{
    cout << "Инициализируйте один экземпляр стиральной машины\n";
    cout << "\nПроизводитель:                           ";
    cin.getline(data.company, sizeof(data.company));
    cout << "\nЦвет:                                    ";
    cin.getline(data.color, sizeof(data.color));
    cout << "\nРазмеры:                                 ";
    cin.getline(data.dimensions, sizeof(data.dimensions));
    cout << "\nМощность:                                ";
    cin >> data.power;
    cout << "\nМаксимальная скорость отжима:        ";
    cin >> data.max_speed;
    cout << "\nМаксимальная температура нагрева:        ";
    cin >> data.max_temperature;
    cout << "\nСтоимость:                               ";
    cin >> data.price;
}


void show(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}

void show(const Movie& mv)
{
    cout << "\nНазвание фильма:         " << mv.name;
    cout << "\nРежиссер:                " << mv.director;
    cout << "\nЖанр:                    " << mv.genre;
    cout << "\nРейтинг популярности:    " << mv.rating;
    cout << "\nЦена диска:              " << mv.price;
    cout << endl;
}

void show(const Washer& ws)
{
    cout << "\nФирма:                                       " << ws.company;
    cout << "\nЦвет:                                        " << ws.color;
    cout << "\nРазмеры:                                     " << ws.dimensions;
    cout << "\nМощность:                                    " << ws.power;
    cout << "\nМаксимальная скорость отжима:                " << ws.max_speed;
    cout << "\nМаксимальная температура нагрева:            " << ws.max_temperature;
    cout << "\nСтоимость:                                   " << ws.price;
    cout << endl;
}

void show(Washer* arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        show(arr[i]);
    }
}

void show(Movie* movie, int s)
{
    for (int i = 0; i < s; i++)
    {
        show(movie[i]);
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