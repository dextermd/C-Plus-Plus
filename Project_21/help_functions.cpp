#include <iostream>
#include <stdlib.h>
#include "help_functions.h"

using namespace std;


bool is_number_even(int n)
{
	return (n % 2 == 0);
}

bool is_pythagoras(int a, int b, int c)
{

	return a * a + b * b == c * c;
	
}

int count_digits(long long a)
{
    int k = 0;
    while (a) {
        a /= 10;
        k++;
    }

    return k;

}

int digit_by_pos(long long n, int pos)
{
    int k = count_digits(n); // количество цифр
    while (k > pos)
    {
        n /= 10;
        k--;
    }
    return n % 10;
}


bool is_greater(int a, int b)
{
	return (a > b);
}


bool is_number_palindrom(long long n)
{

    int k = count_digits(n);

    for (int i = 1; i <= k; i++)
    {
        if (digit_by_pos(n, i) != digit_by_pos(n, k--))
        {
            return false;
        }
    }

    return true;
    
}

void line(char symbol, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << symbol << " ";
    }
}

long long volume(int h, int w, int d)
{
    return h * w * d;
}
