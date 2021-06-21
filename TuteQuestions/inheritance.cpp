#include<iostream>
#include<string>

using namespace std;

/* this is used to identify the inheritence concept of cpp */

class Animal
{
	public:
		int legs = 4;
		string name = " Mammel ";
};

class Dog: public Animal
{
	public:
		string mode = " Altation ";
};

int main()
{
	Dog Dog1;
	cout << Dog1.legs << " " << Dog1.name << " " <<Dog1.mode;
	
	return 0;
}
