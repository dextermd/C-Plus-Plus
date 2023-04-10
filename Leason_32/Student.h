#include "Data.h"

#pragma once

// Описать структуру Студент(имя, фамилия, Вуз, 5 оценок, год рождения)

struct Student {
	static const int N = 5;

	char surname[30];
	char name[20];
	char vuz[50];
	int marks[N];
	// int year;
	Data birthday; // поле, которое является структурой
};

void show(const Student& st);

void show(Student * m, int s);

void init(Student& data);

double average(const Student& data);

int find_student(Student* m, int size, const char* surname);

Student best(Student* mas, int size);

void show_best(Student* mas, int size);