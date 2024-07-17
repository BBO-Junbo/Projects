#include<iostream>
using namespace std;
class Test
{
public:
	Test(){cout<<"Default Constructor\n";}
	Test(int xx):x(xx){cout<<"Int Constructor\n";}
	Test(const Test&t):x(t.x){cout<<"Copy Constructor\n";}
private:
	int x;
};
Test t;
int main()
{
	cout<<"---------------------\n";
	Test tt(t);
	return 0;
}
