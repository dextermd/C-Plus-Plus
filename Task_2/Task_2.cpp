#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h> 

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	������� 2: �������� ��������� ��� ����������� ���������� ������ ����������� ���������
	//		ax2 + bx + c = 0, ��� a �� ����� ����(����������� �������� ������������ ����� ������).
	//		� ���������� �������� ��� ����� �����(a, b, c) � �������������� ������������ �� �������
	//		d = b2 � 4ac.
	//	- ���� d > 0, �� ������ ��� � ��� ������������ �� �������� :
	//		x1 = (-b + �����.������(d)) / (2a) �
	//		x2 = (-b - �����.������(d)) / (2a)
	//		- ���� d ����� 0, �� ������ ���� x1 = x2 = -b / (2a)
	//		- ���� d < 0, �� ������ ���.
	//	���������� : ��� ����������� ����������� ����� ����������� ������� sqrt.

	int a, b, c;

	cout << "\n������� ��� ����� �����: ";
	cin >> a >> b >> c;

	if (a != 0)
	{
		double disc = b * b - 4 * a * c;
		double rOne, rTwo, r;

		if ( disc > 0 )
		{
			rOne = (-b + sqrt(disc)) / (2 * a);
			rTwo = (-b - sqrt(disc)) / (2 * a);

			cout << "������ ���, ������ " << rOne << " ������ " << rTwo << endl;
		}
		else if (disc == 0)
		{
			r = -b / (2 * a);
			cout << "������ ���� " << r;
		}
		else
		{
			cout << "\n������ ���";
		}
	}
	else {
		cout << "��������� �������� �������";
	}

	_getch();

}