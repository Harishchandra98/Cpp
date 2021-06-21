#include<iostream>

using namespace std;

class Complex
{
	float real,img;
	public:
		Complex operator+(Complex);
		Complex()
		{
			
		}
		Complex(float r, float i)
		{
			real = r;
			img = i;
		}
		void Display()
		{
			cout << " Real " << real << endl
				 << " Image " << img << endl;
		}
};

Complex Complex:: operator+(Complex a)
{
	Complex z;
	z.real = real + a.real;
	z.img = img + a.img;
	return z;
}

int main()
{
	Complex op1(13.2,15.2), op2(20.6,14.7), tot_op;
	tot_op = op1 + op2;
	tot_op.Display();
	
	return 0;
}
