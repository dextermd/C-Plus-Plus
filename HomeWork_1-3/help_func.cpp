#include "help_func.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

void count(char s, int& vowel, int& consonant, int& number)
{

}


bool is_vowel(char s)
{
    char vowel[] = "aoueiy";
    for (int i = 0; i < vowel[i]; i++)
    {
        if (tolower(s) == vowel[i])
        {
            return true;
        }
    }
    return false;
}

bool is_consonant(char s)
{
    char consonant[] = "bcdfghjklmnpqrstvwxyz";
    for (int i = 0; i < consonant[i]; i++)
    {
        if (tolower(s) == consonant[i])
        {
            return true;
        }
    }
    return false;
}

void file_info(char filename[], int& vowel, int& consonant, int& number, int& row, int& symbol)
{
    FILE* file;
    errno_t err;
    err = fopen_s(&file, filename, "r");
    char s;

    if (!err)
    {

        while (!feof(file))
        {
            symbol += 1;

            s = fgetc(file);

            is_vowel(s) ? vowel += 1 : vowel;
            is_consonant(s) ? consonant += 1 : consonant;
            isdigit(s) ? number += 1 : number;
            s == '\n' ? row += 1 : row;

            if (feof(file)) break;
            printf("%c", s);
        }

        fclose(file);

        printf("\n\t\tTEXT STATISTIC\n");
        printf("\nИмя файла:\t\t\t %s", filename);
        printf("\nКоличество символов:\t\t %d", symbol);
        printf("\nКоличество строк:\t\t %d", row);
        printf("\nКоличество гласных букв:\t %d", vowel);
        printf("\nКоличество согласных букв:\t %d", consonant);
        printf("\nКоличество цифр:\t\t %d", number);
    }
    else {
        printf("\nОшибка чтения файла");
    }

}

void file_get_max_row(char filename[])
{
    char str[200];
    FILE* file;
    errno_t err;
    err = fopen_s(&file, filename, "r");
    int row = 0, finish_row = 0, symbol = 0, max = 0;
    char s;
    

    if (!err)
    {
        while (!feof(file))
        {
            symbol += 1;
            s = fgetc(file);
            if (s == '\n')
            {
                row += 1;
                max < symbol ? max = symbol, finish_row = row : max;
                symbol = 0;
            }
        }

        fclose(file);

        err = fopen_s(&file, filename, "r");

        for (int i = 0; i < row; i++)
        {
            fgets(str, sizeof(str), file);
            if (i == finish_row - 1)
            {
                printf("Строка номер %d: %s", finish_row, str);
            }

        }

        fclose(file);
    }
    else {
        printf("\nОшибка чтения файла");
    }
}


