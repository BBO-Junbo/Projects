#include<iostream>
using namespace std;
int fun(int interval=1)
{
	int sum=0,i=0;
	for(i=0;i<100;i+=interval)
		sum+=i;
		return sum;
}
int main()
{
	cout<<"Result1:"<<fun(2)<<endl;
	cout<<"Result2:"<<fun()<<endl;
	return 0;
}
