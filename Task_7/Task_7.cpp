#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	//	Задание 7. Вводится целое число и цифра.Программа подсчитывает и выводит на экран
	//		количество повторений этой цифры в числе.В случае отсутствия введенной цифры в числе –
	//		сообщение.
	//		Например, число 123536, цифра 3 Цифра 3 повторяется в числе 2 раза.
	//		Например, число 123536, цифра 8 Цифра 8 отсутствует в числе.


	int num = 0, findNum, n, ncout, k = 0;

	cout << "Введите целое число: ";
	cin >> num;

	cout << "Введите цифру для поиска: ";
	cin >> findNum;

	ncout = num;

	while (num)
	{
		n = num % 10;

		if (n == findNum)
		{
			k++;
		}

		num /= 10;
	}

	if (k < 0)
	{
		cout << "Число " << ncout << ", цифра " << findNum << " отсутствует в числе.";
	}
	else {
		cout << "Число " << ncout << ", цифра " << findNum << " повторяется в числе " << k << " раза.";
	}


	_getch();

}