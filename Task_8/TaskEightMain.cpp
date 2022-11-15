#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// Задание 8. Напишите программу “Конвертатор валюты” : MDL->USD MDL->EURO.
	// Оформление по желанию.

	//--------------------------------------------------------------------------------------

	float mdl, usd, mdlToUsd, usdToMdl;

	cout << "\t\t\t\tКонвертатор валюты MDL -> USD\n";

	cout << "\nВведите стоимость 1 USD в MDL: ";
	cin >> usdToMdl;

	cout << "Введите количество MDL которое хотите поменять на USD : ";
	cin >> mdl;

	cout << setprecision(2) << fixed;
	cout << "Вы поличили: " << mdl / usdToMdl << " USD";

	cout << endl << endl << endl;

	cout << "\t\t\t\tКонвертатор валюты USD -> MDL\n";

	cout << "\nВведите стоимость 1 MDL в USD: ";
	cin >> mdlToUsd;

	cout << "Введите количество USD которое хотите поменять на MDL : ";
	cin >> usd;

	cout << setprecision(2) << fixed;
	cout << "Вы поличили: " << usd / mdlToUsd << " MDL";

	_getch();
}