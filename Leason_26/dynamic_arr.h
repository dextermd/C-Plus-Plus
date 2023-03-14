#pragma once
int* memory(int size);
void init(int* m, int size, int = 1, int b = 10);
void showDynamArr(int* m, int size);
void destroy(int*& m);
int* mas_odd(int* m, int size, int& size2);
int* push_back(int* m, int size, int &size2, int value);
int* push_start(int* m, int size, int &size2, int value);
void mas_odd(int*& m, int& size);
void push_back(int*& m, int& size, int value);
void add_by_index(int*& m, int& size, int index, int value);

//-------------------------
int** memory(int row, int col);
void init(int** m, int row, int col, int a = 1, int b = 10);
void show(int** m, int row, int col);
void destroy(int**& m, int row);