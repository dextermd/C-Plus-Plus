#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

typename int my_int; // синоним имени типа 

//template<typename Type>
template<class Type>
void show(Type arr[], int size, bool direction = true);


template<class Type>
void show(Type arr[][COL], int row);

template<class Type>
Type maximum(Type arr[], int size);

template<class Type>
Type maximum(Type a, Type b);

template<class Type1, class Type2>
Type1 maximum(Type1 a, Type2 b);

template<class Type>
void sort(Type arr[], int size, bool derection = true);


// ----------------------------------------------------------------------------------------- //
// ------------------------------------ Реализация ----------------------------------------- //



template<class Type>
inline void show(Type arr[], int size, bool direction)
{
	if (direction)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else {

		for (int i = size - 1; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
	}

	cout << endl;
}



template<class Type>
inline void show(Type arr[][COL], int row)
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



template<class Type>
inline Type maximum(Type arr[], int size)
{
	Type max;
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


template<class Type>
inline Type maximum(Type a, Type b)
{
	return a > b ? a : b;
}

template<class Type1, class Type2>
inline Type1 maximum(Type1 a, Type2 b)
{
	return a > b ? a : b;
}

template<class Type>
inline void sort(Type arr[], int size, bool derection)
{
	Type t;

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
