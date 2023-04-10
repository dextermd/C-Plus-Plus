#include <iostream>
#include "Student.h"

using namespace std;

void show(const Student& st)
{
	cout << "\nИмя:             " << st.name;
	cout << "\nФамилия:         " << st.surname;
	cout << "\nВуз:             " << st.vuz;
	cout << "\nДата рождения:    " << st.birthday.day << "." << st.birthday.month << "." << st.birthday.year;
	cout << "\nОценки :         ";

	for (int i = 0; i < 5; i++)
	{
		cout << st.marks[i] << " ";
	}

	cout << endl;
}

void show(Student* m, int s)
{
	for (int i = 0; i < s; i++)
	{
		show(m[i]);
	}
}

void init(Student& data)
{
	cout << "\nИмя:              ";
	cin.getline(data.name, sizeof(data.name));
	cout << "\nФамилия:          ";
	cin.getline(data.surname, sizeof(data.surname));
	cout << "\nВуз:              ";
	cin.getline(data.vuz, sizeof(data.vuz));

	//cout << "\nДата рождения(день, месяцm год):     ";
	//cin >> data.birthday.day >> data.birthday.month >> data.birthday.year;

	cout << "\nДата рождения(день, месяцm год):    ";
	show(data.birthday, true);

	cout << "\nОценки(кол-во 5): ";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ": ";
		cin >> data.marks[i];
	}

}

double average(const Student& data)
{
	double avg = 0;

	for (int i = 0; i < data.N; i++)
	{
		avg += data.marks[i];
	}

	return avg / data.N;
}

int find_student(Student* m, int size, const char* surname)
{
	for (int i = 0; i < size; i++)
	{
		//if (strcmp(m[i].surname, surname) == 0) // strcmp сравнивает два char
		if (_strcmpi(m[i].surname, surname) == 0)// _strcmpi сравнивает два char без учета регистра на латинице
		{
			return i;
		}
	}

	return -1;
}

Student best(Student* mas, int size)
{
	Student max;
	
	max = mas[0];
	for (int i = 1; i < size; i++)
	{
		if (average(mas[i]) > average(max))
		{
			max = mas[i];
		}
	}

	return max;
}

void show_best(Student* mas, int size)
{
	Student b = best(mas, size);
	double media = average(b);

	for (int i = 0; i < size; i++)
	{
		if (average(mas[i]) == media)
		{
			show(mas[i]);
		}
	}
}


