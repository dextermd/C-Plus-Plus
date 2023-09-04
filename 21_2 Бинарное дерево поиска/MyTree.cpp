
#include <iostream>
#include "MyTree.h"
using namespace std;



MyTree::Node::Node(int _data, Node * _right , Node *_left )
	: data(_data), left(_left), right(_right)
{
	/*data = _data;
	left = _left;
	right = _right;*/
}



//----------------------------------------------------------
void MyTree::Add(Node *& node, const int& data)
{
	if (node == nullptr)
		node = new Node(data);      // конструктор Node
	else if (data < node->data)
	Add(node->left, data);
	else Add(node->right, data);
}



//----------------------------------------------------------
void MyTree::Show(Node* node)const
{
	if (!node) return;
	//cout << node->data << "  "; //Данные ветки
	Show(node->left);
	cout << node->data << "  "; //Данные ветки
	Show(node->right);
}


//----------------------------------------------------------
void MyTree::DeleteSubMyTree(Node * node)
{
	if (node != nullptr)                
	{
		DeleteSubMyTree(node->left);                
		DeleteSubMyTree(node->right); 
		//cout << endl << node->data << "   ";
		
		delete node;                 
		node = nullptr;                 
		count--;
	}
}

MyTree::Node* MyTree::search(Node* node, int data) const
{
	/*while (node != nullptr && node->data != data)
	{
		if (data >= node->data) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	return node;*/

	if (!node) return nullptr;
	if (node->data == data) return node;
	if (node->data <= data) return search(node->right, data);
	else return search(node->left, data);


}

