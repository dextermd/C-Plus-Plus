#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include "Data.h"
#include "Student.h"
#include "my_templates.h"


using namespace std;


int main()
{

#if 0

    /*
    
    // Логическая операция  | ИЛИ 

    По отношению ко второму операнду(маске) логическая операция ИЛИ
    сохраняет те разряды первого операнда,
    которые соответствуют нулевым разрядам маски,
    и  устанавливает в 1 разряды результата,
    которые соответствуют единичным разряды маски.

    Операция так и называется - установка разрядов по маске.

    x x x x x x x x - операнд
    0 0 1 1 1 0 0 0 - маска
    x x 1 1 1 x x x - результат
    */

    int a = 25, m = 4, c;
    char str[32];

    c = a | m;

    _itoa_s(a, str, 2);
    cout << setw(8) << str << endl;

    _itoa_s(m, str, 2);
    cout << setw(8) << str << endl;

    _itoa_s(c, str, 2);
    cout << setw(8) << str << endl;

    cout << "\n c = " << c << endl;

#endif


#if 0

    // Установить  i-й бит числа n равным 1.
    // Алгоритм: 
    //      - Сдвиг единицы влево на i позицийю.
    //      - Побитовое OR  

    int a = 25, i = 3, m, r;
    m = 1 << i;
    r = a | m;

#endif


#if 0

    // Задача: Записать день, месяц, год в одну переменную.
    // Добавить проверку правильного ввода данных 

    unsigned int date = 0, d;
    char str[32];

    _itoa_s(date, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nВведи день: ";
    cin >> d;
    
    //date = d;
    //date = date | d;
    date |= d;

    _itoa_s(d, str, 2);
    cout << setw(12) << "d(day) = " << str << endl;

    _itoa_s(date, str, 2);
    cout << setw(12)<< "date(day) = " << str << endl;

    cout << "\nВведи месяц: ";
    cin >> d;

    //date = date << 4; // место для месяца максимальное число 12 это 4 бита
    date <<= 4;

    _itoa_s(date, str, 2);
    cout << setw(12) << "date(day + 4 bit) = " << str << endl;

    date |= d; // установить бит месяца

    _itoa_s(d, str, 2);
    cout << setw(25) << "d(month) = " << str << endl;

    _itoa_s(date, str, 2);
    cout << setw(12) << "date(day + month) = " << str << endl;

    cout << "\nВведи год: ";
    cin >> d;

    date <<= 11;  // место для года максимальное число 2047 это 11 бита

    _itoa_s(date, str, 2);
    cout << setw(12) << "date(day + 11 bit) = " << str << endl;

    date |= d;  // установить бит года

    _itoa_s(d, str, 2);
    cout << setw(29) << "d(year) = " << str << endl;

    _itoa_s(date, str, 2);
    cout << setw(12) << "date(day + monrh + year) = " << str << endl;

    cout << "\nВведи часы: ";
    cin >> d;

    date <= 5; // Место для часов

    _itoa_s(d, str, 2);
    cout << setw(29) << "d(часы) = " << str << endl;

    date |= d; // уствновка бит часов

    _itoa_s(d, str, 2);
    cout << setw(29) << "d(чесы) = " << str << endl;

    _itoa_s(date, str, 2);
    cout << setw(12) << "date(day + monrh + year + чесы) = " << str << endl;

    cout << "\nВведи минуты: ";
    cin >> d;
    
    date <<= 6;
    date |= d;

    _itoa_s(date, str, 2);
    cout << setw(29) << "date = " << str << endl;


    cout << "\ndate = " << date << endl << endl;
    // 5(день), 4(месяц), 11(год), 5(часы), 6(минуты) (Bits)
    

    // Распаковка
    int day, month, year, hour, minut;
    int m1 = 63; // 0x3F  // 6 bit
    int m2 = 31; // 0x1F  // 5 bit
    int m3 = 0x7FF; // 2047  // 11 bit
    int m4 = 15; // 0xF  // 4 bit

    minut = date & m1;
    
    _itoa_s(m1, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nМинуты: " << minut << endl;

    date >>= 6; // удаляем данные минут из date

    _itoa_s(date, str, 2);
    cout << setw(12) << str << endl;

    hour = date & m2;

    cout << "\nЧасы: " << hour << endl;

    date >>= 5; // удаляем данные часов из date

    year = date & m3;

    cout << "\nГод: " << year << endl;

    date >>= 11;

    _itoa_s(date, str, 2);
    cout << setw(12) << str << endl;

    month = date & m4;

    cout << "\nМесяц: " << year << endl;

    date >>= 4;
    day = date & 0x1F;

    _itoa_s(date, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nДень: " << day << endl;

    date >>= 5;

    _itoa_s(date, str, 2);
    cout << setw(12) << str << endl;

    cout << "\ndate = " << date;

#endif

    
#if 0

    /*
    Инверсия битов (поразрядное отрицание, дополнение
    до единицы) инвертирует биты, т.е. каждый бит со
    значением 1 получает значение 0 и наоборот.
    */

    // Операция ИНВЕРСИИ ~ 

    int a = 25, b;
    char str[33];

    cout << "\na = " << a << endl;

    _itoa_s(a, str, 2);
    cout << setw(32) << str << endl;

    b = ~a;

    _itoa_s(b, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nb = " << b << endl;

    b = ~a + 1; // в b запись значения 'a' с отрицательным знаком  

    _itoa_s(b, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nb + 1 = " << b << endl;

#endif


#if 0

    /*
    Очищение разрядов.

    Поразрядная инверсия меняет значение каждого разряда
    машинного слова на противоположное (инвертирует).

    Операция И(&) в сочетании с инвертированной маской-константой
    производит ОЧИСТКА разрядов по маске.

    */

    int a = 2047, b, c;
    int m = ~240;
    char str[33];

    _itoa_s(a, str, 2);
    cout << setw(32) << str << endl;

    _itoa_s(m, str, 2);
    cout << setw(32) << str << endl;

    cout << "\nОчищение разрядов с 4-го по 7-ой: \n";
    c = a & m;

    _itoa_s(c, str, 2);
    cout << setw(32) << str << endl;

#endif


#if 0

    // Поразрядная операция  исключающая ИЛИ  ^

    /*
    Битовое исключающее «ИЛИ» сравнивает последовательно
    разряд за разрядом два своих операндов.

 

    Для каждого разряда результат равен 1, если один из
    двух (но не оба) соответствующих разрядов операндов
    равен 1.
    */


    int a = 25;
    int b = 5;
    int c;
    int d;
    char str[33];

    _itoa_s(a, str, 2);
    cout << setw(12) << str << endl;
   
    _itoa_s(b, str, 2);
    cout << setw(12) << str << endl;

    c = a ^ b;

    _itoa_s(c, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nc = " << c << endl;

    d = c ^ b;

    _itoa_s(c, str, 2);
    cout << setw(12) << str << endl;

    _itoa_s(b, str, 2);
    cout << setw(12) << str << endl;

    _itoa_s(a, str, 2);
    cout << setw(12) << str << endl;

    cout << "\nd = " << d << endl;

#endif


#if 0

    //----------------------------------------------------------------------
    // Криптография------------------- шифр Вернама -------------------------

    //int i, len; 
    //char str[] = "Hello, word!";
    //
    //len = strlen(str) + 1;            // определяем длину строки открытого текста
    //char *oStr = new char[len];   //объявляем динамический массив указанной длины для открытого текста
    //char *key = new char[len];    //точно такой же массив объявляем для ключа
    //char *shStr = new char[len];  //массив-приемник для зашифрованного текста
    //char *rasStr = new char[len];  //массив-приемник для разшифрованного текста
    //
    ////помещаем в массив открытый текст
    //strcpy_s(oStr,len, str);



    //// определяем ключ случайным образом
    //for (i = 0; i < len; i++)
    //    key[i] = (char)rand() % 255;
    //cout << "\nКлюч: " << key;
    //
    ////  шифрование
    //for (i = 0; i < len; i++)
    //    shStr[i] = oStr[i] ^ key[i];


    ////для наглядности выведем на экран результат работы
    //cout << "\nОткрытый текст:       " << oStr;
    //cout << "\nЗашифрованный текст:  " << shStr;

    //for (i = 0; i < len; i++)
    //    rasStr[i] = shStr[i] ^ key[i];
    //cout << "\nРасшифрованный текст: " << rasStr;


    //delete[]oStr;
    //delete[]key;
    //delete[]shStr;

#endif


    // ------------------------------------------------------------------------------------------------- //
    // Битовые поля ------------------------------------------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------- //

    struct test {
        unsigned a : 1;
        unsigned b : 4;
        unsigned c : 2;
        unsigned   : 1; // не занят
    };

    cout << "\nОбьем памяти в байтах : " << sizeof(test) << endl;

    test t;
    t.a = 1;

    cout << "\nt.a = " << t.a << endl;

    t.a = 10; // 1010
    cout << "\nt.a = " << t.a << endl;

    t.b = 12;
    cout << "\nt.b = " << t.b << endl;

    t.b = 25;
    cout << "\nt.b = " << t.b << endl;

    _getch();
}