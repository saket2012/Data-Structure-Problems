#include <iostream>
#include <stdlib.h>
using namespace std;
template <class x>
void accept(x *a, int m, int n)
{
     int i, j;

     for (i = 0; i < m; i++)
     {
          for (j = 0; j < n; j++)
          {
               cin >> a[i][j];
          }
     }
}
template <class x>
void display(x *a, int m, int n)
{
     int i, j;
     for (i = 0; i < m; i++)
     {
          for (j = 0; j < n; j++)
          {
               cout << a[i][j] << "\t";
          }
          cout << endl;
     }
}

template <class x>
void addition(x *a, x *b, int m, int n, int o, int p)
{
     int i, j;
     if (m == o && n == p)
     {
          cout << "\nAddition of matrices is :\n";
          for (i = 0; i < m; i++)
          {
               for (j = 0; j < n; j++)
               {
                    cout << a[i][j] + b[i][j] << "\t";
               }
               cout << endl;
          }
     }
     else
          cout << "Addition not possible, please enter same rows and column matrices";
}

template <class x>
void sub(x *a, x *b, int m, int n, int o, int p)
{
     int i, j;
     if (m == o && n == p)
     {
          cout << "\nSubstraction of matrices is :\n";
          for (i = 0; i < m; i++)
          {
               for (j = 0; j < n; j++)
               {
                    cout << a[i][j] - b[i][j] << "\t";
               }
               cout << endl;
          }
     }
     else
          cout << "\nSubstraction not possible, please enter same rows and column matrices\n";
}

template <class x>
void mul(x *a, x *b, int m, int n, int p)
{
     int i, j, k;
     double h[10][10];

     for (i = 0; i < m; i++)
     {
          for (j = 0; j < n; j++)
          {
               h[i][j] = 0;
          }
     }
     if (m == p)
     {
          for (i = 0; i < m; i++)
          {
               for (j = 0; j < n; j++)
               {
                    for (k = 0; k < m; k++)
                    {
                         h[i][j] = h[i][j] + (a[i][k] * b[k][j]);
                    }
               }
          }
          for (i = 0; i < n; i++)
          {
               for (j = 0; j < n; j++)
               {
                    cout << h[i][j] << "\t";
               }
               cout << endl;
          }
     }
}

int main()
{
     int a[10][10], b[10][10];
     float x[10][10], y[10][10];
     int m, n, o, p, ch, ch1;
     do
     {
          cout << "\nMENU\n1.Integer\n2.Float\n3.Exit\nEnter data-type you want for matrices";
          cin >> ch;
          switch (ch)
          {
          case 1:
               cout << "\nEnter the no. rows and columns for matrices\n";
               cin >> m >> n;
               cout << "\nEnter the 1st matrix for integer\n";
               accept(a, m, n);
               cout << "\nEnter the no. rows and columns for matrices\n";
               cin >> o >> p;
               cout << "\nEnter the 2nd matrix for integer\n";
               accept(b, o, p);
               do
               {
                    cout << "\nSubmenu\n1.Display\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Exit\n";
                    cin >> ch1;

                    switch (ch1)
                    {
                    case 1:
                         cout << "\n1st matrix is\n";
                         display(a, m, n);
                         cout << "\n2nd matrix is\n";
                         display(b, o, p);
                         break;
                    case 2:
                         addition(a, b, m, n, o, p);
                         break;
                    case 3:
                         sub(a, b, m, n, o, p);
                         break;
                    case 4:
                         mul(a, b, m, n, p);
                         break;
                    case 5:

                         break;
                    }
               } while (ch1 != 5);
               break;

          case 2:
               cout << "\nEnter the no. rows and columns for matrices\n";
               cin >> m >> n;
               cout << "\nEnter the 1st matrix for float\n";
               accept(x, m, n);
               cout << "\nEnter the no. rows and columns for matrices\n";
               cin >> o >> p;
               cout << "\nEnter the 2nd matrix for float\n";
               accept(y, o, p);
               do
               {
                    cout << "\nSubmenu\n1.Display\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Exit\n";
                    cin >> ch1;

                    switch (ch1)
                    {
                    case 1:
                         cout << "\n1st matrix is\n";
                         display(x, m, n);
                         cout << "\n2nd matrix is\n";
                         display(y, o, p);
                         break;
                    case 2:
                         addition(x, y, m, n, o, p);
                         break;
                    case 3:
                         sub(x, y, m, n, o, p);
                         break;
                    case 4:
                         mul(x, y, m, n, p);
                         break;
                    case 5:

                         break;
                    }
               } while (ch1 != 5);
               break;
          case 3:
               exit(0);
               break;
          }
     } while (ch != 3);

     return 0;
}
