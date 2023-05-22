#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <algorithm>
#include "help_func.h"



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

#if 1
    /*
        Задание 2. 
        Дан текстовый файл(из задания 1).
        Найти длину самой длинной строки и вывести ее на экран(с указанием длины).
    */

    char filename[10] = "data.txt";
    file_get_max_row(filename);

#endif


    _getch();
}