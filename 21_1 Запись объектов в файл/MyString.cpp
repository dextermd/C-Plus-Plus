//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <assert.h>
#include "MyString.h"
#include <assert.h>

using namespace std;

//#define DEBUG

int MyString::count = 0;

//MyString::MyString() // C++
//{
//#ifdef DEBUG
//	cout << "\nКонструткор по умолчанию\n";
//#endif // DEBUG
//
//	length = 3;
//	str = new char[length + 1];
//	strcpy_s(str, length + 1, "C++");
//	count++;
//}

MyString::MyString(const char* str)
{
#ifdef DEBUG
	cout << "\nКонструктор преобразования\n";
#endif // DEBUG
	this->length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
	count++;
}


MyString::MyString(const MyString & obj)
{
#ifdef DEBUG
	cout << "\nКонструктор копирования\n";
#endif // DEBUG
	this->length = obj.length;
	// Глубокое копирование
	this->str = new char[this->length + 1];
	strcpy_s(this->str, this->length + 1, obj.str);
	count++;
}

MyString::MyString(int len, char symbol) : length{ len }
{
#ifdef DEBUG
	cout << "\nКонструктор с двумя параметрами - длина и символ\n";
#endif // DEBUG
	str = new char[length + 1];
	if (str)
	{
		for (int i = 0; i < length; i++)
		{
			str[i] = symbol;
		}
		str[length] = '\0';
		count++;
	}
	else
	{
		cout << "Память не выделена";
		str = nullptr;
		length = 0;
	}

}

void MyString::init()
{
	char buf[500];
#ifdef DEBUG
	cout << "\nВведите строку: ";
#endif // DEBUG

	cin.getline(buf, sizeof(buf));
	if (strlen(str) != strlen(buf))
	{
		delete[] str; // освобождение старой памяти
		length = strlen(buf);// длина новой строки
		str = new char[length + 1];// выделение памяти под новое содержимое
	}
	strcpy_s(str, length + 1, buf);
}

void MyString::init(const char* str)
{
	if (strlen(this->str) != strlen(str))
	{
		delete[]this->str;
		length = strlen(str);
		this->str = new char[length + 1];
	}
	strcpy_s(this->str, length + 1, str);
}



int MyString::getLength()const
{
	return length;
}

/*static*/ int MyString::getCount() //статический метод
{
	return count; 
}

void MyString::show()const
{
	/*std::*/cout << str;

#ifdef DEBUG
	cout << endl;
#endif // DEBUG
}

MyString MyString::add(const MyString& obj)const
{
	// v 1
	//MyString result; // C++
	//if (result.str)
	//{
	//	delete[]result.str;
	//}
	//result.length = obj.length + this->length;
	//result.str = new char[result.length + 1];
	
	// v2
	int max_size = this->length + obj.length;
	MyString result(max_size, ' ');

	//выполняется в обоих версиях
	strcpy_s(result.str, result.length + 1, this->str);
	strcat_s(result.str, result.length + 1, obj.str);

	return result;
}
MyString MyString::operator+(const MyString& obj)const
{
	// v2
	int max_size = this->length + obj.length;
	MyString result(max_size, ' ');

	//выполняется в обоих версиях
	strcpy_s(result.str, result.length + 1, this->str);
	strcat_s(result.str, result.length + 1, obj.str);

	return result;
}

MyString& MyString::operator+=(const MyString& obj)
{
	// v2
	char* old_str = this->str;// сохраняем адрес старой строки

	this->length += obj.length;// новая длина
	this->str = new char[this->length + 1];// новая память
	strcpy_s(this->str, this->length + 1, old_str);// копируем старое содержимое
	strcat_s(this->str, this->length + 1, obj.str);// конкатенируем новую строку

	delete[]old_str;// освобождение старой памяти
	return *this;

	// v1
	//MyString temp = *this + obj;
	//*this = temp;

	//return *this;
}

MyString& MyString::operator=(const MyString& obj)
{
	//защита от "дурака"
	if (this == &obj)
	{
		return *this;
	}

	if (this->length != obj.length) {
		this->length = obj.length;
		delete[]this->str;
		this->str = new char[/*strlen(obj.str)*/this->length + 1];
	}
	strcpy_s(this->str, /*strlen(obj.str)*/this->length + 1, obj.str);
	
	return *this;
}

const char MyString::operator[](const int index)const
{
	//index = 10;//error
	/*if (index < 0 || index > this->length)
	{
		cout << "\nНеверный индекс\n";
		return '\0';
	}*/
	assert(index >= 0 && index < this->length);

	// throw

	return this->str[index];
}

char& MyString::operator[](const int index)
{
	assert(index >= 0 && index < this->length);
	return this->str[index];
}

bool MyString::operator==(const MyString& obj) const
{
	//return !strcmp(this->str, obj.str);
	//или
	return strcmp(this->str, obj.str) == 0;
	//return _strcmpi(this->str, obj.str) == 0; // без учета регистра только для латинских символов

}

bool MyString::operator!=(const MyString& obj) const
{
	//return strcmp(this->str, obj.str) != 0;

	return !(*this == obj);
}

bool MyString::operator>(const MyString& obj) const
{
	return strcmp(this->str, obj.str) > 0;
	//return _strcmpi(this->str, obj.str) > 0;
}

bool MyString::operator<(const MyString& other)const
{
	return _strcmpi(this->str, other.str) < 0;
}

bool MyString::operator>=(const MyString& other)const
{
	return (*this > other || *this == other);
}

bool MyString::operator<=(const MyString& other)const
{
	return (*this < other || *this == other);
}

// Перегрузка потока вывода на экран <<
ostream& operator<<(ostream& out, const MyString& obj)
{
	cout << obj.str;
	return out;
}

// Перегрузка потока вывода на экран >>
istream& operator>>(istream& in, MyString& obj)
{
	char buf[256];
	in.getline(buf, sizeof(buf));

	if (strlen(obj.str) != strlen(buf)) {
		delete[] obj.str;
		obj.length = strlen(buf);
		obj.str = new char[obj.length + 1];
	}
	strcpy_s(obj.str, obj.length + 1, buf);
	return in;
}
void MyString::operator()(const char* str) {

	if (strlen(this->str) != strlen(str)) {
		delete[]this->str;
		this->length = strlen(str);
		this->str = new char[this->length + 1];
	}
	strcpy_s(this->str, this->length + 1, str);
	}

void MyString::save_to_binary_file(FILE* f)
{
	// запись длины строку
	fwrite(&this->length, sizeof(this->length), 1, f);
	// запись содержимого строки
	fwrite(this->str, this->length + 1, 1, f);
}

void MyString::read_from_binary_file(FILE* f)
{
	delete[]this->str;
	// считываем длины строку
	fread(&this->length, sizeof(this->length), 1, f);
	// выделяем новую память
	this->str = new char[this->length + 1];
	// читаем содержимое строки
	fread(this->str, this->length + 1, 1, f);
}

MyString::~MyString()
{
	count--;
#ifdef DEBUG
	cout << "\nДеструктор  "<< count << endl;
	_getch();
#endif // DEBUG
	
	delete[]str;
	str = nullptr;
}

