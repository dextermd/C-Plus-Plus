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

    int num = 99, k = 0, n1, n2, n3;
    while (num < 999)
    {
        num++;
        n1 = num / 100;
        n2 = num % 100 / 10;
        n3 = num % 10;

        if (n1 != n2 && n1 != n3 && n2 != n1 && n2 != n3 && n3 != n1 && n3 != n2)
        {
            cout << n1 << n2 <<n3 << " ";
            k++;
        }
    }

    cout << "\n\n\t\t\t\t\t\t���-�� ����� �� ������ = " << k;
    
    _getch();
}