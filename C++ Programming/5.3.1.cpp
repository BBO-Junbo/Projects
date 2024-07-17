#include <iostream>

using namespace std;
class Base {
public:
void display() {cout<<"Base display"<<endl; } 
};
class Derived : public Base {
public:
void display() { cout<<"Derived display"<<endl; }
};
void display(Base & rr){
rr.display();
}
int main(){
Base b;
Derived d;
display(b);
display(d);
return 0;
}
