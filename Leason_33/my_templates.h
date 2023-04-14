#pragma once
#include <iostream>

using namespace std;

template<class Type>
void sort(Type* mas, int size, bool (*pf)(const Type&, const Type&))
{
	cout << "\n******Шаблон функции sort\n";
	Type t;
	for (int i = 0; i < size - 1; i++)
	{
		for (int k = 0; k < size - 1; k++)
		{
			if ((*pf)(mas[k], mas[k + 1])) // Критерий сортировки зависит от фактического параметра
			{
				t = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = t;

				// или spaw(mas[k], mas[k + 1]) // STL
			}
		}
	}
}