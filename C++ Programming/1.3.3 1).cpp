#include<iostream>
using namespace std;
int *getDiagonal(int **matrix,int n)
{
	int *a=new int[n];
	int *p=a;
	for(int i=0;i<n;)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				if(j==k)
				{
					*a=matrix[j][k];
					a++;
					i++;
				}
			}
		}
	}


	return p;
}
int main()
{
	int **data,n=5;
	data=new int*[n];
	for(int i=0;i<n;++i)
		data[i]=new int[n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			data[i][j]=i+j;
	}
	int *diagonal=getDiagonal(data,n);
	for(int i=0;i<n;++i)
		cout<<diagonal[i]<<endl;
	delete[] diagonal;
	for(int i=0;i<=n;++i)
		delete[] data[i];
	delete[]data;
	return 0; 
} 
