#include<iostream>
using namespace std;
int func(int data[],int size)
{
	int a=data[0];
	int b=data[0];
	for(int i=1;i<size;++i)
	{
		if(data[i]>a) a=data[i];
		if(data[i]<b) b=data[i];
	}
	return a-b;
}
int main()
{
	int a[]{9,3,2,-1,8,0,4};
	cout<<func(a,7)<<endl;
	cout<<func(a+2,4)<<endl;
	return 0;
}
