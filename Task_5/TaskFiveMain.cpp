#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// ������� 5. ��������� ����������� ������� ��������, ���������� ��� � ������ � ���������
	// ��� �������� � ����������.�������: 1 ���� = 453.59 �����.

	//--------------------------------------------------------------------------------------

	double pounds, kg, defPounds = 0.45359237;

	cout << "������� �����: ";
	cin >> pounds;

	cout << setprecision(2) << fixed;

	// M(��) = M(�����) * 0,45359237
	kg = pounds * defPounds;
	cout << pounds << " pounds = " << kg << " kg";

	_getch();
}