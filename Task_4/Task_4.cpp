#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
	//setlocale(LC_CTYPE, "rus");

	// Вывести на экран Таблицу умножения.
	

		for (int i = 1; i < 10; i++)
		{
			cout << setw(15);
			for (int j = 1; j < 10; j++)
				if (i * j >= 10)
				{
					cout << i << "*" << j << " = " << i * j << setw(15);
				}
				else {
					cout << i << "*" << j << " =  " << i * j << setw(15);
				}
				
				
			cout << endl;
		}
		
	
	_getch();

}