#include<iostream>
using namespace std;
class Test
{
public:
	Test(int xx=1):x(xx){}
	void output()const
	{
		cout<<"x:"<<x<<endl;
	}
private:
	int x;
};
int main()
{
	Test t;
	t.output();
	t=4;
	t.output();
	return 0;
}
