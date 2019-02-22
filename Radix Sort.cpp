//============================================================================
// Name        : Radix.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Radix Sort

#include <iostream>
#include <stdlib.h>

using namespace std;
void radix(int a[], int n)
{
	int buckets[10][10], count[10];
	int passes, large, div, bucketno, i, j, k;
	large = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > large)
			large = a[i];
	}
	passes = 0;
	while (large > 0)
	{
		passes++;
		large = large / 10;
	}
	div = 1;
	for (i = 1; i <= passes; i++)
	{
		for (j = 0; j <= 9; j++)
			count[j] = 0;
		for (j = 0; j < n; j++)
		{
			bucketno = (a[j] / div) % 10;
			buckets[bucketno][count[bucketno]] = a[j];
			count[bucketno]++;
		}
		j = 0;
		for (bucketno = 0; bucketno <= 9; bucketno++)
			for (k = 0; k < count[bucketno]; k++)
				a[j++] = buckets[bucketno][k];
		div = div * 10;
	}
}
int main()
{
	int a[30], n, i;
	cout << "Enter no. of elements\n";
	cin >> n;
	cout << "Enter data\n";
	for (i = 0; i < n; i++)
		cin >> a[i];
	radix(a, n);
	cout << "Sorted data\n";
	for (i = 0; i < n; i++)
		cout << " " << a[i];
}
