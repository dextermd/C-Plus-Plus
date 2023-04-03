#include <conio.h>
#include <iostream>


using namespace std;

/*

Напишите программу, которая принимает две строки.
Программа удаляет из первой строки все вхождения второй строки

Пример работы программы:

Строка: nameFile name is, Folder nameisname
Количество символов в строке:  35
Подстрока для удаления: name
Строка после удаления подстроки:  File  is, Folder is
Количество символов в строке:  19

*/

int main()
{
	system("chcp 1251>nul");


	// Вариант  базовый - без динамического выделения памяти - УДАЛЕНИЕ подстроки
	{
		/*char str[] = "String for delete word, String for deleteword ", res[200]="";
		char wd[] = "delete";*/

		char str[] = "nameFile name is, Folder nameisname!!!", res[200] = "";
		char wd[] = "name";

		char* t, * t2;

		t = strstr(str, wd); // Первое вхождение подстроки в строку
		t2 = str;			 // Копия адреса исходной строки

		while (t)
		{
			int index = t - t2; // Определение индекса текущего вхождения подстроки в строку
			cout << "\nИндекс: " << index;

			strncat_s(res, t2, index);// Добавление в результирующую строку index символов строки t2

			t2 = t + strlen(wd);//  Смещаем t2 на длину удаляемой подстроки
			t = strstr(t2, wd); // определяем адрес следующего вхождения подстроки в строку
		}
		if (t2)
		{
			strcat_s(res, t2);
		}
		cout << endl << str << endl << res << endl;

	}


	_getch();
}

