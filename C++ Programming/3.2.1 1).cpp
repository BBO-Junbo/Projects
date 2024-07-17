#include<iostream>
#include<string>
using namespace std;
class Mouse
{
public:
	Mouse(string newName);
	~Mouse();
	string getName()
	{
		return name;	
	}
	static int mouseNum;
private:
	string name;
};
int Mouse::mouseNum=0;
Mouse::Mouse(string newName):name(newName)
{
	cout<<name<<" is born!\n";
	mouseNum++;
}
Mouse::~Mouse()
{
	cout<<name<<" is gone...\n";
	mouseNum--;
}
class Cat
{
public:
	Cat(const string&newName):name(newName)
	{
		cout<<name<<" is coming!\n";
	}
	void catchMouse(Mouse *pMouse);
private:
	string name;
};
void Cat::catchMouse(Mouse *pMouse)
{
	cout<<"I catch you!I never want to see you again."<<pMouse->getName()<<"!"<<endl;
	delete pMouse;
}

int main()
{
	Cat cat("Black Cat Detective");
	Mouse *pMouse1=new Mouse("Micky");
	cout<<Mouse::mouseNum<<" mouse left.\n";
	Mouse *pMouse2=new Mouse("Xiaohua");
	cout<<Mouse::mouseNum<<" mouse left.\n";
	cat.catchMouse(pMouse2);
	cout<<Mouse::mouseNum<<" mouse left.\n";
	cat.catchMouse(pMouse1);
	cout<<Mouse::mouseNum<<" mouse left.\n";
	return 0;
}


