#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  Задание 4. Программа запрашивает два целых числа а и в.Написать программу, которая
    //    выводит на экран только нечетные числа указанного диапазона и находит их сумму.Рассмотреть
    //    случаи, когда a > b(вывести числа от большего к меньшему) и а < b(вывести числа от меньшего
    //    к большему).В случае равенства а и в – сообщение.

    int a, b;
    long long summa = 0;
    cout << "Введите два целых числа: ";
    cin >> a >> b;
    
    if (a > b || b > a)
    {
        while ( a < b)
        {
            if (a % 2) {
                cout << a << " ";
                summa += a;
            }
            a++;
        }
    
        while (a > b)
        {
            if (a % 2) {
                cout << a << " ";
                summa += a;
            }
            a--;
        }
        cout << "\nСумма чисел: " << summa << endl;
    }
    else {
        cout << "A == B";
    }
    _getch();
}