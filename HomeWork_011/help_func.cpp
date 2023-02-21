#include <iostream>
#include <stdlib.h>
#include "help_func.h"

using namespace std;

void show_rectangle(int w, int h, char symbol)
{

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (i == 0 || i == w - 1 || j == 0 || j == h - 1)
			{
				cout << symbol << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

int get_perfect_number_count(int arr[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (is_perfect_number(arr[i]))
		{
			count++;
		}
	}
	
	return count;
}

int get_perfect_number_count(int arr[][COP], int row)
{
	int count = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COP; j++)
		{
			if (is_perfect_number(arr[i][j]))
			{
				count++;
			}
		}
	}

	return count;
}


bool is_perfect_number(int num)
{
	int summa = 0;

	for (int i = 1; i < num / 2; i++)
	{
		if (num % i == 0)
		{
			summa += i;
		}
	}
	
	summa += num / 2;

	return summa == num ? true : false;
}

int get_summa(int num)
{
	int summa = 0;

	while (num)
	{
		summa += num % 10;
		num /= 10;
	}

	return summa;
}

int get_summa(int arr[], int size)
{
	int summa = 0;

	for (int i = 0; i < size; i++)
	{
		summa += arr[i];
	}
	return summa;
}

int get_random(int size)
{
	return rand() % (((size - 1) - 0 + 1) + 0);
}
