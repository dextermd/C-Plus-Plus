#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	//--------------------------------------------------------------------------------------

	// ������� 7. �������� ���������, ������� ����������� ��������� ������������� � ����������
	// ���������� ���� � ���������� ������ ������ � ���������� ����.��������, ������������ ����
	// 17 ����, ��������� ������ ������� �� ����� 2 ������ � 3 ���.


	//--------------------------------------------------------------------------------------

	int days, lostDay, weeks, defWeek = 7.;

	cout << "������� ���������� ����: ";
	cin >> days;

	weeks = days / defWeek;
	lostDay = days % defWeek;

	cout << weeks << " ������ � " << lostDay << " ���";

	_getch();
}