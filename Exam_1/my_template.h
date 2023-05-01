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
