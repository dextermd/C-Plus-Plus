#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// ������� 6. ��������� ����������� ������� ��������, ���������� ���������� � ������� �
	// ��������� ��� ���������� � ���������.�������: 1 ������ = 1066.8 ������.

	//--------------------------------------------------------------------------------------

	double verst, km, defVerst = 1.0668;

	cout << "������� ������: ";
	cin >> verst;

	cout << setprecision(2) << fixed;

	km = verst * defVerst;
	cout << verst << " ������ = " << km << " km";

	_getch();
}