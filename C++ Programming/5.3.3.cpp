#include <iostream>
using namespace std;
class Animal{
public:
virtual void Report() { cout<<"Report from Animal! "<<endl; }
};
class Tiger : public Animal{
public:
virtual void Report() {cout<<"Report from Tiger! "<<endl; }
};
class Monkey : public Animal{
public:
virtual void Report() {
cout<<"Report from Monkey! "<<endl; 
}
};
void show(Animal *p){
p->Report(); 
}
int main(){
Tiger tiger;
Monkey monkey;
Animal animal=tiger;
show(&tiger);
show(&monkey);
show(&animal);
return 0;
}
