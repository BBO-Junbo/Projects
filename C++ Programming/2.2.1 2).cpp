#include<iostream>
using namespace std;
class TestClass
{
	public:
		TestClass()
		{
			cout<<"Constructed!\n";
		}
		~TestClass()
		{
			cout<<"Destructed!\n";
		}
};
int main()
{
	TestClass t1;
	TestClass *p;
	p=new TestClass;
	
	delete p;
	return 0;
}
