#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include "Data.h"

using namespace std;



void init(Data& data)
{
    do
    {
        cout << "\nВведите день:                ";
        cin >> data.day;
    } while (data.day > 31 || data.day < 1);

    do
    {
        cout << "\nВведите месяц:               ";
        cin >> data.month;
    } while (data.month > 12 || data.month < 1);

    do
    {
        cout << "\nВведите год:                 ";
        cin >> data.year;
    } while (data.year > 9999 || data.year < 1);

    do
    {
        cout << "\nВведите час от 1 до 24:      ";
        cin >> data.hour;
    } while (data.hour > 24 || data.hour < 1);

    do
    {
        cout << "\nВведите минуту от 0 до 59:   ";
        cin >> data.minut;
    } while (data.minut > 59 || data.minut < 0);

}


void show(const Data& data, bool str_name)
{
    if (str_name)
    {
        cout << data.day << " " << month_name(data.month) << " " << data.year << " " << data.hour << ":" << data.minut;
    }
    else 
    {
        cout << data.day << "." << data.month << "." << data.year << " " << data.hour << ":" << data.minut;
    }
}


char* month_name(int num)
{
    static char name[][20]{
        "none", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    return (num >= 1 && num <= 12) ? name[num] : name[0];
}