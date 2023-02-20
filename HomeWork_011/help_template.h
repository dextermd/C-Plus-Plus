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
