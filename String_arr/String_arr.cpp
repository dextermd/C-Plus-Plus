#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;


int main()
{

    //setlocale(LC_ALL, "rus");

    // ---------------------------------------------------------------------------------------------------------------- //
    // ****************************************** Строки массив символов ********************************************** //

    char arr[5]{ '+','-' ,'*' ,'/' ,'%' }; 
    char arr2[5]{ 'H','e' ,'l' ,'l' ,'o' }; // не строка, а набор символов

    for (char value : arr) 
    {
        cout << value << ' ';
    }

    cout << endl << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

 
    cout << endl << endl;
    cout << "\nОбьем памяти под массив символов " << sizeof(arr) << endl;

    for (char value : arr2)
    {
        cout << value << ' ';
    }

    char str[6]{ 'H','e' ,'l' ,'l' ,'o', '\0'}; // строка ('\0' к конце массива из символов превращает  этио все в строку)
    cout << "\nОбьем памяти под массив символов " << sizeof(str) << endl;


    // Обьявление и инициализация строки -----------------------------------------------------------------------------------

    char surname[20] = "Ivanov"; // именованная строка
    //char surname[] = "Ivanov"; // именованная строка
    cout << "\nОбьем памяти под массив символов " << sizeof(surname) << endl;

    // Вывод строки на экран  - 1
    cout << surname << endl;

    // Вывод строки на экран  - 2
    //for (int i = 0; i < surname[i] != '\0'; i++)
    for (int i = 0; i < surname[i]; i++)
    {
        cout << surname[i] << ' ';
    }

    cout << endl << endl;

    // Вывод строки с клавиатуры: 

    char product[50];
    cout << "\nВведи наименование товара: ";
    //cin >> product; // считывание строки до первого пробела
    cin.getline(product, sizeof(product)); // считываение строки целиком

    cout << "\nВыш товар: " << product;







    _getch();
}


