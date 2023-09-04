#pragma once
#include <iostream>
using namespace std;


struct Node           // Узел дерева
{
	int x;            // Значение узла
	Node *left, *right, *parent; // Указатели на новые узлы

	// конструктор							
	Node() {
		left = right = parent = 0;
	}
};



class BTree
{
	Node * root;	  // Корень деверва
public:
	BTree();
	~BTree();
	
	void Show(Node * n );   // Вывод от указанного узла
	
	Node * GetRoot() { return root; }	// Получить корень

	void Insert(Node * z);  // Добавление узла

	Node * Search(Node * n, int k);  // Поиск 

	bool Search(int value);  // Поиск по значению

	Node * Min(Node * n);   // Поиск минимального значения

	Node * Max(Node * n);   // Поиск максимального значения 
	
	Node * Next(Node * n);  // Следующий для указанного узла
	
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Node * z = 0);
	
	

};
