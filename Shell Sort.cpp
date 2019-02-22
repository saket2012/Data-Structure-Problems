//============================================================================
// Name        : Shell.cpp
// Author      : Saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// Shell Sort

#include <iostream>
#define MAX 10
using namespace std;

class shellsort
{
    int arr[MAX], n;

  public:
    void getdata();
    void showdata();
    void sortLogic();
};

void shellsort ::getdata()
{
    cout << "Enter the size of shell array:\n ";
    cin >> n;
    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void shellsort ::showdata()
{
    cout << "\nShell sorted array is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}

void shellsort ::sortLogic()
{
    int i, j, temp, increment;

    for (increment = n / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (temp < arr[j - increment])
                    arr[j] = arr[j - increment];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    shellsort obj;
    obj.getdata();
    obj.sortLogic();
    obj.showdata();
    return 0;
}
