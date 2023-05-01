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