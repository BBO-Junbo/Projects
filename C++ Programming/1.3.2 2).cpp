#include<iostream>

int getMax(int *array,int size)
{
	int maxx;
	if(*array>*(array+1))
	maxx=*array;
	else maxx=*(array+1);
	for(int i=3;i<size;i++)
	{
		if(*(array+i)>maxx)
		maxx=*(array+i)	;
	}	
	return maxx;
} 
int main()
{
	int a[9]={0,56,98,100,22,3,6,4,1};
	std::cout<<getMax(&a[0],9);
	return 0;
}
