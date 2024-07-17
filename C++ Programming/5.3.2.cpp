#include <iostream>
using namespace std;
class Person{
public:
Person() {
cout<<"Person 构造函数! "<<endl;
}
~Person() {
cout<<"Person 被析构! "<<endl;
}
};
class Student : public Person
{
public:
Student() {cout<<"Student 构造函数! "<<endl;}
~Student() {cout<<"Student 被析构! "<<endl;}
};

class Teacher : public Person{
public:
Teacher() {
cout<<"Teacher 构造函数! "<<endl;
}
~Teacher() 
{cout<<"Teacher 被析构! "<<endl;}
};
int main(){
Student s;
Teacher t;
return 0;
}
