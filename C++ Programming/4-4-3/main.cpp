#include <iostream>
using namespace std;
class Array{
private:
int *pdata;
int size;
public:
Array():size(0){ pdata=nullptr;}
Array(int s):size(s){
pdata=new int[size];
}
~Array(){delete[] pdata;}
Array(const Array& a):size(a.size){
pdata=new int[size];
for(int i=0;i<size;++i) pdata[i]=a[i];
}
Array(Array && a):size(a.size){
pdata=a.pdata;
a.size=0;
a.pdata=nullptr;
}
Array& operator=(const Array& a){
if(this==&a) return *this;
size=a.size;
pdata=new int[size];
for(int i=0;i<size;++i) pdata[i]=a[i];
return *this;
}
Array& operator=(Array&& a){
if(this==&a) return *this;
size=a.size;
pdata=a.pdata;
a.size=0;
a.pdata=nullptr;
return *this;
}
const int& operator[](int index)const{ return pdata[index];}
int& operator[](int index){return pdata[index];}
int length()const{return size;}
};
int main(){
Array a1(3);
for(int i=0;i<3;++i) a1[i]=i;
cout<<"length of a1:"<<a1.length()<<endl;
Array a2(a1);
cout<<"length of a1:"<<a1.length()<<endl;
cout<<"length of a2:"<<a2.length()<<endl;
Array a3(move(a1));
cout<<"length of a1:"<<a1.length()<<endl;
cout<<"length of a3:"<<a3.length()<<endl;
return 0;
}
