#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// ������� 8. �������� ��������� ������������ ������� : MDL->USD MDL->EURO.
	// ���������� �� �������.

	//--------------------------------------------------------------------------------------

	float mdl, usd, mdlToUsd, usdToMdl;

	cout << "\t\t\t\t����������� ������ MDL -> USD\n";

	cout << "\n������� ��������� 1 USD � MDL: ";
	cin >> usdToMdl;

	cout << "������� ���������� MDL ������� ������ �������� �� USD : ";
	cin >> mdl;

	cout << setprecision(2) << fixed;
	cout << "�� ��������: " << mdl / usdToMdl << " USD";

	cout << endl << endl << endl;

	cout << "\t\t\t\t����������� ������ USD -> MDL\n";

	cout << "\n������� ��������� 1 MDL � USD: ";
	cin >> mdlToUsd;

	cout << "������� ���������� USD ������� ������ �������� �� MDL : ";
	cin >> usd;

	cout << setprecision(2) << fixed;
	cout << "�� ��������: " << usd / mdlToUsd << " MDL";

	_getch();
}