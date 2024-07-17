#include<iostream>
using namespace std;
class Test
{
private:
	int a,b;
public:
	Test():Test(1){cout<<"constructor whitout parameter!\n";}
	Test(int x):Test(x,10){cout<<"constructor whit 1 parameter!\n";}
	Test(int x,int y):a(x),b(y){cout<<"constructor whit 2 parameter!\n";}
	void output()const{cout<<a<<","<<b<<endl;}
};
int main()
{
	Test t;
	t.output();
	Test t1(3,5);
	t1.output();
	return 0;
}
