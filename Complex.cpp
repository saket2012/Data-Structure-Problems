// Complex Numbers

#include <iostream>
#include <cstdlib>
using namespace std;

class complex
{
	float real, img;

   public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(float x, float y)
	{
		real = x;
		img = y;
	}
	complex operator+(complex b);
	complex operator-(complex b);
	complex operator*(complex b);
	complex operator/(complex b);
	void input();
	void output();
};

complex complex::operator+(complex b)
{
	complex c;
	c.real = real + b.real;
	c.img = img + b.img;
	return c;
}

complex complex::operator-(complex b)
{
	complex c;
	c.real = real - b.real;
	c.img = img - b.img;
	return c;
}

complex complex::operator*(complex b)
{
	complex c;
	c.real = ((real * b.real) - (img * b.img));
	c.img = ((real * b.img) + (b.real * img));
	return c;
}
complex complex::operator/(complex b)
{
	complex c;
	c.real = ((real * b.real) + (img * b.img)) / ((b.real * b.real) + (b.img * b.img));
	c.img = ((b.real * img) - (real * b.img)) / ((b.real * b.real) + (b.img * b.img));
	return c;
}
void complex::output()
{
	cout << real << " + " << img << "i\n";
}
int main()
{
	int ch;
	complex c1, c2, c3;
	float x, y, z, w;
	cout << "Enter the real and imaginary part of first no.\n";
	cin >> x >> y;
	cout << "Enter the real and imaginary part of second no.\n";
	cin >> z >> w;
	c1 = complex(x, y);
	c2 = complex(z, w);
	do
	{
		cout << "\nMenu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit";
		cout << "\nEnter your choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n Addition is ";
			c3 = c1 + c2;
			c3.output();
			break;
		case 2:
			cout << "\n Subtraction is ";
			c3 = c1 - c2;
			c3.output();
			break;
		case 3:

			cout << "\n Multiplication is ";
			c3 = c1 * c2;
			c3.output();
			break;
		case 4:
			cout << "\n Division is ";
			c3 = c1 / c2;
			c3.output();
			break;
		case 5:
			exit(0);
			break;
		}
	} while (ch != 5);
	return 0;
}
