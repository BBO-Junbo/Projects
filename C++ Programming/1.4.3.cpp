#include<iostream>
using namespace std;

int sum(int a,int b=1,int c=3)
{
	return a+b+c;
}
int main()
{
	int sum(int a,int b=3,int c=4);
	cout<<sum(2)<<endl;
	cout<<sum(2,5)<<endl;
	cout<<sum(2,3,6)<<endl;
	return 0;
}
