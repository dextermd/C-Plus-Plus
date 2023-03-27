#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>

using namespace std;



bool is_cifra(char s)
{   // 48 - 57 || '0' - '9'
    return (s >= '0' && s <= '9');
}

bool is_glas(char s) // aoueiyAOUEIY
{
    char gl[] = "aoueiyAOUEIY";
    for (int i = 0; i < gl[i]; i++)
    {
        if (s == gl[i])
        {
            return true;
        }
    }
    return false;
}

bool is_cyril(char s)
{
    return (s >= 'А' && s <= 'я');
}

void revers(const char* s) // test --> tset
{
    int count = strlen(s) - 1;
    for (; count > 0; count--)
    {
        cout << s[count];
    }
}

void func(int arr[], int s, int& max, int& summa)
{
    max = arr[0];
    summa = 0;
    for (int i = 0; i < s; i++)
    {
        summa += arr[i];
        max > arr[i] ? max : max = arr[i];
    }

}


int main()
{

#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    // Повторение ссылок.

    int arr[5]{ 20,9,-6,4,7 }, max, summa;

    func(arr, 5, max, summa);

    cout << "\nMax = " << max;
    cout << "\nSumma = " << summa;

#endif

#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\

    char s1[20] = "Hello", s2[20];
    strcpy_s(s2, s1);
    cout << s2 << endl;

    // Выделение памяти под строку динамически

    char buf[200];
    cout << "\nВведите строку: ";
    cin.getline(buf, sizeof(buf)); // Hello, world!

    char* str = new char[strlen(buf) + 1]; // + 1 для нул терминатора
    if (str)
    {
        strcpy_s(str, strlen(buf) + 1, buf); // 3 параментра !!!
        cout << "\nВаша строка: " << str;
        cout << "\nДлина  строка: " << strlen(str);
        // ... Подчищаем обязательно !
        delete[]str;
        str = nullptr;
    }

#endif


#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    // Поиск строк strchr
    //    char * strchr(const char *s, int c); библиотечная функция     
    //    — Ищет в строке s
    //    первое вхождение символа c, начиная с начала
    //    строки. В случае успеха возвращает указатель
    //    на найденный символ, иначе возвращает нуль(nullptr).

    char str[] = "123-456-789-654-123!", s = '-';
    int count = 0;

    //for (int i = 0; str[i]; i++)
    //{
    //    str[i] == s ? count++ : count;
    //}

    int index;
    char* p = strchr(str, s);
    if (p)
    {
        index = p - str; // таким образом мы узнаем индекс первого значения который мы искади  s = '-' в str[] = "123-456-789-654-123!" тоесть index должен быть равен 3
        cout << "\nIndex '-' в str =  " << index << endl;
        cout << *p << " " << p[0] << " " << str[index];
    }
    else {
        cout << "\nСимвола в строке нет";
    }

#endif


#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    // Поиск строк strchr
    /*
        Самостоятельно:
        Найти и вывести на экран индексы всех
        вхождений символа в строку
    */

    char str[] = "123 w 456 w 789 w 654 w 123!", s = 'w';
    int count = 0;

    int index;
    char* p = strchr(str, s);
    if (p)
    {
        while (p) {
            index = p - str;
            cout << "\nIndex 'w' в str =  " << index << endl;
            str[index] = toupper(str[index]);
            p++;
            p = strchr(p, s);
        }
        cout << endl << str << endl;
    }
    else {
        cout << "\nСимвола в строке нет";
    }


#endif

#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    // Поиск подстроки в строке strstr

    char str[] = "Hello, stringstring stroka, hello", sub_str[] = "ings";

    char* p = strstr(str, sub_str);
    int index = 0;

    if (p)
    {
        index = p - str;
        cout << "\nИндекс первого вхождения: " << index;
    }
    else {
        cout << "\nПодстроки в троке нет";
    }

#endif


#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    // Поиск подстроки в строке strstr Все вхождения
    // Найти все вхождения подстроки в строку, вывести индексы вхождений на экран
    // и перевести найденную подстроку в строке в верхний регистр
    //   

    char str[] = "hello, stringstrings stroka, stringshello", sub_str[] = "hello";
    int k = strlen(sub_str);
    char* p = strstr(str, sub_str);
    int index = 0;

    if (p)
    {
        while (p)
        {
            index = p - str;

            for (int i = 0; i < k; i++)
            {
                p[i] = toupper(p[i]);
            }

            cout << "\nИндекс первого вхождения: " << index;
            p += k;
            p = strstr(p, sub_str);
        }
        cout << endl << str;
    }
    else {
        cout << "\nПодстроки в троке нет";
    }

#endif



#if 0
    // -------------------------------------------------------------------------------------------------------------------------- \\
    
    /*
        Функция strtok     Дана строка текста.     
        1. Посчитать количество слов.     
        2. Вывести каждое  слово(лексему) с новой строки.     
        3. Перевести первую букву каждого слова в верхний регистр,
        остальные символы - в нижний регистр     
    */

    char str[100] = "CAT, dog, bruclin gold, bibizon.", copy_str[100];
    strcpy_s(copy_str, str);

    char* t1, *t2;
    int words = 0;
    //t1 = strtok_s(str, ", .!", &t2); // Первый вызов функции
    //cout << t1 << endl;
    //cout << t2 << endl;


    //t1 = strtok_s(nullptr, ", .!", &t2); // Второй вызов функции и все последующие  первый параметр должен быть nullptr
    //cout << t1 << endl;
    //cout << t2 << endl;

    // Поиск и вывод на экран всех лексем
    t1 = strtok_s(str, ", .!", &t2); // Первый вызов функции
    while (t1)
    {
        _strlwr_s(t1, strlen(t1)+1);
        *t1 = toupper(*t1);

        cout << t1 << endl;
        t1 = strtok_s(nullptr, ", .!", &t2);
        words++;
    }
    cout << "\nКоличество слов: " << words;
    cout << "\nСтрока после использования функции : " << str;
    cout << "\nКопия строки : " << copy_str;

#endif



#if 1
    // -------------------------------------------------------------------------------------------------------------------------- \\
    
    // Запись лексем строки в массив целого типа
    // (с динамическим выделением памяти).     
    
    /*Дана строка символов: "20  3058  15  -18   9  12  600  98751  12  -1548"
    На основе строки сформировать динамический одномерный
        массив целых чисел.Использовать алгоритм :
    -Объявить и проинициализировать строку
        - Сделать копию строки
        - Посчитать количество лексем в строке         - Выделить динамически память под одномерный массив целых
        размером по количеству лексем         - Для копии строки :
    -пройтись по лексемам, каждую преобразовать
        в целое число(atoi(t1)) и записать
        в одномерный массив целых
        - Вывести одномерный массив целых на экран
        - Освободить память
        */

    char str[100] = "20  3058  15  -18   9  12  600  98751  12  -1548", copy_str[100];
    strcpy_s(copy_str, str);

    char* t1, * t2;
    int k = 0;

    t1 = strtok_s(str, " ", &t2); // Первый вызов функции
    while (t1)
    {
        t1 = strtok_s(nullptr, ", .!", &t2);
        k++;
    }

    cout << "\nКоличество ликсем : " << k;
    int* arr = new int[k];

    strcpy_s(str, copy_str);

    if (arr)
    {
        int  i = 0;
        t1 = strtok_s(str, " ", &t2);
        while (t1)
        {
            arr[i++] = atoi(t1);
            t1 = strtok_s(nullptr, " ", &t2);
        }
    }
    
    cout << "\nДинамический массив целых: \n";

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    delete[]arr;
    arr = nullptr;

#endif

    _getch();
}