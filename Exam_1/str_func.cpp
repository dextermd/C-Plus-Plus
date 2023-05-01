#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include "str_func.h"
#include "color.h"

using namespace std;


bool is_сyrillic(char s)
{
    return (s >= 'А' && s <= 'я');

}

bool is_latin(char s)
{
    return (s >= 'A' && s <= 'z');
}

bool is_num_d(char s)
{   
    return s >= '0' && s <= '9';
}

bool is_punctuation(char s)
{
    char gl[] = ",.;:?!(){}'`~<>[]@#$%^&*_=+|//\\";
    for (int i = 0; i < gl[i]; i++)
    {
        if (s == gl[i])
        {
            return true;
        }
    }
    return false;
}

void show_str_color(char s[])
{
    cout << "\n\t\t\t";
    for (int i = 0; i < strlen(s) + 1; i++)
    {
        s[i] == ' ' ? cout << ' ' : cout;
        is_сyrillic(s[i]) ? (SetColor(4), cout << s[i]) : (SetColor(15), cout);
        is_latin(s[i]) ? (SetColor(6), cout << s[i]) : (SetColor(15), cout);
        is_num_d(s[i]) ? (SetColor(19), cout << s[i]) : (SetColor(15), cout);
        is_punctuation(s[i]) ? (SetColor(12), cout << s[i]) : (SetColor(15), cout);
    }
    SetColor(15);
    cout << endl;
}



