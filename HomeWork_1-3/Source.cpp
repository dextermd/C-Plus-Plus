#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include "help_func.h"
#include "Movie.h"



using namespace std;

int main()
{

#if 0

    /*
        Задание 1. Написать программу, которая записывает в текстовый файл стихотворение(на ваш
            выбор).Считать информацию из файла и в новый файл записать следующую статистику по
            исходному файлу :
                -Имя файла;
                -Количество символов;
                -Количество строк;
                -Количество гласных букв;
                -Количество согласных букв;
                -Количество цифр.
     */

    FILE* file;
    errno_t err;
    char filename[10] = "data.txt";
    err = fopen_s(&file, filename, "w");
    int symbol = 0, row = 0, vowel = 0, consonant = 0, number = 0;

    char str[750] = "For shame deny that thou bear - st love to any,\n"
        "Who for thyself art so improvident.\n"
        "Grant, if thou wilt, thou art beloved of many,\n"
        "But that thou none lov'st is most evident;\n"
        "For thou art so possess'd with murd'rous hate\n"
        "That 'gainst thyself thou stick'st not to conspire,\n"
        "Seeking that beauteous roof to ruinate\n"
        "Which to repair should be thy chief desire :\n"
        "O change thy thought, that I may change my mind!\n"
        "Shall hate be fairer lodged than gentle love ?\n"
        "Be as thy presence is, graciousand kind,\n"
        "Or to thyself at least kind - hearted prove :\n"
        "Make thee another self, for love of me,\n"
        "That beauty still may live in thine or thee. 555\n";


    // Запись в файл 

    if (!err)
    {
        fputs(str, file);
        printf("\n\t\tTEXT WRITE OK!\n\n");
        printf("\t\t______________\n");

        fclose(file);
    }
    else {
        printf("\nОшибка записи в файл");
    }

    // Чтение из файла 
    printf("\n\t\tTEXT READ\n\n");
    file_info(filename, vowel, consonant, number, row, symbol);

    

#endif

#if 0
    /*
        Задание 2. 
        Дан текстовый файл(из задания 1).
        Найти длину самой длинной строки и вывести ее на экран(с указанием длины).
    */

    char filename[10] = "data.txt";
    file_get_max_row(filename);

#endif

#if 0
    /*
        Задание 3. Написать функцию, которая записывает в текстовый файл объект структуры
            «Фильм» из домашнего задания №31 - 32. Функция принимает файловый указатель и
            экземпляр структуры.Информацию оформить в удобном для пользователя формате, т.е.с
            указанием наименования полей : Название фильма, Режиссер и т.д.
            В отдельный файл записать массив объектов «Фильм» в текстовый файл.Массив объявлен и
            инициализирован на этапе разработки.
            Прочитать информацию из файла построчно и вывести данные на экран.
    */

    const int S = 9;
    char str[256];
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

    FILE* file = fopen("movie.txt", "w");;

    if (file)
    {
        save_and_read_movie(file, movies, S);

        fclose(file); 

        file = fopen("movie.txt", "r");

        while (!feof(file))
        {
            fgets(str, sizeof(str), file);
            printf("%s", str);
        }

        fclose(file);
    }


#endif

#if 0
    /*
        Задание 4. Написать программу, которая записывает массив объектов «Фильм» в двоичный
            файл.Массив объявлен и инициализирован на этапе разработки.
            Считать информацию из двоичного файла, проинициализировав данные нового массива
            объектов «Фильм».Вывести данные нового массива на экран.
    */

    const int S = 9;
    char str[256];
    Movie movies_new[S];
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

    FILE* file;
    errno_t err;
    err = fopen_s(&file, "movie_byte.txt", "wb");

    // Запись

    if (!err)
    {
        for (int i = 0; i < S; i++)
        {
            fwrite(movies + i, sizeof(movies), 1, file);
        }

        printf("\nOk\n");
        fclose(file);
    }
    else {
        printf("\nОшибка записи в файл");
    }

    // Запись в новую структуру из файла

    err = fopen_s(&file, "movie_byte.txt", "rb");
    if (!err)
    {
        for (int i = 0; i < S; i++)
        {
            fread(movies_new +i, sizeof(movies_new), 1, file);
        }
       
        fclose(file);

        show(movies_new, S);
    }
    else {
        printf("\nОшибка чтении файла");
    }



#endif


    _getch();
}