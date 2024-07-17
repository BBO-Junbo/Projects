#include<iostream>
using namespace std;
int main()
{
	char word[50];
	cin>>word;
	for(int i=0;word[i]!='\0';++i)
	{
		if(word[i]>='a'&&word[i]<='z')
		{
			word[i]=32;
		}
	}
	cout<<word<<endl;
	return 0;
}
