#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	// Задание 2: Пользователь вводит с клавиатуры целое трехзначное число.Программа проверяет
	//	введено ли верное или неверное значение и выводит соответствующее сообщение.
		
	int number;

	cout << "\nВведите целое трехзначное число: ";
	cin >> number;

	if ( number > 99 && number <= 999 )
	{

		cout << "Значение верное!";
	}
	else
		cout << "Значение не верное!";

	_getch();

}