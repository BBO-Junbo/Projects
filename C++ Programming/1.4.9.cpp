#include<iostream>
using namespace std;

void f(const string&s,int n)
{
	cout<<s[n-1];
	if(n>1)
		f(s,n-1);
}
int main()
{
	f("animal",6);
	cout<<endl;
	f("hello",3);
	return 0;
 } 
