#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "array_functions.h"
#include "help_functions.h"
#include "my_template.h"
#include "color.h"

using namespace std;

// Макрос
// #define Имя_макроса(Выражение)
#define LINE {for(int i = 0; i < 10; i++) cout << "="; cout << endl;}

// #define Имя_макроса(Параметры)(Выражение) - Параметризированный макрос
#define SUMMA(X,Y) ((X)+(Y))

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

#define SQ(X) ((X) * (X))

#define PRINT(X) cout << X;

struct Color
{
    int red = 12;
};


int main()
{

    //setlocale(LC_ALL, "rus");

    // ---------------------------------------------------------------------------------------------------------------- //
    // ******************************************  ************************************************* //

    //system("color 1F");

    //cout << "Hello!\n";

    //SetColor(12);

    //cout << "Hello!\n";

    //SetColor(8);

    //cout << "Привет!\n";

    //SetColor(9);

    //cout << "Привет!\n\n";

    //for (int i = 0; i < 16; i++)
    //{
    //    SetColor(i);
    //    cout << "Hello! color # " << i << endl;;
    //}

    //cout << endl;

    //SetColor(15, 1);
    //cout << "Привет!\n";
    //SetColor(4, 0);
    //cout << "Привет!\n";
    //SetColor(15, 7);
    //cout << "Привет!\n";

    //cout << endl;

    //SetColor(15, 0);

    // system("color.r");


    // ---------------------------------------------------------------------------------------------------------------- //
    /*
        Вывести на экран данные одномерного массива, выделив при этом
        четные и нечетные значения разными цветами.
    */

    //const int  N = 10;
    //int arr[N] = { 1,2,3,4,5,6,7,8,9,10 };

    //for (int i = 0; i < N; i++)
    //{
    //    arr[i] = rand() % 21 - 10;
    //    cout << arr[i] << "  ";
    //}

    //cout << endl;

    //for (int i = 0; i < N; i++)
    //{
    //    if (arr[i] % 2 == 0)
    //    {
    //        SetColor(10);
    //    }
    //    else {
    //        SetColor(4);
    //    }
    //    cout << arr[i] << "  ";
    //}




    // ---------------------------------------------------------------------------------------------------------------- //
    // Тип данных enum - Перечисления

    //// Анонимное обьявление
    //enum {BLACK, BLUE, RED = 4, BLUELIGHT = 9, GREEN = 10, WHITE = 15};

    //cout << endl;

    //SetColor(BLUE);
    //cout << "\nТип данных enum - Перечисление BLUE " << BLUE << endl;    
    //
    //SetColor(WHITE);
    //cout << "\nТип данных enum - Перечисление WHITE " << WHITE << endl;

    //SetColor(RED);
    //cout << "\nТип данных enum - Перечисление RED " << RED << endl;

    //SetColor(GREEN);
    //cout << "\nТип данных enum - Перечисление GREEN " << GREEN << endl;


    // ---------------------------- Тип enum - Обьявление с указанием типа

    //enum my_colors{ BLACK, BLUE, GREEN, RED = 4, BLUELIGHT = 9, WHITE = 15 };

    //my_colors mc; // mc - переменная типа my_colors
    //mc = GREEN;

    //cout << endl;

    //SetColor(mc);
    //cout << "\nmc " << mc << endl; // 10

    //int color;
    //SetColor(WHITE);

    //cout << "\nВыбери цвет: \n 1 - Черный\n 2 - Красный\n 3 - Синий\n 4 - Зеленый\n";

    //cin >> color;

    //switch (color)
    //{
    //    case 1: mc = BLACK; break;
    //    case 2: mc = RED; break;
    //    case 3: mc = BLUE; break;
    //    case 4: mc = GREEN; break;
    //        //case 5: mc = YELLOW; break;
    //    default: cout << "\nТакой цвет выбрать нельзя"; mc = WHITE;
    //}

    //SetColor(mc);
    //if (mc != WHITE)
    //    cout << "\nПользователь выбрал этот цвет)\n";

    //enum cars{ MERSEDES, BMW, LEXUS, TOYOTA, DACIA };

    //enum limits{MIN = -100, MAX = 100};


    
    
    _getch();
}
