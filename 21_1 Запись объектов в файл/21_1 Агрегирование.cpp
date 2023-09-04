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
	// ������ �������� � ������������ ���������� ������ � �������� ����---
	// 
	// ������ MyString � �������� ���� 

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
		cout << "\n������ ������ � ����";
	}



	// ������ �� ����� � �������������� �������

	MyString tmp;
	cout << "\n ������ ��� ����������: " << tmp << endl;

	FILE* f2;
	errno_t err2;
	err2 = fopen_s(&f2, "str.dat", "rb");
	if (!err2)
	{
		tmp.read_from_binary_file(f2);
		printf("\n������ �� �����: %s", tmp.get_str());
		cout << endl << tmp;
		fclose(f2);
	}
	else {
		cout << "\n������ ������ � ����";
	}

#endif // 0

	//==================================================================
	// � ���������� �������:

	// - �������� ����� ��� ������ ������� MyArray � �������� ����
	// - �������� ����� ��� ������������� ������� MyArray ������� �� ��������� �����
	// - ������������������ ������ �������

	// - �������� ����� ��� ������ ������� ListOneType<Type>  � �������� ����
	// - �������� ����� ��� ������������� ������� ListOneType<Type> ������� �� ��������� �����
	// - ������������������ ������ ������� �� ���� MyString


	//------------------------------------------------------------------
#if 0

	MyArray a(10, 5,12);
	printf("\n������ ��� ������ � ����, size = %d \n",a.get_size());
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
		cout << "\n������ ������ � ����";
	}



	// ������ �� ����� � �������������� �������

	MyArray tmp;
	printf("\n������ ��� ������ �� �����, size = %d \n", tmp.get_size());
	tmp.show();

	FILE* f2;
	errno_t err2;
	err2 = fopen_s(&f2, "mas.txt", "rb");
	if (!err2)
	{
		tmp.read_from_binary_file(f2);
		printf("\n������ ��� ������ �� �����, size = %d \n", tmp.get_size());
		tmp.show();
		fclose(f2);
	}
	else {
		cout << "\n������ ������ �����";
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
		printf("������ ������ � ����");
	}

	ListOneType<MyString> sub2;
	
	err = fopen_s(&file, "subjects.txt", "rb");
	if (!err)
	{
		sub2.read_from_binary_file(file);
		printf("\n������ �� �����: ");
		sub2.show();
		cout << "������ ������: " << sub2.get_count() << endl;
			
		fclose(file);
	}
	else {
	printf("������ ������ �����");
	}

#endif // 0

	//-------------------------------------------------------------------
#if 1
	//ListOneType<int> sp;

	// ��������������:  �������� ������ ���� StudentAgr � �������� ����

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
	cout << "\n������� ��� ������ � ����: \n" << s4 << endl;
	err = fopen_s(&file, "student_bin.txt", "wb");
	if (!err)
	{
		//s4.save_to_binary_file(file);
		s4.save_to_binary_file2(file);
		printf("Ok\n");
		fclose(file);
	}
	else {
		printf("������ ������ � ����");
	}

	StudentAgr tmp;
	cout << "\n������� ��� ������ ������ �� �����: \n"<< tmp<< endl;
	err = fopen_s(&file, "student_bin.txt", "rb");
	if (!err)
	{
		//tmp.read_from_binary_file(file);
		tmp.read_from_binary_file2(file);
		printf("\n������� �� �����: ");
		cout << tmp;
	
		fclose(file);
	}
	else {
		printf("������ ������ �����");
	}

#endif // 0

	
	

	_getch();
	return 0;
}


