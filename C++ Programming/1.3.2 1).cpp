#include<iostream>
using namespace std;
void reverse(int array[],int size)
{
	int *p,*q;
	p=array;
	q=array+5;
	int c;
	for(int i=0;i<3;i++)
	{
		c=*p;
		*p=*q;
		*q=c;
		p+=1;
		q-=1;
		
	}
}
int main()
{
	int a[6]={1,2,3,4,5,6};
	reverse(&a[0],6);
	for(int i=0;i<6;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}


