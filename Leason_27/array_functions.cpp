#include <iostream>
#include <stdlib.h>
#include "array_functions.h"
#include <iomanip>

using namespace std;

void show(int array[], int size, bool derection)
{
	if (derection)
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}
	else {

		for (int i = size - 1; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
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

int find_repeat(int array[], int size, int key)
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

int find_index(int array[], int size, int key)
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

void fill(int arr[], int size, int a, int b)
{
	int t;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}

void sort(int arr[], int size, bool derection)
{
	int t;

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size - 1; k++)
		{
			if (derection)
			{
				if (arr[k] > arr[k + 1])
				{
					t = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = t;
				}
			}
			else {
				if (arr[k] < arr[k + 1])
				{
					t = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = t;
				}
			}
		}
	}
}

void fill(int arr[][COL], int row, int a, int b)
{
	int t;

	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < COL; k++)
		{
			arr[i][k] = rand() % (b - a + 1) + a;
		}
	}
}

void show(int arr[][COL], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < COL; k++)
		{
			cout << setw(5) << arr[i][k];
		}
		cout << endl;
	}
}

int find_repeat(int array[][COL], int row, int key)
{
	int c = 0;

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < COL; k++)
		{
			if (array[i][k] == key)
			{
				c++;
			}
		}
	}
	return c;
}

void sort(int arr[][COL], int row)
{
	int min, index_min;

	for (int i = 0; i < row; i++) // проходы по строкам
	{
		for (int j = 0; j < COL; j++) 
		{
			min = arr[i][j];
			index_min = j;

			for (int k = j + 1; k < COL; k++)
			{
				if (arr[i][k] < min)
				{
					min = arr[i][k];
					index_min = k;
				}
			}
			arr[i][index_min] = arr[i][j];
			arr[i][j] = min;
		}
	}
}

int maximum(int arr[], int size)
{
	int max;
	max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}


