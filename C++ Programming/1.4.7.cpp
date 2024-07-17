#include<iostream>
using namespace std;

void xhg(int &a,int &b)
{
	int temp;
	temp=b;
	b=a;
	a=temp;
	cout<<a<<' '<<b<<endl;
}
int main()
{
	int x(5),y(4);
	xhg(x,y);
	cout<<x<<' '<<y<<endl;
	return 0;
}
