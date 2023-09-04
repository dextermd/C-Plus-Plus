
#include <iostream>
#include "BTree.h"

using namespace std;
int tab = 0;
// �����������
BTree::BTree()          
{
	root = NULL;
}

//-------------------------------------------------------
// ����������
BTree::~BTree()			
{
	//root = NULL;
	Del();
}

//-------------------------------------------------------
// ����������� ����� ������
void BTree::Show(Node * n)   
{
	if (n != 0)
	{
		// ����� ����� � �������: �������, ����� ���������, ������ ���������,
		//cout << n->x << "  "; 
		Show(n->left);  // ������� ����� � �� �������� �����
		cout << n->x << "  ";  // ����� ����� � ��������������� �������
		Show(n->right); // ������� ����� � �� �������� ������
		//����� ����� � �������: ����� ���������, ������ ���������, �������.
		//cout << n->x << "  ";
	}
}

//-------------------------------------------------------
// ���������� ����
void BTree::Insert( Node * z)
{
	Node * y = NULL;
	Node * n = root;

	//����� �����
	while (n != 0)
	{
		//������� ��������
		y = n;
		if (z->x < n->x)
			n = n->left;
		else
			n = n->right;
	}
	//��������� ��������
	z->parent = y;
	
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (z->x < y->x)
		y->left = z;
	else
		y->right = z;
}

//-------------------------------------------------------
// ����� � ��������� ������ ����
Node * BTree::Search(Node* n, int k)
{
	if (!n) return NULL;
	if (k == n->x)
		return n;
	if (k < n->x)
		return Search(n->left, k);
	else
		return Search(n->right, k);

	//���� ���� ���� � ����� �� ���������
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
//����� �� ��������
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
	//����� ������ "������" ����
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
{//����� ������ "�������" ����
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
		//���� ���� ������ �������
		if (n->right != 0)
			return Min(n->right);
		//�������� ����
		y = n->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && n == y->right)
		{
			//�������� �����
			n = y;
			y = y->parent;
		}
	}
	return y;
}

//-------------------------------------------------------
void BTree::Del(Node * z)
{
	//�������� �����
	if (z != 0)
	{
		Node * n, *y;
		//�� 2 �������
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
		
		//��������� �������� ����?
		if (y->parent == 0)
			root = n;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = n;
		else
			//������ �� ��������?
			y->parent->right = n;
		if (y != z)
		{
			//����������� ������ ����
			z->x = y->x;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}
