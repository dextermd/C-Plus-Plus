//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "MyString.h"
#include "MyArray.h"
#include "ListOneType.h"
#include "StudentAgr.h"
#include <list> // STL

using namespace std;


int main()
{
	system("chcp 1251>nul");
	system("color 1F");
	
		
#if 0


	//==================================================================
	// Запись объектов с динамическим выделением памяти в бинарный файл---
	// 
	// Запись MyString в бинарный файл 

	MyString a("Hello, World!!!!!");

	FILE* f;
	errno_t err;
	err = fopen_s(&f, "str.dat", "wb");
	if (!err)
	{
		a.save_to_binary_file(f);
		printf("Ok");
		fclose(f);
	}
	else {
		cout << "\nОшибка записи в файл";
	}



	// Чтение из файла с инициализацией объекта

	MyString tmp;
	cout << "\n Объект для считывания: " << tmp << endl;

	FILE* f2;
	errno_t err2;
	err2 = fopen_s(&f2, "str.dat", "rb");
	if (!err2)
	{
		tmp.read_from_binary_file(f2);
		printf("\nОбъект из файла: %s", tmp.get_str());
		cout << endl << tmp;
		fclose(f2);
	}
	else {
		cout << "\nОшибка чтения в файл";
	}

#endif // 0

	//==================================================================
	// К следующему занятию:

	// - Написать метод для записи объекта MyArray в двоичный файл
	// - Написать метод для инициализации объекта MyArray данными из двоичного файла
	// - Продемонстрировать работу методов

	// - Написать метод для записи объекта ListOneType<Type>  в двоичный файл
	// - Написать метод для инициализации объекта ListOneType<Type> данными из двоичного файла
	// - Продемонстрировать работу методов на типе MyString


	//------------------------------------------------------------------
#if 0

	MyArray a(10, 5,12);
	printf("\nМассив для записи в файл, size = %d \n",a.get_size());
	a.show();


	FILE* f;
	errno_t err;
	err = fopen_s(&f, "mas.txt", "wb");
	if (!err)
	{
		a.save_to_binary_file(f);
		printf("Ok");
		fclose(f);
	}
	else {
		cout << "\nОшибка записи в файл";
	}



	// Чтение из файла с инициализацией объекта

	MyArray tmp;
	printf("\nМассив для чтения из файла, size = %d \n", tmp.get_size());
	tmp.show();

	FILE* f2;
	errno_t err2;
	err2 = fopen_s(&f2, "mas.txt", "rb");
	if (!err2)
	{
		tmp.read_from_binary_file(f2);
		printf("\nМассив для чтения из файла, size = %d \n", tmp.get_size());
		tmp.show();
		fclose(f2);
	}
	else {
		cout << "\nОшибка чтения файла";
	}

#endif // 0
	//------------------------------------------------------------------
#if 0

	ListOneType<MyString> sub;
	sub.add_end("C++");
	sub.add_end("Oracle");
	sub.add_end("MS SQL");
	sub.show();

	FILE* file;
	errno_t err;

	err = fopen_s(&file, "subjects.txt", "wb");
	if (!err)
	{
		sub.save_to_binary_file(file);
		printf("Ok\n");
		fclose(file);
	}
	else {
		printf("Ошибка записи в файл");
	}

	ListOneType<MyString> sub2;
	
	err = fopen_s(&file, "subjects.txt", "rb");
	if (!err)
	{
		sub2.read_from_binary_file(file);
		printf("\nСписок из файла: ");
		sub2.show();
		cout << "Размер списка: " << sub2.get_count() << endl;
			
		fclose(file);
	}
	else {
	printf("Ошибка чтения файла");
	}

#endif // 0

	//-------------------------------------------------------------------
#if 1
	//ListOneType<int> sp;

	// Самостоятельно:  Записать объект типа StudentAgr в бинарный файл

	ListOneType<MyString>  sub1, sub2;

	sub1.add_end("C++");
	sub1.add_end("HTML & CSS");

	sub2.add_end("JavaScript");
	sub2.add_end("C#");

	StudentAgr s2("Bogdan", "Vladimir", 30, "UTM",
		MyArray(5, 10, 12), ListOneType<MyString>());

	MyArray arr(4, 9);
	const StudentAgr s3("Davnii", "Eugeniu", 18, "STEP",
		arr, sub1);

	s2.add_subject("Python");

	StudentAgr s4("Poplavets", "Maryna", 20, "STEP",
		MyArray(10, 9, 12), sub2);
	s4.add_subject("Java");

	FILE* file;
	errno_t err;
	cout << "\nСтудент для записи в файл: \n" << s4 << endl;
	err = fopen_s(&file, "student_bin.txt", "wb");
	if (!err)
	{
		//s4.save_to_binary_file(file);
		s4.save_to_binary_file2(file);
		printf("Ok\n");
		fclose(file);
	}
	else {
		printf("Ошибка записи в файл");
	}

	StudentAgr tmp;
	cout << "\nСтудент для чтения данных из файла: \n"<< tmp<< endl;
	err = fopen_s(&file, "student_bin.txt", "rb");
	if (!err)
	{
		//tmp.read_from_binary_file(file);
		tmp.read_from_binary_file2(file);
		printf("\nСтудент из файла: ");
		cout << tmp;
	
		fclose(file);
	}
	else {
		printf("Ошибка чтения файла");
	}

#endif // 0

	
	

	_getch();
	return 0;
}


