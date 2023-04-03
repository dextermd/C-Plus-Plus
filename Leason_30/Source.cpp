#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>

using namespace std;

int find(char** arr, int row, char *findKey);

int find(char** arr, int row, char* findKey)
{
    for (int i = 0; i < row; i++)
    {
        if (strcmp(arr[i], findKey) == 0)
        {
            return i;
        }
    }

    return -1;
}


int main()
{

    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\

#if 0

    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\

    // Инициализация на этапе разработки

    const int ROW = 6, COL = 30;

    char arr[ROW][COL] = {  "pear",
                            "mango", 
                            "kiwi", 
                            "apple", 
                            "manana", 
                            "apricot" 
    };

    // Вывод массива в прямом порядке, вариант 1 (посимвольный)
    // Перевести первую букву каждой строки в верхний регистр
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; arr[i][j]; j++)
        {
            arr[i][0] = toupper(arr[i][0]);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    // Вывод массива в прямом порядке, вариант 2 (построчный)
    for (int i = 0; i < ROW; i++)
    {
        cout << arr[i] << endl;
    }

    cout << endl << endl;

    // Вывод массива в обратном порядке
    /*for (int i = ROW - 1; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }*/

    for (int i = 0; i < ROW; i++)
    {
        cout << arr[ROW - 1 - i] << endl;
    }

#endif

    
#if 0
    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\

    /*
     Объявить статический массив строк для хранения
     пяти названий городов (максимальная длина названия
     города 40 символов).
     Проинициализировать массив с клавиатуры и
     вывести на экран.
     */

    const int R = 5, C = 40;
    char city[R][C];

    cout << "\nВведите  название пяти городов: \n";
    for (int i = 0; i < R; i++)
    {
        cout << i + 1 << ": ";
        cin.getline(city[i], sizeof(city[i]));
    }

    cout << "\nМассив городов: \n";

    for (int i = 0; i < R; i++)
    {
        cout << city[i] << " ";
    }

#endif


#if 0
    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\
    // Функция сравнения двух строк по кодировке  символов -> strcmp

    {
        char s1[] = "apricot", s2[] = "apple";
        cout << strcmp(s1, s2) << endl; //1  s1 > s2
    }

    {
        char s1[] = "apple", s2[] = "apple";
        cout << strcmp(s1, s2) << endl; //0  s1 == s2
    }

    {
        char s1[] = "apple", s2[] = "pear";
        cout << strcmp(s1, s2) << endl; //-1  s1 < s2
    }

    /*
          strcmp(s1, s2)  , возврат:
              0, если s1 == s2, т.е. строки одинаковы
              1, если s1 > s2 , т.е. кодировка первого несовпадающего символа первой строки
                              больше кодировки первого несовпадающего символа второй строки

              -1, если  s1 < s2, т.е. кодировка первого несовпадающего символа первой строки
                              меньше кодировки первого несовпадающего символа второй строки
    */

    const int ROW = 6, COL = 30;
    char arr[ROW][COL] = { "pear",
                            "mango",
                            "kiwi",
                            "apple",
                            "manana",
                            "apricot"
    };


    for (int i = 0; i < ROW; i++)
    {
        cout << arr[i] << endl;
    }

    cout << endl << endl;

    char t[COL];

    for (int i = 0; i < ROW; i++)
    {
        for (int k = 0; k < ROW - 1; k++)
        {
            int  b = strcmp(arr[k], arr[k + 1]); 

            // if (b > 0) //в обрпатном порядке порядке
            if (b > 0) //в алфавитном порядке
            {
                strcpy_s(t, arr[k]);
                strcpy_s(arr[k], arr[k + 1]);
                strcpy_s(arr[k + 1], t);
            }
        }
    }

    cout << "\nМассив после сортировки: \n\n";

    for (int i = 0; i < ROW; i++)
    {
        cout << arr[i] << endl;
    }


#endif


#if 0

    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\
    // Поиск строки в массиве строк -> strcmp

    const int ROW = 6, COL = 30;
    char arr[ROW][COL] = { "pear",
                            "mango",
                            "kiwi",
                            "apple",
                            "manana",
                            "apricot"
    };

    char find[COL];
    bool b = false;
    int number = 0;
    for (int i = 0; i < ROW; i++)
    {
        cout << arr[i] << endl;
    }

    cout << endl << endl;

    cout << "\nВведи название товара для поиска: ";
    cin.getline(find, sizeof(find));

    for (int i = 0; i < ROW; i++)
    {
        if (strcmp(find, arr[i]) == 0)
        {
            b = true;
            number = i + 1;
            break;
        }
        
    }

    b ? cout << "\nТовар есть в списке" : cout << "\nТовар нет в списке";

    cout << endl << number;

#endif

#if 0
    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\
    // Динамический массив строк
    // Инициализация с клавиатуры

    char buf[256];
    int row;
    cout << "\nВведи количество строк: ";
    cin >> row;
    cin.get(); // Считываение нажатой клавишы Enter. Если после cin используется cin.getline() надо между ними  использовать cin.get()

    char** arr = new char* [row];

    if (arr)
    {
        for (int i = 0; i < row; i++)
        {
            cout << "\nВведи строку " << i + 1 << ": ";
            cin.getline(buf, sizeof(buf));

            arr[i] = new char[strlen(buf) + 1]; //  выделение памяти под каждую строку
            strcpy_s(arr[i], strlen(buf) + 1, buf); // (3 параметра) копирование содержимого каждой строки
        }
    }

    for (int i = 0; i < row; i++)
    {
        cout << arr[i] << endl;
    }



    // --------------------------------------------------------------------------------------------------------------- \\
   
    /*
    Написать функцию, которая осуществояет поиск строки в
        динамическом массиве строк   (задача выше).
        В случае успеха - возвращает индекс строки,
        в противном случае - -1.
    */



    if (arr)
    {
        char findKey[200];

        cout << "\nВведите строку для поиска: ";
        cin.getline(findKey, sizeof(findKey));

        int index;
        index = find(arr, row, findKey);


        if (index >= 0)
        {
            cout << "\nМы нашли " << findKey << " порядковый номер = " << index + 1;
        }
        else {
            cout << "\nСтрока не найдена";
        }


        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
        arr = nullptr;
    }



#endif


#if 1
    // --------------------------------------------------------------------------------------------------------------- \\
    // ------------------------------------------- МАССИВЫ СТРОК ----------------------------------------------------- \\
    
    /*
        Инициализация динамического массива строк лексемами строки
        Записать слова(лексемы) строки в динамический массив строк.
        Исключить знаки препинания.
    */

    /*
        Использовать алгоритм:
            - Объявить и проинициализировать строку
            - Сделать копию строки, т.к. функция strtok "режет" строку, в ней остается первая лексема
            - Посчитать количество лексем в строке

            - Выделить динамически память под массив строк
              размером по количеству лексем

            - Для копии строки:
            - проинициализировать адреса строк массива строк, т.к. выделить память под каждую строку массива строк
            -  пройтись лексемам и записать в массив в текущую строку
            - Вывести массив строк  на экран
            - Освободить память
        */

    char str[200] = "Карандаш красный,Ручка шариковая,Линейка деревянная,Линейка пластиковая,Маркер,Бумага белая";
    char str_copy[200];

    strcpy_s(str_copy, str);

    char* t1, * t2;
    t1 = strtok_s(str, ",.;", &t2);
    int k = 0;

    while (t1)
    {
        cout << t1 << endl;
        t1 = strtok_s(nullptr, ",.;", &t2);
        k++;
    }


    cout << "\nКоличество лексем: " << k << endl << endl;
    strcpy_s(str, str_copy);

    char** arr = new char*[k];

    if (arr)
    {
        t1 = strtok_s(str, ",.;", &t2);

        for (int i = 0; i < k; i++)
        {
            arr[i] = new char[strlen(t1) + 1];
            strcpy_s(arr[i], strlen(t1) + 1 , t1);

            t1 = strtok_s(nullptr, ",.;", &t2);
        }

        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << endl;
        }

        for (int i = 0; i < k; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
        arr = nullptr;
    }


#endif


    _getch();
}

