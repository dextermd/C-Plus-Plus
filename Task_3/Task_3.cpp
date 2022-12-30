#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	//	Задача 3. Написать программу, которая выводит все совершенные числа от 1 до 10000.
	//	Совершенным называется число, у которого сумма всех делителей(включая единицу и исключая
	//	само число) равна этому числу.
	//	Ответ: 6 28 496 8128


	int i, j, s; 
	for (i = 1; i < 10000; i++) {
		s = 0;
	for (j = 1; j < i; j++)
		if (i % j == 0)
			s += j; 
		if (s == i)
			cout << i << " ";
	}

	_getch();

}