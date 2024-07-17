#include<iostream>
#include<vector>
using namespace std;

vecrot<int>getDiagonal(const vector<vector<int>>& matrix)
{
	
}

int main()
{
	vector<vector<int>>matrix
	{
		{0,1,2,3,4},
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7},
		{4,5,6,7,8},
 	};
	vector<int>diagonal=getDiagonal(matrix);
	for(auto e:diagonal)
	{
		cout<<e<<endl;	
	 }	 
	 return 0;
} 
