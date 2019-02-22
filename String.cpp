
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strng
{
   private:
     char str[10];

   public:
     char str1[20];
     void accept();
     void palindrome(strng &s2);
     void substring(strng &s2);
     void operator<<(strng s2);
     void operator>>(strng &str);
     void operator+(strng &s1);
     void operator=(strng &s2);
     void operator==(strng &s3);
};

void strng::accept()
{
     cout << "Enter string\n";
     cin >> str1;
}

void strng::operator<<(strng s2)
{
     cout << "String1\n"
          << str1 << endl;
     cout << "String2\n"
          << s2.str1 << endl;
}

void strng::operator>>(strng &str)
{
     int i = 0, j = 0;
     char t1, t2;
     while (str1[i] != NULL)
          i++;
     i--;
     while (i >= j)
     {
          t1 = str1[i];
          str1[i] = str1[j];
          str1[j] = t1;
          i--;
          j++;
     }
     i = 0;
     j = 0;
     while (str.str1[i] != NULL)
          i++;
     i--;
     while (i >= j)
     {
          t2 = str.str1[i];
          str.str1[i] = str.str1[j];
          str.str1[j] = t2;
          i--;
          j++;
     }
}

void strng::operator+(strng &s2)
{
     int i = 0, j = 0;
     while (str1[i] != NULL)
          i++;
     while (s2.str1[j] != NULL)
     {
          str1[i] = s2.str1[j];
          i++;
          j++;
     }
     str1[i] = '\0';
}

void strng::operator=(strng &s2)
{
     int i = 0;
     bool flag = false;
     while (str1[i] != NULL && s2.str1[i] != NULL)
     {
          if (str1[i] != s2.str1[i])
          {
               flag = true;
               cout << "Strings are not equal\n";
               break;
          }
          i++;
     }
     if (flag == false)
          cout << "Strings are equal\n";
}

void strng::operator==(strng &s2)
{
     int i = 0;
     while (str1[i] != NULL)
     {
          s2.str1[i] = str1[i];
          i++;
     }
     s2.str1[i] = '\0';
}

void strng::palindrome(strng &s2)
{
     int i = 0, j = 0;
     bool flag = false;
     while (s2.str1[j] != NULL)
          j++;
     j--;
     while (j >= i)
     {
          if (str1[i] != s2.str1[j])
          {
               flag = true;
               cout << "Strings are not palindrome\n";
               break;
          }
          i++;
          j--;
     }
     if (flag != true)
          cout << "Strings are palindrome\n";
}

void strng::substring(strng &s2)
{
     int i = 0, j = 0, l1, l2;
     while (str1[i] != '\0')
          i++;
     l1 = i;
     while (s2.str1[j] != '\0')
          j++;
     l2 = j;
     i = 0;
     j = 0;
     while (l1 != 0)
     {
          if (str1[i] == s2.str1[j])
          {
               i++;
               j++;
               l2--;
               if (l2 == 0)
               {
                    cout << "\nString is Substring\n";
                    break;
               }
               l1--;
          }
          else
          {
               j = 0;
               i++;
               l1--;
          }
     }
     if (l1 == 0)
          cout << "\nString is not Substring\n";
}

int main()
{
     int ch;
     strng s1, s2;
     s1.accept();
     s2.accept();
     do
     {
          cout << "------------------------------------\n";
          cout << "Menu\n1.Display\n2.Reverse string\n3.Concatinate\n";
          cout << "4.Check equality\n5.Copy\n6.Palindrome\n7.Substring\n8.Exit\n";
          cout << "------------------------------------\n";
          cout << "Enter your choice\n";
          cin >> ch;
          switch (ch)
          {
          case 1:
               s1.operator<<(s2);
               break;
          case 2:
               cout << "Reversed strings are\n";
               s1.operator>>(s2);
               s1.operator<<(s2);
               break;
          case 3:
               s1.operator+(s2);
               cout << "String 2 is concatinated to string 1\n";
               cout << "String 1 is\n"
                    << s1.str1 << endl;
               break;
          case 4:
               s1.operator=(s2);
               break;
          case 5:
               s1.operator==(s2);
               cout << "String 1 is copied in string 2\n";
               cout << "String 2 is\n"
                    << s2.str1 << endl;
               break;
          case 6:
               s1.palindrome(s2);
               break;
          case 7:
               s1.substring(s2);
               break;
          case 8:
               exit(0);
          }
     } while (ch != 8);
     return 0;
}