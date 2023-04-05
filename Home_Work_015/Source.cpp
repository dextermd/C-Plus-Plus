#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <string>

using namespace std;




int main()
{


#if 0

    // --------------------------------------------------------------------------------------------------------------- \\
    //  Задание 1: Дан массив строк (проинициализирован). Вывести массив на экран, после каждой
    //  строки в скобках указать ее длину.Определить и вывести на экран строку с максимальной
    //  длиной и ее позицию в массиве.
    //  Пример работы программы :
    //  Кишинев(7)
    //  Бухарест(8)
    //  Киев(4)
    //  Рим(3)
    //  Вашингтон(9)
    //  Строка максимальной длины : Вашингтон(9), порядковый номер : 5

    const int ROW = 5, COL = 30;
    int max = 0, index = 0;
    char str[ROW][COL] = { 
                            "Kishinev",
                            "Bucharest",
                            "Washington",
                            "Kyiv",
                            "Rome",     
    };

    for (int i = 0; i < ROW; i++)
    {
        int g = 0;

        for (int j = 0; str[i][j]; j++)
        {
            if (str[i][j])
            {
                g++;
            }

            max < g ? max = g : max;
            cout << str[i][j];
        }
        cout << "("<< g << ")" << endl;
    }

    for (int i = 0; i < ROW; i++)
    {
        if (max == strlen(str[i])) {

            cout << "Строка максимальной длины : " << str[i] << "(" << max << ")" << ", порядковый номер : " << i + 1;
        }

    }

#endif

#if 0

    //    Задание 2: Дан массив строк.Напишите программу, которая выводит его на экран, указав после
    //    каждого слова строки в скобках его длину, а ниже каждой строки вывести :
    // 
    //    -количество слов в текущей строке
    //    - слово максимальной длины в текущей строке
    //    - слово минимальной длины в текущей строке
    // 
    //    Например, исходный массив строк :
    //      My name is Artur.
    //      I am learning C++ programming language.
    // 
    //    Пример работы программы :
    //      My(2) name(4) is(2) Artur(5).
    //      Количество слов в строке : 4
    //      Слово максимальной длины : Artur
    //      Слово минимальной длины : My
    // 
    //      I(1) am(2) learning(8) C++(3) programming(11) language(8)
    //      Количество слов в строке : 6
    //      Слово максимальной длины : programming
    //      Слово минимальной длины : I
    // 
    //    * Можно добавить вывод всех слов минимальной и максимальной длины в текущей строке,
    //    если таковые есть.Например :
    // 
    //      My(2) name(4) is(2) Artur(5).
    //      Слово максимальной длины : Artur
    //      Слова минимальной длины : My, is

    const int ROW = 2, COL = 50;
    char str[ROW][COL] = { "My name is  Artur.", "I am learning C++ programming language." };
    int num = 0, value = 1, value2 = 1;
    char min[20], max[20];
    for (int i = 0; i < ROW; i++)
    {
        num = 0;

        for (int j = 0; str[i][j]; j++)
        {
            str[i][j] == '.' ? str[i][j] = ' ' : str[i][j];
        }

        char* token = strtok(str[i], " ");
        strcpy(min, token);
        while (token != NULL) {
            value2 >= strlen(token) ? value2 = strlen(token), strcpy(min, token) : token;
            value <= strlen(token) ? value = strlen(token), strcpy(max, token) : token;
            
            num++;
            cout << token << "(" << strlen(token) << ") ";

            token = strtok(NULL, " ");

         }
        
        cout << endl;
        cout << "Количество слов в строке : " << num << endl;;
        cout << "Слово максимальной длины : " << max << endl;;
        cout << "Слово минимальной длины : " << min << endl;;
        cout << endl;
    }


#endif




    _getch();
}