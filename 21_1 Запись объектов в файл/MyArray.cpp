
#include <iostream>
#include <conio.h>   
#include <assert.h>   
#include "MyArray.h"
using namespace std;

//---------------------------------------------
//MyArray::MyArray()
//{
//	size = 5;
//	arr = new int[size];
//	
//	for (int i = 0; i < size; i++)
//		arr[i] = 0;
//	
//	/*arr = nullptr;
//	size = 0;*/
//}

//---------------------------------------------
MyArray::MyArray(unsigned int size, int val)
{
	this->size = size;
	arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		arr[i] = val;
}

//---------------------------------------------
MyArray::MyArray(const int *pn, unsigned int size)
{
	this->size = size;
	arr = new int[this->size];
	
	for (int i = 0; i < this->size; i++)
		arr[i] = pn[i];
}

//---------------------------------------------
MyArray::MyArray(unsigned int size, int a, int b)
{
	if (a > b)
	{
		int t = a;
		a = b;
		b = t;
	}
	this->size = size;
	arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		arr[i] = rand() % (b - a + 1) + a;
}

//---------------------------------------------
MyArray::MyArray(const MyArray & a)
{
	//cout << "\nКонструктор копирования\n";
	size = a.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = a.arr[i];
}

//---------------------------------------------
MyArray::~MyArray()
{
	delete[] arr;
	arr = nullptr;
	/*cout << "\nДеструктор\n";
	_getch();*/
}

//---------------------------------------------
double MyArray::average() const
{
	double sum = 0;
	int i;
	
	for (i = 0; i < this->size; i++)
		sum += arr[i];
	
	if (i > 0)  return sum / i;
	else
	{
		cout << "\nМассив пуст\n";
		return 0;
	}
}

//---------------------------------------------
void MyArray::show()const
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


//---------------------------------------------
void MyArray::init()
{
	cout << "\nВведите количество элементов массива: ";
	cin >> size;
	delete[]arr;
	arr = new int[size];
	cout << "\nВведите значения массива: \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " : ";
		cin >> arr[i];
	}
}

//---------------------------------------------
MyArray MyArray::add(const MyArray& b)const
{
	MyArray t;// По умолчанию выделение памяти под 5 элементов     X100
	if (t.arr)
		delete[]t.arr;// освобождение старой памяти
	t.size = this->size + b.size;
	t.arr = new int[t.size];   // X200
	int k = 0;
	for (int i = 0; i < this->size; i++)
		t.arr[k++] = this->arr[i];
	for (int i = 0; i < b.size; i++)
		t.arr[k++] = b.arr[i];
	return t;
}



//-----------------------------------------------

MyArray& MyArray::operator=(const MyArray& a)
{
	//cout << "\n Оператор = \n";
	if (this == &a)
		return *this;
	delete[] arr;
	size = a.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = a.arr[i];
	return *this;
}

//----------------------------------------------------
ostream& operator<<(ostream& os, const MyArray& a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		os << a.arr[i] << " ";
	}
	return os;
}

//----------------------------------------------------
istream& operator>>(istream& is, MyArray& a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		is >> a.arr[i];
	}

	return is;
}

int& MyArray::operator[](int i)
{
	assert(i >= 0 && i < size);
	return arr[i];
}
//---------------------------------------------

const int& MyArray::operator[](int i) const
{

	/*if (i < 0 || i >= size)
	{
	cout << "Неверный индекс : " << i << endl;
	exit(1);
	}*/

	assert(i >= 0 && i < size);
	return arr[i];
}


void MyArray::set_size(unsigned int size)
{
	delete[]arr;
	this->size = size;
	if (this->size)
		this->arr = new int[this->size]{ 0 };
	else this->arr = nullptr;
}


void MyArray::save_to_binary_file(FILE* f)
{
	fwrite(&size, sizeof(size), 1, f);// запись количества элементов массива

	// Запись значений массива - Вариант 1
	/*for(int i = 0; i < size; i++)
		fwrite(&arr[i], sizeof(arr[i]), 1, f);*/

		// Запись значений массива - Вариант 2
	fwrite(arr, sizeof(int) * size, 1, f);

	// Запись значений массива - Вариант 3
	//fwrite(arr, sizeof(int), size, f);
}

void MyArray::read_from_binary_file(FILE* f)
{
	delete[]arr;
	fread(&size, sizeof(size), 1, f);
	arr = new int[size];

	// Чтение значений массива - Вариант 1
	/*for (int i = 0; i < size; i++)
		fread(&arr[i], sizeof(arr[i]), 1, f);*/

		// Чтение значений массива - Вариант 2
	//fread(arr, sizeof(int) * size, 1, f);
	fread_s(arr, sizeof(int) * size, sizeof(int), size, f);


	// Чтение значений массива - Вариант 3
	//fread(arr, sizeof(arr[0]), size, f);

}