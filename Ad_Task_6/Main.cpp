#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	Дополнительно(по желанию) :
	//		Задание 6. Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня.
	//		Вывести на экран текущее время в часах, минутах и секундах.Посчитать, сколько часов, минут и
	//		секунд осталось до полуночи.

	int pastSecTime, mins, lastSec, hours;

	cout << "\nВведите прошедшее время в секундах с начала дня: ";
	cin >> pastSecTime;

	if (pastSecTime > 0 && pastSecTime < 86401)
	{
		hours = pastSecTime / 3600;
		mins = (pastSecTime / 60) % 60;
		lastSec = pastSecTime % 60;

		cout << "Прошедшее время с начала дня в формате (HH:MM:SS) " << hours << ":" << mins << ":" << lastSec;

		hours -= 24;
		mins -= 60;
		lastSec -= 60;

		cout << "\nОсталось до полуночи в формате (HH:MM:SS) " << abs(hours) << ":" << abs(mins) << ":" << abs(lastSec);
	}
	else
		cout << "Значение не верное!";


	_getch();

}