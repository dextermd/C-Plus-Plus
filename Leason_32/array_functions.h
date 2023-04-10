#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

void show(int array[], int size, bool derection = true);

double media_array(int array[], int size);

bool find_number(int array[], int size, int key);

int find_repeat(int array[], int size, int key);

int find_index(int array[], int size, int key);

bool is_array_palindrom(int array[], int size);

void fill(int arr[], int size, int a = 1, int b = 10);

void sort(int arr[], int size, bool derection = true);


// Перегрузка (overload) функций;
// Использование одного имени для двух и более функций, 
// которые отличаются количеством и/или типом параметров.
// Тип возвращаемого значения не учитываеются.

const int COL = 5;
void fill(int arr[][COL], int row, int a, int b);

void show(int arr[][COL], int row);

int find_repeat(int array[][COL], int row, int key);

void sort(int arr[][COL], int row);

int maximum(int arr[], int size);

