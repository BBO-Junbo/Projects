#include <iostream>
using namespace std;
class Base{

public:
Base (int i,int j){ x0=i; y0=j;}
void Move(int x,int y){ x0+=x; y0+=y;}
void Show(){ cout<<"Base("<<x0<<","<<y0<<")"<<endl;}
private:
int x0,y0;
};
class Derived: private Base{
public:
Derived(int i,int j,int m,int n):Base(i,j){ x=m; y=n;}
void Show (){cout<<"Next("<<x<<","<<y<<")"<<endl;}
void Move1(){Move(2,3);}
void Show1(){Base::Show();}
private:
int x,y;
};
int main( ){
Base b(1,2);
b.Show();
Derived d(3,4,10,15);
d.Move1();
d.Show();
d.Show1();
return 0;
}

