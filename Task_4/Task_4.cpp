#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>


using namespace std;

void main()
{

    //setlocale(LC_ALL, "rus");

    //Задание 4. Написать программу «Успеваемость».Пользователь вводит 10 оценок студента,
    //    значения сохраняются в массиве.Осуществлять проверку на корректный ввод оценки
    //    (от 1 до 10).Реализовать меню для пользователя :
    //− Вывод оценок(вывод содержимого массива);
    //− Пересдача экзамена(пользователь вводит порядковый номер оценки и новую
    //    оценку).Осуществлять проверку на корректный ввод номера оценки и самой
    //    оценки;
    //− Максимальная оценка студента;
    //− Минимальная оценка студента;
    //− Средний балл;
    //− Выходит ли стипендия(стипендия выходит, если средний бал не ниже 8.5);
    //− Выход из меню.

    const int NUM = 10;
    int arr[NUM], num, max, min;
    float bal = 0.;

    cout << "\nВведите " << NUM << " оценок студента: \n";

    for (int i = 0; i < NUM;)
    {   
        cout << "\nВведите оценку номер " << i + 1 << ": ";
        cin >> arr[i];

        if (arr[i] <= 10 && arr[i] > 0)
        {
            i++;
            system("CLS");
        }
        else {
            system("CLS");
            cout << "\nОценка должна быть от 1 до 10: ";
        }
    }

    do
    {
        cout << "\n\tМеню";
        cout << "\n1.[Вывести оценки]";
        cout << "\n2.[Пересдача экзамена]";
        cout << "\n3.[Максимальная оценка]";
        cout << "\n4.[Минимальная оценка]";
        cout << "\n5.[Средний балл]";
        cout << "\n6.[Выходит ли стипендия]";
        cout << "\n0.[Выход из меню]";
        cout << "\n\n------------------------";

        cout << "\n\nВведите пункт меню от 0 до 6: ";
        cin >> num;

        switch (num)
        {
            case 1:
                system("CLS");
                cout << "\n\n\nОценки студента: ";
                for (int i = 0; i < NUM; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << "\n\n\n";
                break;
            case 2:
                int grade_index, new_grade;
                system("CLS");
                cout << "\n\tПересдача экзамена";
                cout << "\nВведите порядковый номер оценки от 1 до 10: ";
                cin >> grade_index;
                if (grade_index >=1 && grade_index <= 10)
                {
                    cout << "\nВведите новую оценку от 1 до 10: ";
                    cin >> new_grade;
                    if (new_grade >=1 && new_grade <= 10)
                    {
                        arr[grade_index - 1] = new_grade;
                    }
                    else {
                        cout << "\nНеверная оценка!";
                    }
                }
                else {
                    cout << "\nНеверный порядковый номер оценки!";
                }
                cout << "\n\n\n";
                break;
            case 3:
                system("CLS");
                cout << "\n\tМаксимальная оценка студента: ";
                max = arr[0];
                for (int i = 1; i < NUM; i++)
                {
                    arr[i] > max ? max = arr[i] : max;
                }
                cout << max;
                cout << "\n\n\n";
                break;
            case 4:
                system("CLS");
                cout << "\n\tМинимальная оценка студента: ";
                min = arr[0];
                for (int i = 1; i < NUM; i++)
                {
                    arr[i] < min ? min = arr[i] : min;
                }
                cout << min;
                cout << "\n\n\n";
                break;
            case 5:
                system("CLS");
                cout << "\n\tСредний балл студента: ";
                for (int i = 0; i < NUM; i++)
                {
                    bal += arr[i];
                }
                bal /= NUM;
                cout << bal;
                cout << "\n\n\n";
                break;
            case 6:
                system("CLS");
                bal >= 8.5 ? (cout << "\n\tCтипендия есть!") : (cout << "\n\tCтипендии нету :(");
                cout << "\n\n\n";
                break;
            default:
                break;
        }
    } while (num);


    _getch();
}