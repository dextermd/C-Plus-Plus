#pragma once
#include <iostream>
using namespace std;


struct Node           // ���� ������
{
	int x;            // �������� ����
	Node *left, *right, *parent; // ��������� �� ����� ����

	// �����������							
	Node() {
		left = right = parent = 0;
	}
};



class BTree
{
	Node * root;	  // ������ �������
public:
	BTree();
	~BTree();
	
	void Show(Node * n );   // ����� �� ���������� ����
	
	Node * GetRoot() { return root; }	// �������� ������

	void Insert(Node * z);  // ���������� ����

	Node * Search(Node * n, int k);  // ����� 

	bool Search(int value);  // ����� �� ��������

	Node * Min(Node * n);   // ����� ������������ ��������

	Node * Max(Node * n);   // ����� ������������� �������� 
	
	Node * Next(Node * n);  // ��������� ��� ���������� ����
	
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Node * z = 0);
	
	

};
