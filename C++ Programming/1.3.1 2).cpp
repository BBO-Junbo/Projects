#include<iostream>
#include<string>
using namespace std;
string add(const string& s1,const string s2)
{
	return s1+s2;
}
double add(double a,double b)
{
	return a+b;
}
int main()
{
	cout<<add("hello","world")<<endl;
	cout<<add(3,5)<<endl;
	cout<<add('3','5')<<endl;
	return 0;
}
