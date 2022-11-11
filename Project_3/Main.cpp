#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");

	cout << "\tInfo\n\"\\\n\n";

	cout << R"(\tInfo\n\"\\\n\n)";

	cout << endl << endl;

	cout << "15 + 2 = " << 15 + 2 << endl;  // 15 + 2 = 17
	cout << "15 - 2 = " << 15 - 2 << endl;  // 15 - 2 = 15
	cout << "15 * 2 = " << 15 * 2 << endl;  // 15 * 2 = 30
	cout << "15 / 2 = " << 15 / 2 << endl;  // 15 / 2 = 7

	cout << endl << endl;

	cout << "15 / 2 = " << 15 / 2.0 << endl;  // 15 / 2.0 = 7.5

	cout << "15 / 2 = " << (float)15 / 2 << endl;  // (float или double)15 / 2 = 7.5

	cout << "15 % 2 = " << 15 % 2 << endl;  // 15 % 2 = 1

	cout << endl << endl;

	cout << "2147483647 + 1 = " << 2147483647 + 1 << endl;  // int  max = (−2,147,483,648 to 2,147,483,647)
	cout << "2147483647 + 2 = " << 2147483647 + 2 << endl;  // int  max = (−2,147,483,648 to 2,147,483,647)
	cout << "2147483647 + 3 = " << 2147483647 + 3 << endl;  // int  max = (−2,147,483,648 to 2,147,483,647)
	cout << "2147483647 + 3 = " << (unsigned int)2147483647 + 3 << endl;  // int unsigned   max = ( 0 to 4,294,967,295)

	cout << endl << endl;

	cout << "6587445648465658 + 1 = " << 6587445648465658 + 1 << endl; // 4 байт

	cout << endl << endl;

	cout << "\nВыделение памяти в байтах: 25.36 = " << sizeof(25.36) << " байт" << endl; // 8 байт

	cout << "\nВыделение памяти в байтах: float = " << sizeof(float) << " байт" << endl; // 4 байт

	cout << "\nВыделение памяти в байтах: short = " << sizeof(short) << " байт" << endl; // 2 байт

	cout << "\nВыделение памяти в байтах: long long = " << sizeof(long long) << " байт" << endl; // 8 байт

	cout << "\nВыделение памяти в байтах: char = " << sizeof(char) << " байт" << endl; // 1 байт

	cout << "\nВыделение памяти в байтах: 'a' = " << sizeof('a') << " байт" << endl; // 1 байт

	cout << "\nСимвол: " << 'a' << " Код символа: " << (int)'a' << endl; // 97
	cout << "\nСимвол: " << '+' << " Код символа: " << (int)'+' << endl; // 43
	cout << "\nСимвол: " << '`' << " Код символа: " << (int)'`' << endl; // 96
	cout << "\nСимвол: " << '1' << " Код символа: " << (int)'1' << endl; // 49
	cout << "\nСимвол: " << ' ' << " Код символа: " << (int)' ' << endl; // 32

	cout << "\nКод символа " << 43 << " Символ = " << (char)43 << endl; // s
	cout << "\nКод символа " << 97 << " Символ = " << (char)97 << endl; // s

	cout << "Символ " << 'Ю' << " Код символа: " << (int)(unsigned char)'Ю' << endl; // 222


	_getch();

}