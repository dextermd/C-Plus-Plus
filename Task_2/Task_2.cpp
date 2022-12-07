#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h> 

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	Задание 2: Напишите программу для определения количества корней квадратного уравнения
	//		ax2 + bx + c = 0, где a не равно нулю(Осуществить проверку правильности ввода данных).
	//		С клавиатуры вводятся три целых числа(a, b, c) и рассчитывается дискриминант по формуле
	//		d = b2 – 4ac.
	//	- Если d > 0, то корней два и они определяются по формулам :
	//		x1 = (-b + квадр.корень(d)) / (2a) и
	//		x2 = (-b - квадр.корень(d)) / (2a)
	//		- если d равен 0, то корень один x1 = x2 = -b / (2a)
	//		- если d < 0, то корней нет.
	//	Примечание : для определения квадратного корня используйте функцию sqrt.

	int a, b, c;

	cout << "\nВведите три целых числа: ";
	cin >> a >> b >> c;

	if (a != 0)
	{
		double disc = b * b - 4 * a * c;
		double rOne, rTwo, r;

		if ( disc > 0 )
		{
			rOne = (-b + sqrt(disc)) / (2 * a);
			rTwo = (-b - sqrt(disc)) / (2 * a);

			cout << "Корней два, первый " << rOne << " второй " << rTwo << endl;
		}
		else if (disc == 0)
		{
			r = -b / (2 * a);
			cout << "Корень один " << r;
		}
		else
		{
			cout << "\nКорней нет";
		}
	}
	else {
		cout << "Введенное значение неверно";
	}

	_getch();

}