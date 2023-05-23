#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include "Movie.h"
#include "help_func.h"

using namespace std;


void save_and_read_movie(FILE* file, Movie* movies, const int size)
{
   
    if (file)
    {

        for (int i = 0; i < size; i++)
        {
            fprintf(file, "Имя:\t\t %s\nРежисер:\t %s\nЖанр:\t\t %s\nРейтинг:\t %.2lf\nЦена:\t\t %d\n\n",
                movies[i].name,
                movies[i].director,
                movies[i].genre,
                movies[i].rating,
                movies[i].price
            );
        }
    }
    else {
        printf("\nОшибка записи в файл");
    }
}

void show(const Movie& mv)
{
    cout << "\nНазвание фильма:         " << mv.name;
    cout << "\nРежиссер:                " << mv.director;
    cout << "\nЖанр:                    " << mv.genre;
    cout << "\nРейтинг популярности:    " << mv.rating;
    cout << "\nЦена диска:              " << mv.price;
    cout << endl;
}


void show(Movie* movie, int s)
{
    for (int i = 0; i < s; i++)
    {
        show(movie[i]);
    }
}


void destroy(int*& arr)
{
    delete[]arr;
    arr = nullptr;
}