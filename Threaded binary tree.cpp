//============================================================================
// Name        : TBT.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Threaded Binary Tree

#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
   public:
	int data;
	int lbit, rbit;
	node *left, *right;
};
class TBT
{
   private:
	node *root, *dummy;

   public:
	void create(int num);
	void insert(node *trav, node *temp);
	void preorder();
	void inorder();
	void postorder();
	void construction();
	TBT()
	{
		root = NULL;
		dummy = NULL;
	}
} * root, *dummy;

void TBT::create(int num)
{
	node *trav, *temp;
	temp = new node();
	temp->data = num;
	temp->lbit = 0;
	temp->rbit = 0;
	if (root == NULL)
	{
		dummy = new node;
		dummy->data = -9999;
		dummy->lbit = 1;
		dummy->rbit = 1;
		dummy->left = temp;
		dummy->right = dummy;
		temp->left = dummy;
		temp->right = dummy;
		root = temp;
	}
	else
	{
		trav = root;
		insert(trav, temp);
	}
}
void TBT::insert(node *trav, node *temp)
{
	if (temp->data < trav->data)
	{
		if (trav->lbit == 0)
		{
			temp->left = trav->left;
			temp->right = trav;
			trav->left = temp;
			trav->lbit = 1;
		}
		else
		{
			insert(trav->left, temp);
		}
	}
	if (temp->data > trav->data)
	{
		if (trav->rbit == 0)
		{
			temp->right = trav->right;
			temp->left = trav;
			trav->right = temp;
			trav->rbit = 1;
		}
		else
		{
			insert(trav->right, temp);
		}
	}
}

void TBT::preorder()
{
	node *trav;
	trav = root;
	while (trav != dummy)
	{
		cout << trav->data << endl;
		if (trav->lbit == 1)
		{
			trav = trav->left;
		}
		else
		{
			while (trav->rbit == 0 && trav->right != dummy)
			{
				trav = trav->right;
			}
			trav = trav->right;
		}
	}
}

void TBT::inorder()
{
	node *trav;
	trav = root;
	while (trav != dummy)
	{
		while (trav->lbit == 1)
		{
			trav = trav->left;
		}
		cout << trav->data << endl;
		while (trav != dummy)
		{
			if (trav->rbit == 1)
			{
				trav = trav->right;
				while (trav->lbit == 1)
				{
					trav = trav->left;
				}
				cout << trav->data << endl;
			}
			else
			{
				while (trav->rbit == 0)
				{
					trav = trav->right;
					if (trav == dummy)
					{
						break;
					}
					cout << trav->data << endl;
				}
			}
		}
	}
}

void TBT::postorder()
{
	node *trav;
	trav = root;
	if (root == NULL)
		cout << "Empty Tree";
	else
	{
		int a[20], i = 0;
		while (trav != dummy)
		{
			a[i] = trav->data;
			i++;
			if (trav->rbit == 1)
			{
				trav = trav->right;
			}
			else
			{
				while (trav->lbit == 0 && trav->left != dummy)
				{
					trav = trav->left;
				}
				trav = trav->left;
			}
		}
		int n = i - 1;
		for (i = n; i >= 0; i--)
		{
			cout << a[i] << endl;
		}
	}
}

void TBT::construction()
{
	int ch, num, size, i;
	cout << "Enter number of nodes in tree\n";
	cin >> size;
	cout << "Enter the data in the nodes\n";
	for (i = 0; i < size; i++)
	{
		cin >> num;
		create(num);
	}
	do
	{
		cout << "\n------------------\n";
		cout << "Menu\n1.Insert\n2.Pre order traversal\n3.In order traversal\n4.Post order traversal\n5.Exit\n";
		cout << "------------------\n";
		cout << "Enter your choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			node *temp;
			temp = new node;
			cout << "Enter data to insert\n";
			cin >> temp->data;
			insert(root, temp);
			break;
		case 2:
			cout << "Pre order traversal\n";
			preorder();
			break;
		case 3:
			cout << "In order traversal\n";
			inorder();
			break;
		case 4:
			cout << "Post order traversal\n";
			postorder();
			break;
		case 5:
			exit(0);
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (ch != 5);
}
int main()
{
	TBT tbt;
	tbt.construction();
	return 0;
}
