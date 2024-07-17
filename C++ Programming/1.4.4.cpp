#include<iostream>
using namespace std;

char&elem(char *s,int n)
{
	return s[n];
}
int main()
{
	char str[]="HelloWorld";
	elem(str,1)='A';
	cout<<str<<endl;
	return 0;
}
