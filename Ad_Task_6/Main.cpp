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

	int pastSecTime, mins, sec, hours, lastHours,lastMins,lastSec;

	cout << "\n������� ��������� ����� � �������� � ������ ���: ";
	cin >> pastSecTime;

	if (pastSecTime > 0 && pastSecTime < 86401)
	{
		hours = pastSecTime / 3600;
		mins = (pastSecTime / 60) % 60;
		sec = pastSecTime % 60;

		cout << "��������� ����� � ������ ��� � ������� (HH:MM:SS) " << hours << ":" << mins << ":" << sec;

		lastHours = 23 - hours;
		lastMins = 59 - mins;
		lastSec = 60 - sec;

		cout << "\n�������� �� �������� � ������� (HH:MM:SS) " << lastHours << ":" << lastMins << ":" << lastSec;
	}
	else
		cout << "�������� �� ������!";


	_getch();

}