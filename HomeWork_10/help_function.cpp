#include "help_function.h"
#include <iostream>

using namespace std;

int get_random_number(int a, int b)
{
	return  a > b ? rand() % (a - b + 1) + b : rand() % (b - a + 1) + a;
}

float cels_to_fahr(int cels)
{
	return cels * 1.8 + 32;
}

int sum_a_to_b(int a, int b)
{
	int sum = 0, max, min;
	
	a < b ? (min = a, max = b) : (max = a, min = b);

	for (int i = min; i <= max; i++)
	{
		sum += i;
	}

	return sum;
}

void show_rectangle(int length, int width, char symbol)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
	        if (i == 0 || i == width - 1 || j == 0 || j == length -1 )
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

void show_number_reverse(int num)
{
	while (num)
	{
		cout << num % 10 << " ";
		num /= 10;
	}
}

int sum_of_number(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

bool is_ultra_number(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0 && i != num)
		{
			sum += i;
		}
	}
	
	return sum == num;
}

int get_min_array(int array[], int size)
{
	int min = array[0];

	for (int i = 1; i < size; i++)
	{
		min > array[i] ? min = array[i] : min;
	}

	return min;
}
