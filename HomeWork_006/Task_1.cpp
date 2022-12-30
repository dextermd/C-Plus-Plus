#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	//	Задание 1. Вывести на экран фигуры, заполненные звездочками.Диалог с пользователем
	//		реализовать при помощи меню(фигура выводится по введенному пользователю номеру).
	//		Последний пункт меню – выход из меню.Пользователь может выбирать пункты меню до тех пор,
	//		пока не выберет пункт выхода из меню.Сделать проверку на правильность ввода пункта меню.

	int menuNumber = 1;
	do
	{
		cout << "\nВведите какой пунк меню котите вывести на экран от 1 до 12 ( 0 = выход из меню ): ";
		cin >> menuNumber;

		switch (menuNumber)
		{
		case 1:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
			    for (int j = 0; j < 5; j++)
			    {
			        if (i <= j)
			        {
						cout << "*" << " ";
			        }
			        else {
			            cout << "  ";
			        }
			    }
			    cout << endl;
			}

			break;

		case 2:
			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
			    for (int j = 0; j < 5; j++)
			    {
			        if (i >= j) 
			        {
			            cout << "*" << " ";
			        }
			    }
			    cout << endl;
			}

			break;

		case 3:
			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j >= i && i + j <= 5 - 1 )
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 4:
			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j <= i && i + j >= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 5:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j >= i && i + j <= 5 - 1 || j <= i && i + j >= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 6:
			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j <= i && i + j <= 5 - 1 || j >= i && i + j >= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 7:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j <= i && i + j <= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 8:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j >= i && i + j >= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 9:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (i + j <= 5 - 1)
					{
						cout << "*" << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}

			break;

		case 10:
			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
			    for (int j = 0; j < 5; j++)
			    {
			        if (i + j >= 5 - 1) 
			        {
						cout << "*" << " ";
			        }
			        else {
			            cout << "  ";
			        }
			    }
			    cout << endl;
			}


			break;
		case 11:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++) // ?????? 
			{
			    for (int j = 0; j < 5; j++) // ???????
			    {
			        if (i + j >= 5 / 2 && j - i <= 5 / 2 && i - j <= 5 / 2 && i + j <= 5 / 2 + 5 - 1)
			        {
			            cout << "*" << " ";
			        }
			        else {
			            cout << "  ";
			        }

			    }
			    cout << endl;
			}

			break;

		case 12:

			cout << "\nВы выбрали меню " << menuNumber << endl << endl;

			for (int i = 0; i < 5; i++)
			{
			    for (int j = 0; j < 5; j++)
			    {
			        if (i + j <= 5 / 2 || j - i >= 5 / 2 || i - j >= 5 / 2 || i + j >= 5 / 2 + 5 - 1)
			        {
			            cout << "*" << " ";
			        }
			        else {
			            cout << "  ";
			        }

			    }
			    cout << endl;
			}

			break;
		case 0:
			cout << "\nВы вышли из программы " << endl;
			break;
		}
	} while (menuNumber != 0);


	_getch();

}