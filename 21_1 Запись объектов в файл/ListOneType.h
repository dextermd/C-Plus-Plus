#pragma once

#include <iostream>
using namespace std;

template<class Type> //requires is_same<Type, MyString>::value || is_same<Type, MyArray>::value
struct ElementType {

	Type data;		// Полезные данные
	ElementType* next;	// адрес следующего элемента

};

template<class Type> 
class ListOneType {
	ElementType<Type> * head;
	int count;

public:
	ListOneType();
	ListOneType(const ListOneType& obj); //конструктор копий

	void add_end(const Type& data);
	void add_begin(const Type& d);
	void add_after(const Type d, const Type add);

	void delete_begin();

	void show()const;

	int get_count()const { return count; }

	bool containe(const Type& data)const;

	ListOneType& operator=(const ListOneType& other);

	Type get_by_pos(const int p)const;

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

	~ListOneType();


};

template<class Type>
ListOneType<Type>::ListOneType()
{
	this->head = nullptr;
	count = 0;
}

template<class Type>
ListOneType<Type>::ListOneType(const ListOneType& obj)
{
	this->head = nullptr;
	ElementType<Type>* current = obj.head;

	while (current != nullptr)
	{
		this->add_end(current->data);
		current = current->next;
	}
	//this->count = obj.count;
}
template<class Type>
void ListOneType<Type>::add_end(const Type& data)
{
	// Создание нового элемента

	ElementType<Type>* add = new ElementType<Type>;
	add->data = data;
	add->next = nullptr;

	ElementType<Type>* current = this->head;
	//if(count)  // если список не пуст
	if (this->head != nullptr) // если список не пуст
	{
		while (current->next != nullptr)// пока не добрались до последнего элемента списка
		{
			current = current->next;
		}
		current->next = add; //связь
	}
	else {// если список  пуст
		this->head = add; //связь
	}
	count++;
	
}


template<class Type>
void ListOneType<Type>::add_begin(const Type& data)
{
	ElementType<Type>* add = new ElementType<Type>;		//создание нового элемента
	add->data = data;				//заполнение данными
	add->next = nullptr;			//следующий элемент отсутствует

	if (head == nullptr)// если список  пуст
	{
		head = add;
	}
	else { // если список не пуст
		add->next = head;// 1 связь
		head = add;      // 2 смещение головы списка на добавленный элемент
	}
	count++;
}

template<class Type>
void ListOneType<Type>::add_after(const Type d, const Type add)
{
	if (containe(d))
	{
		ElementType<Type>* e = new ElementType<Type>;
		e->data = add;
		e->next = nullptr;

		ElementType<Type>* t = head;

		while (t->data != d)
			t = t->next;

		e->next = t->next;	//1
		t->next = e;		//2

		count++;
	}

}
template<class Type>
void ListOneType<Type>::delete_begin()
{
	if (head) //если список не пуст
	{
		ElementType<Type>* tmp = this->head;
		this->head = this->head->next;
		delete tmp;
		count--;
	}
	// else cout << "\nСписок пуст";
	// сообщение, если список пуст
}
template<class Type>
void ListOneType<Type>::show() const
{
	if (this->head == nullptr)
	{
		cout << " Список пуст!\n";
		return;
	}
	
	ElementType<Type>* current = this->head;

	//for (int i = 0; i < this->count; i++)
	//{
	//	cout << current->data << "  ";
	//	current = current->next;  // переход на следующий элемент
	//}

	while (current != nullptr)
	{
		cout << current->data << "  ";
		current = current->next; // переход на следующий элемент
	}
	cout << endl;
}
template<class Type>
bool ListOneType<Type>::containe(const Type& data) const
{
	if (!this->head) // если список пуст
		return false;

	ElementType<Type>* current = head;
	while (current != nullptr) {
		if (current->data == data)// значение найдено
		{
			return true;
		}
		current = current->next;
	}
	return false;
}
template<class Type>
ListOneType<Type>::~ListOneType()
{
	ElementType<Type>* current = this->head;
	ElementType<Type>* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = nullptr;
}

template<class Type>
ListOneType<Type> & ListOneType<Type>::operator=(const ListOneType & other)
{
	//this->head = nullptr;
	ElementType<Type>* current = other.head;
	// освобождение памяти -  лучше написать метод void clear()
	// this->clear();

	this->~ListOneType<Type>(); // вызов деструктора в явном виде

	while (current != nullptr) {
		this->add_end(current->data);
		current = current->next;
	}
	return *this;
}

template<class Type>
inline Type ListOneType<Type>::get_by_pos(const int p) const
{
	if (p >= 1 && p <= count) {

		ElementType<Type>* t = head;

		for (int i = 1; i != p; i++)
			t = t->next;
		return t->data;
	}

	cout << "\nНеверная позиция";
	return -1;
}

template<class Type> 
void ListOneType<Type>::save_to_binary_file(FILE* f)
{
	fwrite(&this->count, sizeof(int), 1, f);
	ElementType<Type>* e = head;

	while (e != nullptr)
	{
		(e->data).save_to_binary_file(f);// save_to_binary_file должен быть у Type
		e = e->next;
	}
}

template<class Type>
void ListOneType<Type>::read_from_binary_file(FILE* f)
{
	
	//this->DeleteAll();
	this->~ListOneType();
	int k;
	Type tmp;

	fread(&k, sizeof(int), 1, f);
	while (k)
	{
		tmp.read_from_binary_file(f);// read_to_binary_file должен быть у Type
		this->add_end(tmp);
		k--;
	}

	//---------------------------------------------
	////this->DeleteAll();
	//this->~ListOneType();

	//fread(&this->count, sizeof(int), 1, f);

	//Type tmp;
	//int k = this->count;
	//for(int k = 1; k <=count; k++)
	//{
	//	tmp.read_from_binary_file(f);
	//	this->add_end(tmp);
	//	this->count--;
	//}
	
}