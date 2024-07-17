#include<iostream>
class Test
{
private:
	int a;
public:
	Test()=default;//added by myself
	Test(const Test&t)=default;
};
int main()
{
	Test t;
	return 0;
}
