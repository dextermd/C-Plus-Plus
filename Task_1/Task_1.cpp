#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  ������� 1. ����� ������������ ���� ����� ����� �� a �� 20 (�������� a �������� � ���������� :
    //  1 <= a <= 20).����������� �������� ������������ ����� �������� � ����������.

    int n, num;
    unsigned long long result;

    cout << "������� �������� �� 1 �� 20: ";
    cin >> n;
    if (n >= 1 && n <= 20)
    {
        result = n;
        num = n;
        while (n >= 1 && n <= 20)
        {
            result *= n;
            n++;
            

        }
        cout << "������������ ����� �� " << num << " �� 20: " << result;
    }
    else
        cout << "\n����� �������� ��������!";




    _getch();
}