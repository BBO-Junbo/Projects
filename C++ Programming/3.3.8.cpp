#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;
	int age;
public:
	Person(string name,int age);
	~Person()
	{
		cout<<"Bye! My name is "<<name<<",I'm "<<age<<"years old."<<endl;
	}
	void growup()
	{
		age++;
	}
};
Person::Person(string name,int age)
{
	this->name=name;
	this->age=age;
	cout<<"Hello,"<<name<<"is coming!"<<endl;
}
int main()
{
	Person p("zhang",1);
	for(int i=0;i<90;++i)
		p.growup();
	return 0;
}
