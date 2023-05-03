#pragma once
#include <iostream>


using namespace std;

template<class Type>
void str_filter(Type* s, Type* c, bool (*pf)(char symb))
{
    for (int i = 0; i < strlen(s); i++)
    {
        if ((*pf)(s[i]))
        {
            s[i] = ' ';
        }
        else if (!(*pf)(s[i])  && (*pf)(c[i])) {
            s[i] = c[i];
        }

    }

    cout << endl;
}


template<class Type>
void sort(Type* mas, int size, bool (*pf)(const Type&, const Type&))
{
    Type t;
    for (int i = 0; i < size - 1; i++)
    {
        for (int k = 0; k < size - 1; k++)
        {
            if ((*pf)(mas[k], mas[k + 1]))
            {
                t = mas[k];
                mas[k] = mas[k + 1];
                mas[k + 1] = t;
            }
        }
    }
}