#include<iostream>
using namespace std;
class TestClass
{
	public:
		TestClass(int a)
		{
			aa=a;
			cout<<aa<<"Constructed!\n";
		}
		~TestClass()
		{
			cout<<aa<<"Destructed!\n";
		}
	private:
		int aa;
}
TestClassAA(3);
int main()
{
	cout<<"In MainFunction."<<endl;
	TestClass BB(5);
	return 0;
}


