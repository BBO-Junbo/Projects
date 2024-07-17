
#include <iostream>
using namespace std;
class Matrix{

double * elem;
int row,col;
public:
Matrix(int r,int c){ 
row=r;col=c;
elem=new double[row *col];
}
double &operator() (int x,int y) {
return elem[ col *(x-1)+y-1];
}
double &operator()(int x,int y) const {
return elem[ col*(x-1)+y-1];
}
~Matrix(){delete [] elem; }
};
int main(){
Matrix m(5,8);
int i;
for(i=1;i<6; ++i)
m(i,1)=i+5;
for(i=1; i<6; ++i)
cout<<m(i, 1)<< ",";
cout<<endl;
return 0;
}

