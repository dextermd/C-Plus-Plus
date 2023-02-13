#include <iostream>
#include <stdlib.h>
#include "array_functions.h"

using namespace std;

void show(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

double media_array(int array[], int size)
{
	double summa = 0;

	for (int i = 0; i < size; i++)
	{
		summa += array[i];
	}

	return summa / size;
}

bool find_number(int array[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			return true;
		}
	}

	return false;
}

int find_count_number(int array[], int size, int key)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			count++;
		}
	}

	return count;
}

int find_index_number(int array[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			return i;
		}
	}

	return -1;
}

bool is_array_palindrom(int array[], int size)
{
	for (int i = 0, j = size - 1; i <= j ; i++, j--)
	{
		if (array[i] != array[j])
		{
			return false;
		}
	}
	return true;
}
