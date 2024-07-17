#include<iostream>
using namespace std;
class Point
{
	int x,y;
public:
	Point(int x1=0,int y1=0):x(x1),y(y1)
	{
		cout<<"Point:"<<x<<' '<<y<<'\n';
	}
	~Point()
	{
		cout<<"Point destructor!\n";
	}
};
class Circle
{
	Point center;
	int radius;
public:
	Circle(int cx,int cy,int r):center(cx,cy),radius(r)
	{
		cout<<"Circle radius:"<<radius<<"\n";
	}
	~Circle()
	{
		cout<<"Circle destructor!\n";
	}
};

int main()
{
	Circle c(3,4,5);
	return 0;
}












