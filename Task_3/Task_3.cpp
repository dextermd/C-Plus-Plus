#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	������� 3: �������� ���������, ������� ����������� ����, �����, ��� � ������������
	//		�������� �� ���������� ���� ������(����).���������� ��������� ���������� ���� ��������
	//		������, ����� ���������� / �� ���������� ���.�������� ���� � �������������� �������������
	//		�����.��� ����� ������������ ������ � ���������.���� �� ���� ������� �����, ������� ��
	//		����� � ��������� ������. ��������, 9 ���� 2021 �.

	int day, month, year;

	cout << "������� ����: ";
	cin >> day;

	if (day > 0 && day < 32)
	{
		cout << "������� �����: ";
		cin >> month;

		if (month > 0 && month < 13)
		{
			if (month == 2 && day > 29)
			{
				cout << "\t\t**** � ������� ��� ������ ���! ****";
			}
			else {
				cout << "������� ���: ";
				cin >> year;

				if (year > 999 && year < 10000)
				{
					bool thirty = false, thirtyOne = false, leapYear = false, febr = false;
					string nameMonth;

					if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
					{
						leapYear = true;
					}
					else {
						leapYear = false;
					}

					switch (month)
					{
					case 1:
						nameMonth = "������";
						thirtyOne = true;
						leapYear = false;
						break;
					case 2:
						nameMonth = "�������";
						if (day == 29 && leapYear == true)
						{
							leapYear = true;
							febr = true;
						}
						else {
							leapYear = false;
							febr = false;
						}
						break;
					case 3:
						nameMonth = "�����";
						thirtyOne = true;
						leapYear = false;
						break;
					case 4:
						nameMonth = "������";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 5:
						nameMonth = "���";
						thirtyOne = true;
						leapYear = false;
						break;
					case 6:
						nameMonth = "����";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 7:
						nameMonth = "����";
						thirtyOne = true;
						leapYear = false;
						break;
					case 8:
						nameMonth = "�������";
						thirtyOne = true;
						leapYear = false;
						break;
					case 9:
						nameMonth = "��������";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 10:
						nameMonth = "�������";
						thirtyOne = true;
						leapYear = false;
						break;
					case 11:
						nameMonth = "������";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 12:
						nameMonth = "�������";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					}

					if (thirty == true || thirtyOne == true || leapYear == true || febr == true)
					{

						cout <<"\t\t\t_____ " << day << " " << nameMonth << " " << year << " � _____";
					}
					else {
						cout << "\t\t**** ������ ��� ���� � ���� ������ � � ���� ����! ****";
					}

				}
				else {
					cout << "\t\t**** �������� ���! ****";
				}
			}
		}
		else {
			cout << "\t\t**** �������� �����! ****";
		}
	}
	else{
		cout << "\t\t**** �������� ����! ****";
	}

	_getch();

}