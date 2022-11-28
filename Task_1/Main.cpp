#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	// Задание 1: Пользователь вводит с клавиатуры целое число.Если оно четное, умножить его на
	// три, иначе – поделить на два.Результат вывести на экран.

	int number;

	cout << "\nВведите целое число: ";
	cin >> number;

	if (number % 2 == 0)
	{
	
		cout << "\t" << number << " * " << 3 << " = " << number * 3;
	}else
		cout << "\t" << number << " / " << 2 << " = " << number / 2;
	
	_getch();

}