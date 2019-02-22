//============================================================================
// Name        : Queue.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Aueue operations

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class queue
{
   private:
	int front, rear, size, q[100], value;

   public:
	queue(int r, int f, int size1)
	{
		value = 0;
		rear = -1;
		front = -1;
		size = size1;
	}
	void enq();
	void deq();
	void display();
	int IsEmpty();
	int IsFull();
};

void queue::enq()
{
	front = 0;
	if (IsFull() != 0)
	{
		cout << "\n Enter element of queue" << endl;
		cin >> value;
		rear++;
		q[rear] = value;
		cout << "\n Enqueued element is " << q[rear] << endl;
	}
}

void queue::deq()
{
	if (IsEmpty() != 0)
	{
		value = q[front];
		cout << "\n Dequeued element is " << value << endl;
	}
	else if (front == rear)
	{
		value = q[front];
		front = rear = -1;
	}
	else
	{
		cout << "\n Dequeued element is " << value << endl;
		front++;
	}
}

void queue::display()
{
	int i;
	if (front == -1 && rear == -1)
	{
		cout << "\n Queue is empty" << endl;
	}
	else
	{
		cout << "\n Queue is" << endl;
		for (i = front; i <= rear; i++)
		{
			cout << "\n " << q[i] << endl;
		}
	}
}

int queue::IsEmpty()
{
	if (front == -1 && rear == -1)
	{
		cout << "\n Queue is empty" << endl;
		return 0;
	}
	else
		return 1;
}

int queue::IsFull()
{
	front = 0;
	if (rear == size - 1)
	{
		cout << "\n Queue is full" << endl;
		return 0;
	}
	else
		return 1;
}

int main()
{
	int size1, ch;
	cout << "\n Enter size of queue" << endl;
	cin >> size1;
	queue q1(-1, -1, size1);
	do
	{
		cout << "\n ------------" << endl;
		cout << "\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit" << endl;
		cout << "\n ------------" << endl;
		cout << "\n Enter your choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			q1.enq();
			break;
		case 2:
			q1.deq();
			break;
		case 3:
			q1.display();
			break;
		case 4:
			exit(0);
		default:
			cout << "\n Invalid choice" << endl;
			break;
		}
	} while (ch != 4);
	return 0;
}
