#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class Type>
Type get_minimum(Type arr[], int size);

const int COL = 6;
template<class Type>
Type get_minimum(Type arr[][COL], int row);

template<class Type>
Type get_minimum(Type a , Type b, Type c);

template<class Type>
Type get_minimum(Type a, Type b);

template<class Type>
void show_array(Type arr[][COL], int row);

template<class Type>
void show_array(Type arr[], int row);

template<class Type>
void sort_array(Type arr[][COL], int row);

template<class Type>
void random_mixing(Type arr[], Type t_arr[], int size);

template<class Type>
bool is_unique(Type arr[], int size, int key);


template<class Type>
inline Type get_minimum(Type arr[], int size)
{
	Type min = arr[0];

	for (int i = 1; i < size; i++)
	{
		min > arr[i] ? min = arr[i] : min;
	}

	return min;
}


template<class Type>
inline Type get_minimum(Type arr[][COL], int row)
{
	Type min = arr[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			min > arr[i][j] ? min = arr[i][j] : min;
		}
	}

	return min;
}

template<class Type>
inline Type get_minimum(Type a, Type b, Type c)
{
	Type min;
	a > b ? min = b : min = a;
	return min > c ? min = c : min;
}

template<class Type>
inline Type get_minimum(Type a, Type b)
{
	Type min;
	a < b ? min = a : min = b;
	return min;
}

template<class Type>
inline void show_array(Type arr[][COL], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;
}

template<class Type>
inline void show_array(Type arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << endl;
}

template<class Type>
inline void sort_array(Type arr[][COL], int row)
{
	Type min, max;
	int index_min, index_max;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			min = arr[i][j];
			index_min = j;			
			max = arr[i][j];
			index_max = j;

			for (int k = j + 1; k < COL; k++)
			{
				if (arr[i][k] > max && i % 2 != 0)
				{
					max = arr[i][k];
					index_max = k;
				}
				else if (arr[i][k] < min && i % 2 == 0)
				{
					min = arr[i][k];
					index_min = k;
				}

			}

			if (i % 2 != 0)
			{
				arr[i][index_max] = arr[i][j];
				arr[i][j] = max;
			}
			else if (i % 2 == 0)
			{
				arr[i][index_min] = arr[i][j];
				arr[i][j] = min;
			}
		}
	}
}

template<class Type>
inline bool is_unique(Type arr[], int size, int key)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{

		arr[i] == key ? count++ : count;
	}

	return count > 1 ? false : true;
}


template<class Type>
inline void random_mixing(Type arr[], Type t_arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		do
		{
			t_arr[i] = get_random(size);
		} while (!is_unique(t_arr, size, t_arr[i]));
	}

	for (int i = 0; i < size; i++)
	{
		int r_index = t_arr[i];
		int temp;

		temp = arr[i];
		arr[i] = arr[r_index];
		arr[r_index] = temp;
		
	}

}

