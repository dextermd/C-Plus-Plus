#include "Data.h"
#pragma once

struct Todo {
	char title[50];
	char priority[50];
	char desc[300];
	Data datetime;

};

void show(Todo& todo);

void show(Todo* arr, int size);

void init(Todo& data);

void init(Todo* arr, int index);

bool search(Todo* arr, int size, const char* search_key, int where_find);

bool search_by_date(Todo* arr, int size, int d, int mo, int y, int h, int mi);

bool view_by_date(Todo* arr, int size, int option);

bool sort_by_priority(const Todo& a, const Todo& b);

bool sort_by_date_time(const Todo& a, const Todo& b);
