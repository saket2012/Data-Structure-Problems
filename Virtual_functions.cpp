

#include <iostream>
using namespace std;

class base
{
   public:
     struct node
     {
          char sname[20], subject[20];
          int roll;
          int mks;
          char assesm[10], subcode[30];
          node *next;
          node *prev;
     } * head;
     base()
     {
          head = NULL;
     }
     virtual void create()
     {
     }
     virtual void insert()
     {
     }
     virtual void delet()
     {
     }
     virtual void search()
     {
     }
     virtual void display()
     {
     }
};
class child : public base
{
   public:
     void create();
     void insert();
     void delet();
     void search();
     void display();
};
void child::create()
{
     node *temp;
     temp = new node;
     cout << "\n enter the details of the student\n";
     cout << "\nenter the rollno";
     cin >> temp->roll;
     cout << "\n enter the name of student";
     cin >> temp->sname;
     cout << "\n enter the subject";
     cin >> temp->subject;
     cout << "\nnenter the mks";
     cin >> temp->mks;
     cout << "\n enter the subject code";
     cin >> temp->subcode;
     cout << "\n enter the assesment";
     cin >> temp->assesm;

     if (head == NULL)
     {
          temp->next = temp;
          temp->prev = temp;
          head = temp;
     }
     else if (head->next == head)
     {
          head->next = temp;
          temp->prev = head;
          temp->next = head;
          head->prev = temp;
     }
     else
     {
          node *trav;
          trav = head;
          trav = head->prev;
          trav->next = temp;
          temp->prev = trav;
          temp->next = head;
          head->prev = temp;
     }
}

void child::insert()
{
     int loc = 0, i;
     node *temp, *trav;
     temp = new node;
     cout << "\n enter the details of the student\n";
     cout << "\nenter the rollno";
     cin >> temp->roll;
     cout << "\n enter the name of student";
     cin >> temp->sname;
     cout << "\n enter the subject";
     cin >> temp->subject;
     cout << "\nnenter the mks";
     cin >> temp->mks;
     cout << "\n enter the subject code";
     cin >> temp->subcode;
     cout << "\n enter the assesment";
     cin >> temp->assesm;

     cout << "\n enter the location\n";
     cin >> loc;
     trav = head;
     for (i = 1; i < loc; i++)
     {
          trav = trav->next;
     }
     temp->next = trav->next;
     temp->next->prev = temp;
     trav->next = temp;
     temp->prev = trav;
}

void child::delet()
{
     int i, loc;
     node *temp, *trav, *temp1;
     temp = temp1 = trav = head;
     if (head == NULL)
     {
          cout << "\n list is empty cannot delete\n";
     }
     else if (head->next == head)
     {
          delete temp;
          head = NULL;
     }
     else
     {
          cout << "\nenter the location\n";
          cin >> loc;
          for (i = 1; i < loc; i++)
          {
               temp = temp->next;
               trav = trav->next;
               temp1 = temp1->next;
          }
          trav = trav->prev;
          temp1 = temp1->next;
          trav->next = temp1;
          temp1->prev = trav;
          delete temp;
          cout << "\n element deleted\n";
     }
}

void child::display()
{
     node *trav;
     trav = head;
     cout << "\n\tROLL\tNAME\tSUBJECT\tMARKS\tSUBJECT CODE\tASSESMENT";
     do
     {
          cout << "\n\t" << trav->roll << "\t" << trav->sname << "\t" << trav->subject << "\t" << trav->mks << "\t" << trav->subcode << "\t\t" << trav->assesm;
          //cout<<"\n";
          trav = trav->next;
     } while (trav != head);
}

void child::search()
{
     int loc = 1, value;
     bool flag = false;
     node *temp;
     cout << "\nenter the rollno to be searched\n";
     cin >> value;
     temp = head;
     while (temp->next != head)
     {
          if (temp->roll == value)
          {
               cout << "\nelement found at location " << loc;
               flag = true;
          }
          loc++;
          temp = temp->next;
     }
     if (flag != true)
     {
          cout << "\n element not found\n";
     }
}
int main()
{
     child c;
     base &b = c;
     int n, i;
     cout << "\n enter the no of records\n";
     cin >> n;
     for (i = 0; i < n; i++)
     {
          b.create();
     }
     b.display();
     b.insert();
     b.display();
     b.search();
     b.delet();
     b.display();
     return 0;
}
