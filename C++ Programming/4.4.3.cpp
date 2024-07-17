#include <iostream>
#include <vector>
using namespace std;
class Fraction{
private:
int num,den;
public:
explicit Fraction(int n=0,int d=1):num(n),den(d){}
explicit operator double()const {return 1.0*num/den; }
Fraction operator+(const Fraction& f)const{
return Fraction(num*f.den+den*f.num,den*f.den);
}
void output()const{cout<<num<<"/"<<den<<endl;}
};
int main(){
Fraction f1(1,3);
f1.output();
Fraction f2=f1+static_cast<Fraction>(1);
f2.output();
cout<<1+static_cast<double>(f1)<<endl;
return 0;
}
