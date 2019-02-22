

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class t>
class vector
{
     t v[100];
     int size;

   public:
     void create(int);
     void display(int);
     void modify();
     void mul(int);
     vector()
     {
          size = 0;
          for (int i = 1; i < 100; i++)
          {
               v[i] = 0;
          }
     }
};
template <class t>
void vector<t>::create(int n)
{
     t value;
     int index;
     char a;
     do
     {
          if (size < n)
          {
               cout << "\n enter the index and value";
               cin >> index >> value;
               v[index] = value;
               size++;
               cout << "\n do u want to add? ";
               cin >> a;
          }
     } while (a == 'y' || a == 'Y');
}

template <class t>
void vector<t>::display(int n)
{
     cout << "\nelements entered " << size;
     cout << "\nthe vector is";
     for (int i = 1; i <= n; i++)
     {
          cout << v[i] << " ";
     }
}

template <class t>
void vector<t>::modify()
{
     int index1;
     t newval;
     cout << "\nenter new index and new value";
     cin >> index1 >> newval;
     v[index1] = newval;
}

template <class t>
void vector<t>::mul(int n)
{
     int scalar;
     cout << "\nenter the scalar value to multiply";
     cin >> scalar;
     for (int i = 1; i <= n; i++)
     {
          v[i] = v[i] * scalar;
     }
}
int main()
{
     int n, ch;
     cout << "\n enter the size of vector";
     cin >> n;
     vector<int> v;
     v.create(n);
     do
     {
          cout << "\nMENU\n1.DISPLAY\n2.MODIFY\n3.MULTIPLY BY SCALAR\n4.EXIT";
          cout << "\n enter your choice";
          cin >> ch;
          switch (ch)
          {
          case 1:
               v.display(n);
               break;
          case 2:
               v.modify();
               v.display(n);
               break;
          case 3:
               v.mul(n);
               v.display(n);
               break;
          case 4:
               exit(0);
               break;
          }
     } while (ch != 4);

     return 0;
}
