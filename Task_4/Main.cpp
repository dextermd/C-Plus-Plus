#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	Задание 4: Программа определяет, является ли введенное с клавиатуры 5 - тизначное число
	//		палиндромом.Палиндромом называется число(или строка), которое читается одинаково
	//		слева направо и наоборот, например : 12321. В случае ввода не 5 - тизначного числа – сообщение
	//		об ошибке.


	int number, n1, n2, n3, n4, n5;

	cout << "\nВведите целое четырехзначное число: ";
	cin >> number;



	if (number > 9999 && number <= 99999)
	{
		n1 = number / 10000;
		n2 = number % 10000 / 1000;
		n3 = number % 1000 / 100;
		n4 = number % 100 / 10;
		n5 = number % 10;

		if (n1 == n5 && n2 == n4)
		{
			cout << number << " Число палиндром";
		}
		else {
			cout << number << " Число обычное";
		}
	}
	else
		cout << "Значение не верное!";


	_getch();

}