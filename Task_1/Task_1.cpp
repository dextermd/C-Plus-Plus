#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	������� 1: �������� ��������� ���������� $ 200 + ������� �� ������ :
	//	-������� �� $ 500 - 3 %,
	//	-�� 500 �� 1000 � 5 %,
	//	-����� 1000 � 8 % .
	//	������������ ������ � ���������� ������� ������ ��� ���� ����������.���������� ��
	//	��������, ���������� ������� ���������(������� �� ����� ���������� ����� �������
	//		���������).������� ��������� ��������� ������ $ 150, ������� ����� �� �����.

	int num;
	double salManagerOne, salManagerTwo, salManagerThree, max;
	
	cout << "\n������� ������� ������ ��� ���� ����������: ";
	cin >> salManagerOne >> salManagerTwo >> salManagerThree;

	if (salManagerOne >= 0 && salManagerTwo >= 0 && salManagerThree >= 0)
	{

		if (salManagerOne < 500) // 0.03
		{
			salManagerOne += salManagerOne * 0.03 + 200;
			num = 1;

		}
		else if (salManagerOne >= 500 && salManagerOne <= 1000) // 0.05
		{
			salManagerOne += salManagerOne * 0.05 + 200;
			num = 1;
		}
		else {	 // 0.08
			salManagerOne += salManagerOne * 0.08 + 200;
			num = 1;
		}

		cout << "�������� c ���������� ������� " << num << " �������� = " << salManagerOne << " USD" << endl;

		if (salManagerTwo < 500) // 0.03
		{
			salManagerTwo += salManagerTwo * 0.03 + 200;
			num = 2;
		}
		else if (salManagerTwo >= 500 && salManagerTwo <= 1000) // 0.05
		{
			salManagerTwo += salManagerTwo * 0.05 + 200;
			num = 2;
		}
		else {	 // 0.08
			salManagerTwo += salManagerTwo * 0.08 + 200;
			num = 2;
		}

		cout << "�������� c ���������� ������� " << num << " �������� = " << salManagerTwo << " USD" << endl;


		if (salManagerThree < 500) // 0.03
		{
			salManagerThree += salManagerThree * 0.03 + 200;
			num = 3;
		}
		else if (salManagerThree >= 500 && salManagerThree <= 1000) // 0.05
		{
			salManagerThree += salManagerThree * 0.05 + 200;
			num = 3;
		}
		else {	 // 0.08
			salManagerThree += salManagerThree * 0.08 + 200;
			num = 3;
		}

		cout << "�������� c ���������� ������� " << num << " �������� = " << salManagerThree << " USD" << endl;
		
		max = salManagerOne;
		num = 1;
		if (salManagerTwo > salManagerOne)
		{
			max = salManagerTwo;
			num = 2;
		}
		if (salManagerThree > max)
		{
			max = salManagerThree;
			num = 3;
		}

		cout << "\n\t\t**** ������ �������� c ���������� ������� " << num << " �������� = " << max << " USD ****" << endl;
		cout << "\n�������� c ���������� ������� " << num << " ������� ������. (150$)\n" << "����� " << max + 150 << " USD" << endl;
	
	}
	else {
		cout << "�������� ��������!";
	}

	_getch();

}