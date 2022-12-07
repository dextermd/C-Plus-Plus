#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	Задание 1: Зарплата менеджера составляет $ 200 + процент от продаж :
	//	-продажи до $ 500 - 3 %,
	//	-от 500 до 1000 – 5 %,
	//	-свыше 1000 – 8 % .
	//	Пользователь вводит с клавиатуры уровень продаж для трех менеджеров.Определить их
	//	зарплату, определить лучшего менеджера(вывести на экран порядковый номер лучшего
	//		менеджера).Лучшему менеджеру начислить премию $ 150, вывести итоги на экран.

	int num;
	double salManagerOne, salManagerTwo, salManagerThree, max;
	
	cout << "\nВведите уровень продаж для трех менеджеров: ";
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

		cout << "Менеджер c порядковым номером " << num << " зарплата = " << salManagerOne << " USD" << endl;

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

		cout << "Менеджер c порядковым номером " << num << " зарплата = " << salManagerTwo << " USD" << endl;


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

		cout << "Менеджер c порядковым номером " << num << " зарплата = " << salManagerThree << " USD" << endl;
		
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

		cout << "\n\t\t**** Лучший менеджер c порядковым номером " << num << " зарплата = " << max << " USD ****" << endl;
		cout << "\nМенеджер c порядковым номером " << num << " получил премию. (150$)\n" << "Итого " << max + 150 << " USD" << endl;
	
	}
	else {
		cout << "Неверное значение!";
	}

	_getch();

}