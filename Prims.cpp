//============================================================================
// Name        : Prims.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Prims Algorithm

#include <iostream>
#include <cstdlib>
using namespace std;
class prim
{
   private:
	int a[10][10], min, max, visited[20], n;

   public:
	void create();
	void display();
	void minimum();
	void maximum();
	void visit();

	prim()
	{
		min = 999;
		max = 0;
		n = 0;
	}
};

void prim::create()
{

	cout << "Enter the no of houses\n";
	cin >> n;
	cout << "Enter adjacency matrix\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
}

void prim::display()
{
	cout << "\n matrix is\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}

void prim::minimum()
{
	int k, l;
	min = 99999;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min && a[i][j] != 0)
			{
				min = a[i][j];
				k = i;
				l = j;
			}
		}
	}
	cout << "\nMinimum distance from " << k << " to " << l << " is : " << min << endl;
}

void prim::maximum()
{
	int k, l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max && a[i][j] != 0)
			{
				max = a[i][j];
				k = i;
				l = j;
			}
		}
	}
	cout << "Maximum distance from " << k << " to " << l << " is :" << max << endl;
}

void prim::visit()
{
	int i, j, k, l, x;
	int cost = 0;
	min = 99999;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] < min && a[i][j] != 0)
			{
				min = a[i][j];
				k = i;
				l = j;
			}
		}
	}
	visited[k] = 1;
	visited[l] = 1;
	cost = min;

	for (x = 0; x < n - 2; x++)
	{
		min = 9999;

		for (i = 0; i < n; i++)
		{
			if (visited[i] == 1)
			{
				for (j = 0; j < n; j++)
				{
					if (visited[j] != 1)
					{
						if (a[i][j] < min && a[i][j] != 0)
						{
							min = a[i][j];
							k = i;
							l = j;
						}
					}
				}
			}
			visited[k] = 1;
			visited[l] = 1;
			cost = cost + min;
		}
		cout << "Total distance is : " << cost << endl;
	}
}

int main()
{
	int ch;
	prim p;
	p.create();
	do
	{
		cout << "------------------------\n";
		cout << "Menu\n1.Minimum distance\n2.Maximum distance\n3.Display matrix\n4.Total distance\n5.Exit\n";
		cout << "------------------------\n";
		cout << "Enter your choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			p.minimum();
			break;
		case 2:
			p.maximum();
			break;
		case 3:
			p.display();
			break;
		case 4:
			p.visit();
			break;
		case 5:
			exit(0);
		}
	} while (ch != 5);
	return 0;
}
