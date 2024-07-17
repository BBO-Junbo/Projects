#include<iostream>
using namespace std;
class Dog
{
public:
	static int number;
	Dog()
	{
		number++;
		cout<<"New Dog"<<endl;
	}
	~Dog()
	{
		number--;
		cout<<"A Dog Die"<<endl;
	}
};
int Dog::number=0;
int main()
{
	Dog dog;
	Dog *pDog=new Dog();
	delete pDog;
	cout<<Dog::number<<endl;
	return 0;
}
