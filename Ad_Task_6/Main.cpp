#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	�������������(�� �������) :
	//		������� 6. ������������ ������ � ���������� ����� � ��������, ��������� � ������ ���.
	//		������� �� ����� ������� ����� � �����, ������� � ��������.���������, ������� �����, ����� �
	//		������ �������� �� ��������.

	int pastSecTime, mins, lastSec, hours;

	cout << "\n������� ��������� ����� � �������� � ������ ���: ";
	cin >> pastSecTime;

	if (pastSecTime > 0 && pastSecTime < 86401)
	{
		hours = pastSecTime / 3600;
		mins = (pastSecTime / 60) % 60;
		lastSec = pastSecTime % 60;

		cout << "��������� ����� � ������ ��� � ������� (HH:MM:SS) " << hours << ":" << mins << ":" << lastSec;

		hours -= 24;
		mins -= 60;
		lastSec -= 60;

		cout << "\n�������� �� �������� � ������� (HH:MM:SS) " << abs(hours) << ":" << abs(mins) << ":" << abs(lastSec);
	}
	else
		cout << "�������� �� ������!";


	_getch();

}