#include <iostream>
#include "Todo.h"
#include "str_func.h"

using namespace std;

void show(Todo& todo)
{

	cout << "\nНазвание:					" << todo.title;
	cout << "\nПриоритет:					" << todo.priority;
	cout << "\nОписание:					" << todo.desc;
	cout << "\nДата, время исполнения:				";
	show(todo.datetime);
	cout << endl;
}

void show(Todo* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl << "ID - " << i + 1 << " ===================================================================";
		show(arr[i]);
		cout << "==========================================================================\n";

	}
}

void init(Todo& data)
{

	do
	{
		cout << "\nНазвание:					 ";
		cin.getline(data.title, sizeof(data.title));
	} while (!isalpha(data.title[0]) && !isdigit(data.title[0]));

	cout << "\nПриоритет:					 ";
	cin.getline(data.priority, sizeof(data.priority));

	cout << "\nОписание:					 ";
	cin.getline(data.desc, sizeof(data.desc));

	init(data.datetime);
}

void init(Todo* arr, int index)
{
	cin.ignore(256, '\n');

	do
	{
		cout << "\nНазвание:					 ";
		cin.getline(arr[index].title, sizeof(arr[index].title));
	} while (!isalpha(arr[index].title[0]) && !isdigit(arr[index].title[0]));

	cout << "\nПриоритет:					 ";
	cin.getline(arr[index].priority, sizeof(arr[index].priority));

	cout << "\nОписание:					 ";
	cin.getline(arr[index].desc, sizeof(arr[index].desc));

	init(arr[index].datetime);
}

bool search(Todo* arr, int size, const char* search_key, int where_find) {
	bool p = false;

	if (where_find == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (_strcmpi(arr[i].title, search_key) == 0)
			{
				show(arr[i]);
				p = true;
			}
		}
	}

	if (where_find == 2)
	{
		for (int i = 0; i < size; i++)
		{
			if (_strcmpi(arr[i].priority, search_key) == 0)
			{
				show(arr[i]);
				p = true;
			}
		}
	}

	if (where_find == 3)
	{
		for (int i = 0; i < size; i++)
		{
			if (_strcmpi(arr[i].desc, search_key) == 0)
			{
				show(arr[i]);
				p = true;
			}
		}
	}


	return p;
}


bool search_by_date(Todo* arr, int size, int d, int mo, int y, int h, int mi)
{
	bool p = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].datetime.day == d && arr[i].datetime.month == mo && arr[i].datetime.year == y && arr[i].datetime.hour == h && arr[i].datetime.minut == mi)
		{
			show(arr[i]);
			p = true;
		}
	}
	

	return p;
}


bool sort_by_priority(const Todo& a, const Todo& b)
{
	return _strcmpi(a.priority, b.priority) > 0;
}

bool sort_by_date_time(const Todo& a, const Todo& b)
{
	int aa = a.datetime.day + a.datetime.month + a.datetime.year + a.datetime.hour;
	int bb = b.datetime.day + b.datetime.month + b.datetime.year + b.datetime.hour;
	return aa > bb;
}