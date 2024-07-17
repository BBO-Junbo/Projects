namespace xxx
{
	double fun(double a,double b)
	{
		return a+b;
	}
}	
namespace yyy
{
	double fun(double a,double b)
	{
		return (a+b)/2;
	}
}
#include<iostream>
using namespace std;
using namespace yyy;
int main()
{
	cout<<fun(1,4)<<endl;
	using xxx::fun;
	cout<<fun(1,4)<<endl;
	cout<<yyy::fun(1,4)<<endl;
	return 0;
}
