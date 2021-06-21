#include<iostream>
using namespace std;

class Box
{
	public:
		int length;
		int width;
		int height;
		double getVolume(void);
};

double Box::getVolume(void)
{
	return (this->length * this->width * this->height);
}

int main()
{
	Box B1;
	B1.length = 5;
	B1.width = 4;
	B1.height = 2;
	cout << B1.getVolume();
	
	return 0;
}
