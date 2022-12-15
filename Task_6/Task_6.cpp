#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	//	Задание 6. Пользователь вводит с клавиатуры целое число(количество цифр неизвестно),
	//		необходимо рассчитать и вывести на экран сумму его цифр.
	//		Например, пользователь ввел число 12345. На экране должно появиться сообщение о том, что сумма цифр числа 12345 равна 15.

	int num = 0, n, summa = 0, ncout;

	cout << "Введите целое число: ";
	cin >> num;

	ncout = num;

	while (num)
	{
		n = num % 10;
		summa += n;
		num /= 10;
	}

	cout << "Сумма цифр числа " << ncout << " равна " << summa;

	_getch();

}