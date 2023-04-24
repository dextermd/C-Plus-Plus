#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;


template<class Type>
void sort(Type* mas, int size, bool (*pf)(const Type&, const Type&))
{
    Type t;
    for (int i = 0; i < size - 1; i++)
    {
        for (int k = 0; k < size - 1; k++)
        {
            if ((*pf)(mas[k], mas[k + 1]))
            {
                t = mas[k];
                mas[k] = mas[k + 1];
                mas[k + 1] = t;
            }
        }
    }
}

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



void show_washer_price_min(Washer* m, int size);

void show_washer_price_max(Washer* m, int size);

bool show_diapozon(Washer* m, int size, int min, int max);

bool show_company(Washer* m, int size, const char* company);

bool sort_by_power_decr(const Washer& a, const Washer& b);

bool sort_by_power_incr(const Washer& a, const Washer& b);

bool sort_by_color_decr(const Washer& a, const Washer& b);

bool sort_by_color_incr(const Washer& a, const Washer& b);

bool sort_by_price_decr(const Washer& a, const Washer& b);

bool sort_by_price_incr(const Washer& a, const Washer& b);

bool sort_by_company_decr(const Washer& a, const Washer& b);

bool sort_by_company_incr(const Washer& a, const Washer& b);

void show_genre_best(Movie* m, int size, const char* genre);

bool show_genre(Movie* m, int size, const char* genre);

bool show_director(Movie* m, int size, const char* director);

bool show_movie(Movie* m, int size, const char* name);

bool sort_by_price_decr(const Movie& a, const Movie& b);

bool sort_by_price_incr(const Movie& a, const Movie& b);

void sort_by_director(Movie* mas, int size, bool order = true);

bool sort_by_rating_decr(const Movie& a, const Movie& b);

bool sort_by_rating_incr(const Movie& a, const Movie& b);

bool sort_by_director_decr(const Movie& a, const Movie& b);

bool sort_by_director_incr(const Movie& a, const Movie& b);

bool sort_by_name_decr(const Movie& a, const Movie& b);

bool sort_by_name_incr(const Movie& a, const Movie& b);

void show(const Movie& mv);

void show(Movie* movie, int s);

void show(const Washer& ws);

void show(Washer* arr, int s);

void destroy(int*& arr);



int main()
{

    //setlocale(LC_ALL, "rus");



#if 1
    // ---------------------------------------------------------------------------------------------------------------- //

    /*
        Задание 1: Напишите программу «Видеомагазин».Используйте структуру «Фильм» из
            предыдущего домашнего задания.Реализуйте следующие возможности обработки массива
            структур(функции) для выполнения в пользовательском меню :

        1. Сортировка массива по :
             названию фильма в алфавитном и обратном порядке
             режиссеру фильма в алфавитном и обратном порядке
             жанру фильма в алфавитном и обратном порядке
             по рейтингу популярности в порядке убывания
             по цене диска в порядке возрастания
       2. Поиск по :
             названию, отобразить данные найденного фильма
             жанру, отобразить все фильмы жанра
             режиссеру, отобразить все фильмы режиссера

       3. Самый популярный фильм(ы) в жанре

       4. Показ всех записей

       5. Выход из меню.

       Продемонстрируйте работу программы на примере массива из 10 фильмов(массив
       инициализирован на этапе разработки).
    */

    int menu = 0, submenu = 0, submenu_two = 0;
    const int S = 9;
    Movie movies[S]{
        {"Marrowbone", "Sergio G. Sanchez", "Horror", 6.82, 275},
        {"Gone Girl", "David Fincher", "Dramas", 7.93, 300},
        {"Fight Club", "David Fincher", "Crime", 8.64, 400},
        {"Predestination", "Michael Spierig", "Detective", 7.4, 200},
        {"Primal Fear", "Gregory King Hoblit", "Thrillers", 7.82, 300},
        {"Saw", "James Wan", "Horror", 7.80, 230},
        {"A Cure for Wellness", "Gore Verbinski", "Fantasy", 6.40, 150},
        {"Stonehearst Asylum", "Brad Anderson", "Thrillers", 7.15, 50},
        {"Get Out", "Jordan Peele’s ", "Detective", 7.01, 100},
    };

    do{
        cout << "\n\n************* (Видеомагазин) *************\n";
        cout << "\nВыберите пункт меню: \n\n";
        cout << "1.Сортировка \n";
        cout << "2.Поиск \n";
        cout << "3.Самый популярный фильм(ы) в жанре \n";
        cout << "4.Показ всех записей \n";
        cout << "5.Выход из меню \n";
        cout << "\nВведите пункт от 1 до 5: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            system("cls");
            do
            {
                cout << "\nСортировка массива по : \n\n";
                cout << "1.Названию фильма в алфавитном.\n";
                cout << "2.Названию фильма в обратном порядке.\n";
                cout << "3.Режиссеру фильма в алфавитном.\n";
                cout << "4.Режиссеру фильма в обратном порядке.\n";
                cout << "5.По рейтингу популярности в порядке убывания.\n";
                cout << "6.По цене диска в порядке возрастания.\n";
                cout << "7.Выход.\n";
                cout << "\nВведите пункт от 1 до 7: ";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                    system("cls");
                    sort(movies, S, sort_by_name_incr);
                    show(movies, S);
                    break;
                case 2:
                    system("cls");
                    sort(movies, S, sort_by_name_decr);
                    show(movies, S);
                    break;
                case 3:
                    system("cls");
                    //sort_by_director(movies, S, true);
                    sort(movies, S, sort_by_director_incr);
                    show(movies, S);
                    break;
                case 4:
                    system("cls");
                    //sort_by_director(movies, S, false);
                    sort(movies, S, sort_by_director_decr);
                    show(movies, S);
                    break;
                case 5:
                    system("cls");
                    sort(movies, S, sort_by_rating_decr);
                    show(movies, S);
                    break;
                case 6:
                    system("cls");
                    sort(movies, S, sort_by_price_incr);
                    show(movies, S);
                    break;
                case 7:
                    submenu = 7;
                    system("cls");
                    break;
                }
                
            } while (submenu != 7);

            break;        
        case 2:
            system("cls");
            do
            {
                cout << "\nПоиск по: \n\n";
                cout << "1.Названию, отобразить данные найденного фильма.\n";
                cout << "2.Жанру, отобразить все фильмы жанра.\n";
                cout << "3.Режиссеру, отобразить все фильмы режиссера.\n";
                cout << "4.Выход.\n";
                cout << "\nВведите пункт от 1 до 4: ";
                cin >> submenu_two;

                switch (submenu_two)
                {
                case 1:
                    bool pr;
                    char name_key[30];
                    system("cls");
                    cin.ignore(256, '\n');
                    cout << "\nВведите название фильма: " ;
                    cin.getline(name_key, sizeof(name_key));
                    pr = show_movie(movies, S, name_key);
                    if (!pr)
                    {
                        cout << "\nФильм не найден!\n";
                    }
                    break;
                case 2:
                    system("cls");
                    bool prr;
                    char genre_key[30];
                    system("cls");
                    cin.ignore(256, '\n');
                    cout << "\nВведите название жанра: ";
                    cin.getline(genre_key, sizeof(genre_key));
                    prr = show_genre(movies, S, genre_key);
                    if (!prr)
                    {
                        cout << "\nЖанр не найден!\n";
                    }
                    break;
                case 3:
                    system("cls");
                    bool prrr;
                    char director_key[30];
                    cin.ignore(256, '\n');
                    cout << "\nВведите режиссера: ";
                    cin.getline(director_key, sizeof(director_key));
                    prrr = show_director(movies, S, director_key);
                    if (!prrr)
                    {
                        cout << "\nРежиссер не найден!\n";
                    }
                    break;
                case 4:
                    submenu = 4;
                    system("cls");
                    break;
                }

            } while (submenu_two != 4);
            break;
        case 3:
            system("cls");
            bool tr;
            char genre[30];
            cin.ignore(256, '\n');
            cout << "\nВведите название жанра: ";
            cin.getline(genre, sizeof(genre));
            show_genre_best(movies, S, genre);

            break;        
        case 4:
            system("cls");
            cout << "\nВсе фильмы которые есть в налиции.\n";
            show(movies, S);
            break;        
        case 5:
            system("cls");
            menu = 5;
            cout << "Вы вышли из меню!";
            break;
        }

    } while (menu != 5);





#endif

#if 0
    // ---------------------------------------------------------------------------------------------------------------- //

    /*
    Задание 2: Напишите программу для уже имеющейся структуры «Стиральная машина» из
    предыдущего домашнего задания. Пусть существует уже проинициализированный массив
    стиральных машин размером десять. Организовать пользовательское меню, в котором
    реализовать следующие возможности:

    1. Сортировка массива по:
         фирме-производителю
         стоимости
         цвету
         мощности

    2. Поиск по:
         фирме-производителю, функция отображает все машины запрошенного
        производителя(либо по полному совпадению, либо по части имени)
         диапазону цены, функция отображает все машины, стоимость которых попадает в
        указанный диапазон цен

    3. Найти машину с максимальной стоимостью

    4. Найти машину с минимальной стоимостью

    5. Вывести на экран данные о всех все машинах с максимальной и минимальной
    стоимостью.

    6. Выход из меню.

    */

    const int S = 9;
    int menu = 0, submenu = 0, submenu_two = 0;
    int min = 0, max = 0;
    Washer washers[S]{
        {"Bosh", "White", "59.60х63.60х85", 1000, 900, 60, 600},
        {"Miele", "White", "59.80х59х84.80", 1300, 600, 90, 700},
        {"AEG L", "White", "59.60х63.60х85", 1400, 500, 60, 900},
        {"MAUNFELD", "Silver", "60 x 50 x 84.7", 1400, 600, 90, 400},
        {"ATLANT", "White", "59.60х55.50х84.60", 1600, 900, 70, 550},
        {"LG", "Black", "60х45х85", 1400, 800, 60, 700},
        {"Indesit", "White", "59.60х63.60х85", 1200, 900, 60, 300},
        {"Midea", "White", "59.50х33х85", 1400, 100, 60, 600},
        {"Hotpoint-Ariston", "Black", "59.60х63.60х85", 1400, 400, 100, 200},
    };


    do {
        cout << "\nВыберите пункт меню: \n\n";
        cout << "1.Сортировка \n";
        cout << "2.Поиск \n";
        cout << "3.Найти машину с максимальной стоимостью \n";
        cout << "4.Найти машину с минимальной стоимостью \n";
        cout << "5.Вывести на экран данные о всех все машинах с максимальной и минимальной стоимостью. \n";
        cout << "6.Выход из меню \n";
        cout << "\nВведите пункт от 1 до 6: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            system("cls");
            do
            {

                cout << "\nСортировка массива по : \n\n";
                cout << "1.Производителю\n";
                cout << "2.Cтоимости\n";
                cout << "3.Цвету\n";
                cout << "4.Мощности\n";
                cout << "5.Выход.\n";
                cout << "\nВведите пункт от 1 до 5: ";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                    system("cls");
                    sort(washers, S, sort_by_company_incr);
                    show(washers, S);
                    break;
                case 2:
                    system("cls");
                    sort(washers, S, sort_by_price_decr);
                    show(washers, S);
                    break;
                case 3:
                    system("cls");
                    sort(washers, S, sort_by_color_incr);
                    show(washers, S);
                    break;
                case 4:
                    system("cls");
                    sort(washers, S, sort_by_power_decr);
                    show(washers, S);
                    break;
                case 5:
                    submenu = 5;
                    system("cls");
                    break;
                }

            } while (submenu != 5);

            break;
        case 2:
            system("cls");
            do
            {
                cout << "\nПоиск по: \n\n";
                cout << "1.Фирме\n";
                cout << "2.Диапазону цены.\n";
                cout << "3.Выход.\n";
                cout << "\nВведите пункт от 1 до 3: ";
                cin >> submenu_two;

                switch (submenu_two)
                {
                case 1:
                    system("cls");
                    bool pr;
                    char company_key[30];
                    cin.ignore(256, '\n');
                    cout << "\nВведите название фирмы: ";
                    cin.getline(company_key, sizeof(company_key));
                    pr = show_company(washers, S, company_key);
                    if (!pr)
                    {
                        cout << "\nФирма не найдена!\n";
                    }
                    break;
                case 2:
                    system("cls");
                    bool prr;
                    cout << "\nВведите диапозон цен от (1) до (999999): \n";
                    cout << "От: ";
                    cin >> min;
                    cout << "До: ";
                    cin >> max;
                    prr = show_diapozon(washers, S, min, max);
                    if (!prr) 
                    {
                        cout << "\nДиапозон не найден!\n";
                    }
                    break;
                case 3:
                    submenu = 3;
                    system("cls");
                    break;
                }

            } while (submenu_two != 3);
            break;
        case 3:
            system("cls");
            show_washer_price_max(washers, S);
            break;
        case 4:
            system("cls");
            show_washer_price_min(washers, S);
            break;
        case 5:
            system("cls");
            show_washer_price_max(washers, S);
            show_washer_price_min(washers, S);
            break;
        case 6:
            system("cls");
            menu = 6;
            cout << "Вы вышли из меню!";
            break;
        }

    } while (menu != 6);




#endif


    _getch();
}

void show_genre_best(Movie* m, int size, const char* genre)
{
    Movie temp;
    temp = m[0];
    for (int i = 0; i < size; i++)
    {
        if (_strcmpi(m[i].genre, genre) == 0)
        {
            if (temp.rating < m[i].rating)
            {
                temp = m[i];
            }
        }
    }

    show(temp);
}


bool show_director(Movie* m, int size, const char* director)
{
    bool p = false;
    for (int i = 0; i < size; i++)
    {
        if (_strcmpi(m[i].director, director) == 0)
        {
            show(m[i]);
            p = true;
        }
    }
    return p;
}

bool show_genre(Movie* m, int size, const char* genre)
{
    bool p = false;
    for (int i = 0; i < size; i++)
    {
        if (_strcmpi(m[i].genre, genre) == 0)
        {
            show(m[i]);
            p = true;
        }
    }
    return p;
}

bool show_movie(Movie* m, int size, const char* name)
{
    bool p = false;
    for (int i = 0; i < size; i++)
    {
        if (_strcmpi(m[i].name, name) == 0)
        {
            show(m[i]);
            p = true;
        }
    }
    return p;
}


bool show_company(Washer* m, int size, const char* company)
{
    bool p = false;
    for (int i = 0; i < size; i++)
    {
        if (_strcmpi(m[i].company, company) == 0)
        {
            show(m[i]);
            p = true;
        }
    }
    return p;
}


bool show_diapozon(Washer* m, int size, int min, int max)
{
    bool p = false;
    for (int i = 0; i < size; i++)
    {
        if (m[i].price >= min && m[i].price <= max)
        {
            show(m[i]);
            p = true;
        }
    }
    return p;
}

void show_washer_price_min(Washer* m, int size)
{
    Washer temp;
    temp = m[0];
    for (int i = 1; i < size; i++)
    {
        if (temp.price > m[i].price)
        {
            temp = m[i];
        }
    }

    show(temp);
}

void show_washer_price_max(Washer* m, int size)
{
    Washer temp;
    temp = m[0];
    for (int i = 1; i < size; i++)
    {
        if (temp.price < m[i].price)
        {
            temp = m[i];
        }
    }

    show(temp);
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


void destroy(int*& arr)
{
    delete[]arr;
    arr = nullptr;
}

bool sort_by_price_decr(const Movie& a, const Movie& b)
{
    return a.price < b.price;
}

bool sort_by_price_incr(const Movie& a, const Movie& b)
{
    return a.price > b.price;
}

bool sort_by_rating_decr(const Movie& a, const Movie& b)
{
    return a.rating < b.rating;
}

bool sort_by_rating_incr(const Movie& a, const Movie& b)
{
    return a.rating > b.rating;
}

bool sort_by_director_decr(const Movie& a, const Movie& b)
{
    return _strcmpi(a.director, b.director) < 0;
}

bool sort_by_director_incr(const Movie& a, const Movie& b)
{
    return _strcmpi(a.director, b.director) > 0;

}

bool sort_by_name_decr(const Movie & a, const Movie & b)
{
    return _strcmpi(a.name, b.name) < 0;
}

bool sort_by_name_incr(const Movie & a, const Movie & b)
{
    return _strcmpi(a.name, b.name) > 0;
}

bool sort_by_company_decr(const Washer& a, const Washer& b)
{
    return _strcmpi(a.company, b.company) < 0;
}

bool sort_by_company_incr(const Washer& a, const Washer& b)
{
    return _strcmpi(a.company, b.company) > 0;
}

bool sort_by_price_decr(const Washer& a, const Washer& b)
{
    return a.price < b.price;
}

bool sort_by_price_incr(const Washer& a, const Washer& b)
{
    return a.price > b.price;
}

bool sort_by_color_decr(const Washer& a, const Washer& b)
{
    return _strcmpi(a.color, b.color) < 0;
}

bool sort_by_color_incr(const Washer& a, const Washer& b)
{
    return _strcmpi(a.color, b.color) > 0;
}


bool sort_by_power_decr(const Washer& a, const Washer& b)
{
    return a.power < b.power;
}

bool sort_by_power_incr(const Washer& a, const Washer& b)
{
    return a.power > b.power;
}

void sort_by_director(Movie* mas, int size, bool order)
{
    Movie temp;

    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size - 1 - i; k++)
        {
            
            if (_strcmpi(mas[k].director, mas[k + 1].director) > 0 && order == true)
            {
                temp = mas[k];
                mas[k] = mas[k + 1];
                mas[k + 1] = temp;
            }
            if (_strcmpi(mas[k].director, mas[k + 1].director) < 0 && order == false)
            {
                temp = mas[k];
                mas[k] = mas[k + 1];
                mas[k + 1] = temp;
            }
        }
    }
}