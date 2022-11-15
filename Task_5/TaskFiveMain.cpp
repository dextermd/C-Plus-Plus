#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// Задание 5. Программа запрашивает дробную величину, означающую вес в фунтах и переводит
	// эту величину в килограммы.Справка: 1 фунт = 453.59 грамм.

	//--------------------------------------------------------------------------------------

	double pounds, kg, defPounds = 0.45359237;

	cout << "Введите фунты: ";
	cin >> pounds;

	cout << setprecision(2) << fixed;

	// M(кг) = M(фунты) * 0,45359237
	kg = pounds * defPounds;
	cout << pounds << " pounds = " << kg << " kg";

	_getch();
}