#include <iostream>
using namespace std;
class Person{
public:
Person() {
cout<<"Person ���캯��! "<<endl;
}
~Person() {
cout<<"Person ������! "<<endl;
}
};
class Student : public Person
{
public:
Student() {cout<<"Student ���캯��! "<<endl;}
~Student() {cout<<"Student ������! "<<endl;}
};

class Teacher : public Person{
public:
Teacher() {
cout<<"Teacher ���캯��! "<<endl;
}
~Teacher() 
{cout<<"Teacher ������! "<<endl;}
};
int main(){
Student s;
Teacher t;
return 0;
}
