#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// Задание 6. Программа запрашивает дробную величину, означающую расстояние в верстах и
	// переводит это расстояние в километры.Справка: 1 верста = 1066.8 метров.

	//--------------------------------------------------------------------------------------

	double verst, km, defVerst = 1.0668;

	cout << "Введите верста: ";
	cin >> verst;

	cout << setprecision(2) << fixed;

	km = verst * defVerst;
	cout << verst << " верста = " << km << " km";

	_getch();
}