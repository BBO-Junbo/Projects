#include <iostream>
using namespace std;
class Base{
private:
int base;
public:
Base(int b) {
base=b;
cout<<"base="<<b<<endl;
}
~Base() { }
};
class Derived : public Base{
private:
Base bb;
int derived;
public:
Derived(int d,int b,int c) : bb(c) , Base(b) {
derived=d;
cout<<"derived="<<derived<<endl;
}
~Derived() {}
};
int main(){
Derived d(3,4,5);
return 0;
}
