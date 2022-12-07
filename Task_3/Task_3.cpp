#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	//	Задание 3: Напишите программу, которая запрашивает день, месяц, год и осуществляет
	//		проверку на корректный ввод данных(даты).Необходимо учитывать количество дней согласно
	//		месяцу, также високосный / не високосный год.Значение года – четырехзначное положительное
	//		число.При вводе некорректных данных – сообщение.Если же дата введена верно, вывести на
	//		экран с названием месяца. Например, 9 июля 2021 г.

	int day, month, year;

	cout << "Введите день: ";
	cin >> day;

	if (day > 0 && day < 32)
	{
		cout << "Введите месяц: ";
		cin >> month;

		if (month > 0 && month < 13)
		{
			if (month == 2 && day > 29)
			{
				cout << "\t\t**** В феврале нет такого дня! ****";
			}
			else {
				cout << "Введите год: ";
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
						nameMonth = "января";
						thirtyOne = true;
						leapYear = false;
						break;
					case 2:
						nameMonth = "февраля";
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
						nameMonth = "марта";
						thirtyOne = true;
						leapYear = false;
						break;
					case 4:
						nameMonth = "апреля";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 5:
						nameMonth = "мая";
						thirtyOne = true;
						leapYear = false;
						break;
					case 6:
						nameMonth = "июня";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 7:
						nameMonth = "июля";
						thirtyOne = true;
						leapYear = false;
						break;
					case 8:
						nameMonth = "августа";
						thirtyOne = true;
						leapYear = false;
						break;
					case 9:
						nameMonth = "сентября";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 10:
						nameMonth = "октября";
						thirtyOne = true;
						leapYear = false;
						break;
					case 11:
						nameMonth = "ноября";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					case 12:
						nameMonth = "декабря";
						thirty = day > 30 ? false : true;
						leapYear = false;
						break;
					}

					if (thirty == true || thirtyOne == true || leapYear == true || febr == true)
					{

						cout <<"\t\t\t_____ " << day << " " << nameMonth << " " << year << " г _____";
					}
					else {
						cout << "\t\t**** Такого дня нету в этом месяце и в этом году! ****";
					}

				}
				else {
					cout << "\t\t**** Неверный год! ****";
				}
			}
		}
		else {
			cout << "\t\t**** Неверный месяц! ****";
		}
	}
	else{
		cout << "\t\t**** Неверный день! ****";
	}

	_getch();

}