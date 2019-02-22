
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

class student
{
   protected:
     char sname[20], subject[20];
     int roll;
};

class parent1 : public virtual student
{
   public:
     int edit(bool, int, int);
};
int parent1::edit(bool flag, int a, int n)
{
     char stud1[30], sub[30];
     int r1;
     for (int i = 0; i < n; i++)
     {
          if (a == roll)
          {
               flag = true;
               cout << "\n record found";
               cout << "\n enter the details of the student you want to edit ";
               cout << "\n enter the name";
               cin >> stud1;
               cout << "\nenter subject";
               cin >> sub;
               cout << "\nenter roll no";
               cin >> r1;
               strcpy(sname, stud1);
               strcpy(subject, sub);
               roll = r1;
          }
     }
     return flag;
}

class parent2 : public virtual student
{
   public:
     int search(bool &, int, int);
};
int parent2::search(bool &flag, int a, int n)
{
     for (int i = 0; i < n; i++)
     {
          if (a == roll)
          {
               flag = true;
          }
     }
     return flag;
}

class child : public virtual parent1, public virtual parent2
{
   public:
     int mks;
     char assesm[10], subcode[30];
     void input1(int);
     void display();
     void delet(int, int, child *c);
};

void child::delet(int a, int n, child c[20])
{
     int r;
     r = a;
     for (int s = 0; s < n; s++)
     {
          if (r == c[s].roll)
          {
               for (int m = s; m < n; m++)
               {
                    c[m] = c[m + 1];
               }
          }
     }
}

void child::input1(int a)
{

     roll = a;
     cout << "\n enter the name of student";
     cin >> sname;
     cout << "\n enter the subject";
     cin >> subject;
     cout << "\nnenter the mks";
     cin >> mks;
     cout << "\n enter the subject code";
     cin >> subcode;
     cout << "\n enter the assesment";
     cin >> assesm;
}

void child::display()
{

     cout << "\t" << roll << "\t" << sname << "\t" << subject << "\t" << subcode << "\t\t" << assesm;
}

int main()
{
     int n, a, ch, i, count = 0;
     char stud[20];
     bool flag = false;
     cout << "\nenter the number of records";
     cin >> n;
     child c1[10], c;
     for (i = 0; i < n; i++)
     {
          cout << "\n enter rollno";
          cin >> a;
          c1[i].input1(a);
          count++;
     }
     do
     {
          cout << "\nMenu\n1.display\n2.delete\n3.insert\n4.search\n5.edit\n6.exit";
          cout << "\nenter choice";
          cin >> ch;
          switch (ch)
          {
          case 1:
               cout << "\n\tROLL\tNAME\tSUBJECT\tSUBJECT CODE\tASSESMENT";
               for (i = 0; i < n; i++)
               {
                    cout << "\n"
                         << i + 1;
                    c1[i].display();
               }
               break;
          case 2:
               n--;
               count = n;
               cout << "\n enter rollno";
               cin >> a;
               c1[a - 1].delet(a, n, c1);
               for (int t = 0; t < count; t++)
               {
                    cout << "\n"
                         << t + 1;
                    c1[t].display();
               }

               break;
          case 3:
               n++;
               count = n;
               cout << "\nenter the roll number";
               cin >> a;
               c1[a - 1].input1(a);
               cout << "\n\tROLL\tNAME\tSUBJECT\tSUBJECT CODE\tASSESMENT";
               for (int i = 0; i < count; i++)
               {
                    cout << "\n"
                         << i + 1;
                    c1[i].display();
               }
               break;
          case 4:
               cout << "\n enter the roll of student u want to search";
               cin >> a;
               for (int i = 0; i < n; i++)
               {
                    c1[i].search(flag, a, n);
               }
               if (flag == true)
               {
                    cout << "\n record found";
               }
               if (flag != true)
               {
                    cout << "\nrecord not found";
               }
               break;
          case 5:
               flag = false;

               cout << "\n Enter the roll of student u want to search";
               cin >> a;
               for (int i = 0; i < n; i++)
               {
                    c1[i].edit(flag, a, n);
               }
               if (flag == true)
                    cout << "\n details successfully edited";
               if (flag != true)
               {
                    cout << "\nrecord not found";
               }

               cout << "\n\tROLL\tNAME\tSUBJECT\tSUBJECT CODE\tASSESMENT";
               for (int i = 0; i < n; i++)
               {
                    cout << "\n"
                         << i + 1;
                    c1[i].display();
               }
               break;
          case 6:
               exit(0);
               break;
          }
          flag = false;
          n = count;
     } while (ch != 6);
     return 0;
}
