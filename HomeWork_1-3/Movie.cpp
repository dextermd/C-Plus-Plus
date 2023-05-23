#include "Movie.h"
#include "help_func.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;

void save_and_read_movie(FILE* file, Movie* movies, const int size)
{
    //errno_t err;
    //err = fopen_s(&file, "movies.txt", "w");

    //if (file != nullptr)
    //{
        fprintf(file, "Фамилия: %s ", movies[0].name);


        //for (int i = 0; i < size; i++)
        //{
        //    //fprintf(file, " %d", student.marks[i]);
        //}

        printf("\nOk");
    //}
    //else {
    //    printf("\nОшибка записи в файл");
    //}
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