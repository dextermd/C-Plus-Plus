#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	// Задание 2: Пользователь вводит четырехзначное число.Необходимо сформировать новое
	//	 число, в котором поменять местами 1 - ю и 2 - ю цифры, а также 3 - ю и 4 - ю цифры исходного числа.
	//	 Если пользователь вводит не четырехзначное число – вывести сообщение об ошибке.Например,
	//	 если введено число 1563, результат работы программы : 5136.


	int number, n1, n2, n3, n4, result;

	cout << "\nВведите целое четырехзначное число: ";
	cin >> number;


	if (number > 999 && number <= 9999)
	{
		n1 = number / 1000;
		n2 = number % 1000 / 100;
		n3 = number % 100 / 10;
		n4 = number % 10; 
		
		result = n2 * 1000 + n1 * 100 + n4 * 10 + n3;

		cout << result;

	}
	else
		cout << "Значение не верное!";

	_getch();

}