#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void main()
{
    setlocale(LC_CTYPE, "rus");

    //  ������� 4. ��������� ����������� ��� ����� ����� � � �.�������� ���������, �������
    //    ������� �� ����� ������ �������� ����� ���������� ��������� � ������� �� �����.�����������
    //    ������, ����� a > b(������� ����� �� �������� � ��������) � � < b(������� ����� �� ��������
    //    � ��������).� ������ ��������� � � � � ���������.

    int a, b;
    long long summa = 0;
    cout << "������� ��� ����� �����: ";
    cin >> a >> b;
    
    if (a > b || b > a)
    {
        while ( a < b)
        {
            if (a % 2) {
                cout << a << " ";
                summa += a;
            }
            a++;
        }
    
        while (a > b)
        {
            if (a % 2) {
                cout << a << " ";
                summa += a;
            }
            a--;
        }
        cout << "\n����� �����: " << summa << endl;
    }
    else {
        cout << "A == B";
    }
    _getch();
}