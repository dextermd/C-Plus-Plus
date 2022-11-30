#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

#define _USE_MATH_DEFINES // 1 M_PI;
#include <math.h> // 2 M_PI;

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//Задание 3: Напишите программу, которая рассчитывает площадь кольца, запрашивая с
	//	клавиатуры радиус кольца(r1) и радиус отверстия(r2),
	//  по формуле s = (r1  – r2 ). 
	//	В случае неправильного ввода данных(радиус кольца меньше радиуса отверстия) появляется
	//	сообщение об ошибке. ( - это число пи, использовать константу математической библиотеки).

	double radiusEx,radiusIn, rEx, rIn;

	cout << "\nВведите радиус кольца: ";
	cin >> radiusEx;
	cout << "\nВведите радиус отверстия: ";
	cin >> radiusIn;
	cout << setprecision(2) << fixed;

	rEx = M_PI * pow(radiusEx, 2);
	rIn = M_PI * pow(radiusIn, 2);


	if (rEx > rIn)
	{
		cout << "\nРадиус кольца: " << rEx 
			 << "\nРадиус отверстия: " << rIn;
	}
	else
		cout << "\nОшибка! Вы ввели неверные значения";


	_getch();

}