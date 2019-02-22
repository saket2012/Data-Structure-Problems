//============================================================================
// Name        : Vegetable.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

class market
{
   private:
	struct node
	{
		int freq;
		string name;
		float price;
		node *next;
		node *prev;
	} * head;

   public:
	market()
	{
		head = NULL;
	}
	void create();
	void display();
	void sort();
};
void market::create()
{
	node *temp, *trav;
	temp = new node;
	temp->next = NULL;
	temp->prev = NULL;
	cout << "\n Enter name of the product" << endl;
	cin >> temp->name;
	cout << "\n Enter the price of the product" << endl;
	cin >> temp->price;
	cout << "\n Enter the frequency of the product" << endl;
	cin >> temp->freq;
	if (head == NULL)
	{
		head = temp;
	}
	else if (head->next == NULL)
	{
		head->next = temp;
		temp->prev = head;
	}
	else
	{
		trav = head;
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = temp;
		temp->prev = trav;
	}
}
void market::display()
{
	//trav=head;
	if (head == NULL)
	{
		cout << "\n The list is empty nothing to display" << endl;
	}
	else
	{
		node *trav;
		trav = head;
		while (trav != NULL)
		{
			cout << trav->name << "\t";
			cout << trav->price << "\t";
			cout << trav->freq << endl;
			trav = trav->next;
		}
	}
}

void market::sort()
{
	node *trav1;
	node *trav2;
	for (trav1 = head; trav1 != NULL; trav1 = trav1->next)
	{
		for (trav2 = trav1->next; trav2 != NULL; trav2 = trav2->next)
		{
			if (trav1->freq > trav2->freq)
			{
				node *temp;
				temp = new node;

				temp->price = trav1->price;
				trav1->price = trav2->price;
				trav2->price = temp->price;
				temp->name = trav1->name;
				trav1->name = trav2->name;
				trav2->name = temp->name;
				temp->freq = trav1->freq;
				trav1->freq = trav2->freq;
				trav2->freq = temp->freq;
			}
		}
	}
}
int main()
{
	market m, m1;
	int i, n, ch;
	cout << endl
		<< "Enter no of vegetables and fruits ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		m.create();
	}
	do
	{
		cout << "\n Menu \n 1.Sort \n 2.Display \n 3.Create and sort New List \n 4.Exit" << endl;
		cout << "\n Enter your choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			m.sort();
			break;
		case 2:
			m.display();
			break;
		case 3:
			for (int i = 0; i <= n; i++)
			{
				m1.create();
			}
			m1.sort();
			m1.display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "\n Invalid choice" << endl;
			break;
		}
	} while (ch != 4);
	return 0;
}
