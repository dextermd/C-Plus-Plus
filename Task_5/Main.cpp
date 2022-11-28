#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	//	Задание 5: Пользователь вводит с клавиатуры целое шестизначное число.Написать программу,
	//		которая определяет, является ли введенное число – счастливым(Счастливым считается
	//		шестизначное число, у которого сумма первых трех цифр равна сумме вторых трех цифр).
	//		Например, число 156372 – счастливое.

	int number, n1, n2, n3, n4, n5, n6;

	cout << "\nВведите целое шестизначное число: ";
	cin >> number;

	if (number > 99999 && number <= 999999)
	{
		n1 = number / 100000;
		n2 = number % 100000 / 10000;
		n3 = number % 10000 / 1000;
		n4 = number % 1000 / 100;
		n5 = number % 100 / 10;
		n6 = number % 10;

		int left = n1 + n2 + n3;
		int right = n4 + n5 + n6;

		if (left == right)
		{
			cout << "Число " << number << " счастливое!";
		}
		else {
			cout << "Число " << number << " обычное";
		}
	}else
		cout << "Значение не верное!";


	_getch();

}