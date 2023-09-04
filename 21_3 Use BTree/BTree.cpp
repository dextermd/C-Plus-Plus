
#include <iostream>
#include "BTree.h"

using namespace std;
int tab = 0;
// Конструктор
BTree::BTree()          
{
	root = NULL;
}

//-------------------------------------------------------
// Деструктор
BTree::~BTree()			
{
	//root = NULL;
	Del();
}

//-------------------------------------------------------
// Рекурсивный обход дерева
void BTree::Show(Node * n)   
{
	if (n != 0)
	{
		// обход узлов в порядке: вершина, левое поддерево, правое поддерево,
		//cout << n->x << "  "; 
		Show(n->left);  // Выведем ветку и ее подветки слева
		cout << n->x << "  ";  // Вывод узлов в отсортированном порядке
		Show(n->right); // Выведем ветку и ее подветки справа
		//обход узлов в порядке: левое поддерево, правое поддерево, вершина.
		//cout << n->x << "  ";
	}
}

//-------------------------------------------------------
// Добавление узла
void BTree::Insert( Node * z)
{
	Node * y = NULL;
	Node * n = root;

	//поиск места
	while (n != 0)
	{
		//будущий родитель
		y = n;
		if (z->x < n->x)
			n = n->left;
		else
			n = n->right;
	}
	//заполняем родителя
	z->parent = y;
	
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (z->x < y->x)
		y->left = z;
	else
		y->right = z;
}

//-------------------------------------------------------
// Поиск с возвратом адреса узла
Node * BTree::Search(Node* n, int k)
{
	if (!n) return NULL;
	if (k == n->x)
		return n;
	if (k < n->x)
		return Search(n->left, k);
	else
		return Search(n->right, k);

	//Пока есть узлы и ключи не совпадают
	//	while (n != 0 && k != n->x)
	//	{
	//		if (k < n->x)
	//			n = n->left;
	//		else
	//			n = n->right;
	//	}
	//	return n;
}

//----------------------------------------------------
//Поиск по значению
bool BTree::Search(int value) {
	if (root == NULL) {
		return false;
	}
	else if (value == root->x) {
		return true;
	}
	else if (value < root->x) {
		return Search(root->left, value);
	}
	else {
		return Search(root->right, value);
	}
}



//-------------------------------------------------------
//
Node * BTree::Min(Node * n)
{
	//Поиск самого "левого" узла
	/*if (n != 0)
	while (n->left != 0)
	n = n->left;
	return n;*/

	if (n->left == NULL)
		return n;
	return Min(n->left);
}

//-------------------------------------------------------
//
Node * BTree::Max(Node * n)
{//Поиск самого "правого" узла
	/*if (n != 0)
		while (n->right != 0)
			n = n->right;
	return n;*/

	if (n->right == NULL)
		return n;
	return Max(n->right);
}

//-------------------------------------------------------
//
Node * BTree::Next(Node * n)
{
	Node * y = 0;
	if (n != 0)
	{
		//если есть правый потомок
		if (n->right != 0)
			return Min(n->right);
		//родитель узла
		y = n->parent;
		//если Node не корень и Node справа
		while (y != 0 && n == y->right)
		{
			//Движемся вверх
			n = y;
			y = y->parent;
		}
	}
	return y;
}

//-------------------------------------------------------
void BTree::Del(Node * z)
{
	//удаление куста
	if (z != 0)
	{
		Node * n, *y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			n = y->left;
		else
			n = y->right;
		if (n != 0)
			n->parent = y->parent;
		
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = n;
		else if (y == y->parent->left)
			//слева от родителя?
			y->parent->left = n;
		else
			//справа от родителя?
			y->parent->right = n;
		if (y != z)
		{
			//Копирование данных узла
			z->x = y->x;
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}
