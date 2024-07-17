#include<iostream>
using namespace std;
class Example
{
private:
	int i;
public:
	Example(int n)
	{
		i=n;
		cout<<"Constructing."<<endl;
	}
	~Example()
	{
		cout<<"Destructing."<<endl;	
	}
	int get_i()
	{
		return i;
	}
};
int sqrt_it(Example o)
{
	return o.get_i()*o.get_i();
}
int main()
{
	Example x(10);
	cout<<x.get_i()<<endl;
	cout<<sqrt_it(x)<<endl;
	return 0;
}




