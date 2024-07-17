#include<iostream>
using namespace std;
class TestClass
{
public:
		TestClass()
		{
			cout<<"Constructed!\n";
			value=10;
		}
		~TestClass()
		{
			cout<<"Destructed!\n";
		}
		void setValue(int newValue)
		{
			value=newValue;	
		}
		int getValue()
		{
			return value;
		}
private:
	int value;
} ;
int main()
{
	TestClass t1;
	cout<<t1.getValue()<<endl;
	TestClass &rt1=t1;
	rt1.setValue(20);
	cout<<t1.getValue()<<endl;
	TestClass *pt=&t1;
	pt->setValue(30);
	cout<<t1.getValue()<<endl;
	return 0;
	
}








