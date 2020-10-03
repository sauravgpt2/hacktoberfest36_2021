/* Friend class by implementing BST*/
#include <bits/stdc++.h>
using namespace std;

class BST;
class Node
{
private:
	int key;
	Node *left, *right;

public:
	Node(int val) : key(val), left(nullptr), right(nullptr) {}

	friend class BST;
};

class BST
{
private:
	Node *root;
	Node *insert(Node *, int);
	void preOrder(Node *);
	void inOrder(Node *);
	void postOrder(Node *);

public:
	BST()
	{
		root = nullptr;
	}

	void insert(int key)
	{
		root = insert(root, key);
	}

	void traverse();
};

Node *BST::insert(Node *root, int key)
{
	if (!root)
		return new Node(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);

	return root;
}

void BST::preOrder(Node *root)
{
	if (root)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void BST::inOrder(Node *root)
{
	if (root)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

void BST::postOrder(Node *root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->key << " ";
	}
}

void BST::traverse()
{
	preOrder(root);
	cout << "\n";
	inOrder(root);
	cout << "\n";
	postOrder(root);
	cout << "\n";
}

int main()
{
	BST B;
	B.insert(10);
	B.insert(5);
	B.insert(20);
	B.insert(3);
	B.traverse();
}
