#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  ������� 3. �������� ���������, ������� ������� �� ����� ������� ��������� �� k, ��� k �
    //    ����� ��������.��������, ��� 7 - �� �������� :
    //      7 x 2 = 14
    //      7 x 3 = 21
    //      � �.�.


    int n,k = 2;

    cout << "������� ����� �� 1 �� 10: ";
    cin >> n;

    if (n >= 1 && n <= 10)
    {
        while (k >= 1 && k <= 10)
        {
            cout << n << " x " << k << " = " << n * k << endl;
            k++;
        }
    }
    else
        cout << "\n����� �������� ��������!";




    _getch();
}