#include<iostream>
using namespace std;
class TestClass
{
public:
	TestClass(int newValue=0)
	{
		value=newValue;
		cout<<"Value:"<<value<<",Constructed!\n";
	}
	TestClass(const TestClass &rhs)
	{
		value=rhs.value;
		cout<<"Value:"<<value<<",Copy Constructed!\n";
	}
	~TestClass()
	{
		cout<<"Value:"<<value<<",Destructed!\n";
	}
	void setValue(int newValue)
	{
		value=newValue;
    } 
private:
	int value;
};
TestClass &foofun(TestClass &t)
{
	t.setValue(20);
	return t;
}
int main()
{
	TestClass t1(10),t2(t1),t3;
	t3=foofun(t1);
	return 0;
}
