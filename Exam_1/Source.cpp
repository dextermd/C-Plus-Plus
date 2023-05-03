#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <ctime>    
#include <algorithm>
#include "str_func.h"
#include "my_template.h"
#include "Data.h"
#include "Todo.h"

using namespace std;

int main()
{
    

#if 0

    /*
        Написать программу, фильтрующую текст, введенный с клавиатуры.
        Задача программы заключается в считывании текста и отображении его на экране,
        используя замену заданного набора символов на пробелы.

            Программа должна предлагать следующие варианты наборов символов для фильтрации :
                − Символы латинского алфавита
                − Символы кириллицы
                − Символы пунктуации
                − Цифры

        Фильтры могут накладываться последовательно.
        При повторной установке существующего фильтра данный фильтр должен сниматься.
        Использовать цветной вывод символов по фильтрам для наглядности.

        Для определения является ли символ строки символом латинского алфавита, символом
        кириллицы, символом пунктуации либо цифрой написать и использовать пользовательские
        функции.
    */

    //char str[100] = "Hello, Привет, (!@#$%), 777.";

    char buf[200];
    cout << "\nВведите строку: ";
    cin.getline(buf, sizeof(buf));
    char* str = new char[strlen(buf) + 1];

    if (str)
    {
        strcpy_s(str, strlen(buf) + 1, buf);
        char str_cpy[100];

        int menu = 0;
        strcpy_s(str_cpy, str);

        do
        {
            show_str_color(str);

            cout << "\n\nВыберите пункт меню:\n\n";
            cout << "1. Фильтр символов латинского алфавита\n";
            cout << "2. Фильтр кириллицы\n";
            cout << "3. Фильтр пунктуации\n";
            cout << "4. Фильтр цифр\n\n";
            cout << "5. Выход\n\n";

            cout << "Введите номер меню от 1 до 5: ";
            cin >> menu;

            switch (menu)
            {
            case 1:
                system("cls");
                str_filter(str, str_cpy, is_latin);
                break;
            case 2:
                system("cls");
                str_filter(str, str_cpy, is_сyrillic);
                break;
            case 3:
                str_filter(str, str_cpy, is_punctuation);
                system("cls");
                break;
            case 4:
                system("cls");
                str_filter(str, str_cpy, is_num_d);
                break;
            case 5:
                system("cls");
                menu = 5;
                cout << "\nВы вышли!\n";
                break;
            }

        } while (menu != 5);

        delete[]str;
        str = nullptr;
    }


#endif

#if 1
    using namespace std;
    /*
        Приложение должно позволять :

            Добавление дел.У дела есть :
                • название.
                • приоритет.
                • описание.
                • дата, время исполнения.

            Удаление дел.

            Редактирование дел.

            Поиск дел по :
                • названию.
                • приоритету.
                • описанию.
                • дате и времени исполнения.

            Отображение списка дел :
                • на день.
                • на неделю.
                • на месяц.

            При отображении должна быть возможность сортировки :
                • по приоритетy.
                • по дате и времени исполнения.
    */
    int index = 0, size = 1, menu = 1, delete_id = -1, update_id = -1;
    int search_menu = 1, where_find = -1, view_menu = -1;
    bool pr;
    char search_key[30];

    Todo* todo = new Todo[size]{};

 
    do
    {
        cout << "\n\nВыберите пункт меню:\n\n";
        cout << "1. Создать дело\n";
        cout << "2. Удаление дел\n";
        cout << "3. Редактирование дел\n";
        cout << "4. Поиск\n";
        cout << "5. Отображение списка дел\n";
        cout << "6. Выход\n";

        cout << "\n\nВведите номер меню от 1 до 6: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            if (index < size)
            {
                init(todo, index);
                index++;
                system("cls");
                cout << "\n\t\t\t\t\tВы успешно создали дело!";
            }
            else {
                size += 1;
                Todo* new_todo = new Todo[size];
                copy(todo, todo + size - 1 , new_todo);
                delete[] todo; 
                todo = new_todo;
                init(todo, index);
                index++;
              system("cls");
              cout << "\n\t\t\t\t\tВы успешно создали дело!";
            }
            break;        
        case 2:
            system("cls");
            if (strcmp(todo[0].title, "") == 0)
            {
                cout << "\n\t\t\t\t\tПусто!";
            }
            else {
                show(todo, size);
                cout << "\nВыберите ID для удаления: ";
                cin >> delete_id;

                if (delete_id - 1 >= 0 && delete_id - 1 <= size - 1)
                {
                    size -= 1;
                    Todo* delete_todo = new Todo[size];
                    for (int i = 0; i < delete_id - 1; i++)
                    {
                        delete_todo[i] = todo[i];
                    }

                    for (int i = delete_id; i <= size; i++)
                    {
                        delete_todo[i - 1] = todo[i];
                    }

                    for (int i = 0; i < size; i++)
                    {
                        todo[i] = delete_todo[i];
                    }

                    delete[] delete_todo;
                    index--;
                    system("cls");
                    cout << "\n\t\t\t\t\tВы успешно удалили  запись под ID - " << delete_id;
                }
                else {
                    system("cls");
                    cout << "\n\t\t\t\t\tОшибка такого ID нету в списке!";
                }
            }
            

            break;
        case 3:
            system("cls");
            if (strcmp(todo[0].title, "") == 0)
            {
                cout << "\n\t\t\t\t\tПусто!";
            }
            else {
                show(todo, size);
                cout << "\nВыберите ID для редактирования: ";
                cin >> update_id;
                if (update_id - 1 >= 0 && update_id - 1 <= size - 1)
                {
                    init(todo[update_id - 1]);
                    cout << "\n\t\t\t\t\tВы успешно отредактировали запись под ID - " << update_id;
                }
                else {
                    system("cls");
                    cout << "\n\t\t\t\t\tОшибка такого ID нету в списке!";
                }
            }
            break;
        case 4:
            system("cls");
            show(todo, size);
            do
            {
                cout << "\nПоиск по: \n\n";
                cout << "1.Названию\n";
                cout << "2.Приоритету\n";
                cout << "3.Описанию.\n";
                cout << "4.Дате и времени исполнения.\n";
                cout << "5.Выход.\n";
                cout << "\nВведите пункт от 1 до 5: ";
                cin >> search_menu;

                switch (search_menu)
                {
                case 1:
                    system("cls");
                    where_find = 1;

                    cin.ignore(256, '\n');
                    cout << "\nВведите название: ";
                    cin.getline(search_key, sizeof(search_key));
                    pr = search(todo, size, search_key, where_find);
                    if (!pr)
                    {
                        cout << "\nДел с таким названием не найдено\n";
                    }
                    pr = false;
                    break;
                case 2:
                    system("cls");
                    where_find = 2;
                    cin.ignore(256, '\n');
                    cout << "\nВведите приоритет: ";
                    cin.getline(search_key, sizeof(search_key));
                    pr = search(todo, size, search_key, where_find);
                    if (!pr)
                    {
                        cout << "\nДел с таким приоритетом не найдено\n";
                    }
                    pr = false;
                    break;
                case 3:
                    system("cls");
                    where_find = 3;
                    cin.ignore(256, '\n');
                    cout << "\nВведите описание: ";
                    cin.getline(search_key, sizeof(search_key));
                    pr = search(todo, size, search_key, where_find);
                    if (!pr)
                    {
                        cout << "\nДел с таким описанием не найдено\n";
                    }
                    pr = false;
                    break;
                case 4:
                    system("cls");
                    int d, mo, y, h, mi;
                    cin.ignore(256, '\n');
                    cout << "\nВведите день, месяц, год, час, рязделяя пробелом: ";
                    cin >> d >> mo >> y >> h >> mi;
                    cin.getline(search_key, sizeof(search_key));
                    pr = search_by_date(todo, size, d, mo, y, h, mi);
                    if (!pr)
                    {
                        cout << "\nДел с такой датой и временем нет!\n";
                    }
                    pr = false;
                    break;
                case 5:
                    search_menu = 5;
                    system("cls");
                    break;
                }

            } while (search_menu != 5);
            break;
        case 5:
            system("cls");
            if (strcmp(todo[0].title, "") == 0)
            {
                cout << "\n\t\t\t\t\tПусто!";
            }
            else {
                do
                {
                    cout << "\nОтображение списка на: \n\n";
                    cout << "1.День.\n";
                    cout << "2.Неделю.\n";
                    cout << "3.Месяц.\n";
                    cout << "\nВведите пункт от 1 до 3: ";
                    cin >> view_menu;

                    switch (view_menu)
                    {
                    case 1:
                        system("cls");
                        sort(todo, size, sort_by_priority);
                        show(todo, size);

                        break;
                    case 2:
                        system("cls");
                        sort(todo, size, sort_by_date_time);
                        show(todo, size);
                        break;
                    case 3:
                        view_menu = 3;
                        system("cls");
                        break;
                    }

                } while (view_menu != 3);

            }
            break;
        }
    } while (menu != 10);

    delete[] todo;

  
#endif


    _getch();
}