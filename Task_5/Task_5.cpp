#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  ������� 5. ��������� ���������� ����� ����� � ��������� �� 100 �� 999, � ������� ��� �����
    //    ������.������� �� ����� ��� ����� � �� ����������.

    int num = 99, k = 0;
    while (num < 999)
    {
        num++;
        if (num % 2 == 0)
        {
            cout << num << " ";
            k++;
        }
    }
    cout << "���-�� ����� �� ������ = " << k;
    
    _getch();
}