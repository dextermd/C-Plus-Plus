#pragma once

struct Movie {
    char name[30];
    char director[30];
    char genre[100];
    double rating;
    int price;
};

void save_and_read_movie(FILE* file, Movie* movies, const int size);

void show(const Movie& mv);

void show(Movie* movie, int s);

void destroy(int*& arr);
