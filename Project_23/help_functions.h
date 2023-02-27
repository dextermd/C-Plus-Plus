#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


bool is_number_even(int n);

bool is_pythagoras(int a, int b, int c);

bool is_greater(int a, int b);

int count_digits(long long a);

int digit_by_pos(long long n, int pos);

bool is_number_palindrom(long long n);

void line(char symbol, int count = 10);

// Функция с параметрами по умолчанию
long long volume(int h = 2, int w = 3, int d = 6);

long area(int w, int h);

double area(int r);

// inline  - подставляемые функции 
inline void print(unsigned int v) { cout << "\"" << v << "\""; }
inline void print(float v) { cout << "{" << v << "}"; }
