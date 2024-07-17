#include<iostream>
using namespace std;
class Test
{
public:
	Test()
	{
		cout<<"Default constructor."<<endl;
	}
	Test(const Test&t)
	{
		cout<<"Copy constructor."<<endl;
	}
};
void fun(Test p)
{
}
int main()
{
	Test a;
	fun(a);
	return 0;
}
