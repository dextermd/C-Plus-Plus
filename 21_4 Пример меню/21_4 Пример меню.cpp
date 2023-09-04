

#include <iostream>
#include <conio.h>
#include <iomanip>
#include "colors.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13



// menu
void showmenu(int key = -1) {
	key--;
	system("CLS");
	cout << endl << endl;
	char menu[6][250] = { "Sort... ","Search... ", "Popular... ", "Show all... ", "Add... ","Exit" };

	for (int i = 0; i < 6; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << " " << menu[i];
		if (i == key) cout << " ->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t =======================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}


int main()
{
	system("chcp 1251>nul");

#if 0

	// Получение кода клавиши

	int  key;

	do {
		cout << "\nНажми клавишу: ";
		key = _getch();
		cout << key << endl;

	} while (key != 27);

#endif // 1


#if 1

	int keys = 1, menuorder = 1, exit = 1;

	showmenu(1);

	while (exit) {

		switch ((keys = _getch())) {

		case KEY_UP:
			if (menuorder == 0) menuorder = 1;
			if (menuorder == 1) menuorder = 6;
			else menuorder--;
			showmenu(menuorder);
			break;
		case KEY_DOWN:
			if (menuorder == 6) menuorder = 1;
			else
				menuorder++;
			showmenu(menuorder);
			break;
		case KEY_ENTER:
			system("CLS");

			switch (menuorder) {
			case 1:

				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(1);
				break;

				break;
			case 2:
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(2);
				break;

				break;
			case 3:

				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(3);
				break;


			case 4:
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(4);
				break;


			case 5:

				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(5);
				break;

				break;

			case 6:
				system("CLS");
				exit = 0;

				break;
			}
		}
	}

#endif // 0

	_getch();
}


