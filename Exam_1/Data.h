#pragma once

struct Data {
    int day;
    int month;
    int year;
    int hour;
    int minut;
};

void init(Data& data);

void show(const Data& data, bool str_name = false);

char* month_name(int num);