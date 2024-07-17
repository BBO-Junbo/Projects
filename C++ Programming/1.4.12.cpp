#include<iostream>
using namespace std;
double func(double pData[],int size);
int main()
{
	double array[]={2.2,3.8,6,5.4};
	cout<<"Result:"<<func(array,4)<<endl;
	cout<<"Result:"<<func(array,3)<<endl;
}
double func(double pData[],int size)
{
	double result=0;
	int i;
	for(i=0;i<size;++i)
	{
		result+=pData[i];
	}
	result/=size;
	return result;
}
