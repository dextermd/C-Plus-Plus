#include <iostream>
#include "Todo.h"

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
	cout << "\nНазвание:					 ";
	cin.getline(data.title, sizeof(data.title));
	cout << "\nПриоритет:					 ";
	cin.getline(data.priority, sizeof(data.priority));
	cout << "\nОписание:					 ";
	cin.getline(data.desc, sizeof(data.desc));

	init(data.datetime);
}

void init(Todo* arr, int index)
{
	cin.ignore(256, '\n');
	cout << "\nНазвание:					 ";
	cin.getline(arr[index].title, sizeof(arr[index].title));
	cout << "\nПриоритет:					 ";
	cin.getline(arr[index].priority, sizeof(arr[index].priority));
	cout << "\nОписание:					 ";
	cin.getline(arr[index].desc, sizeof(arr[index].desc));

	init(arr[index].datetime);
}