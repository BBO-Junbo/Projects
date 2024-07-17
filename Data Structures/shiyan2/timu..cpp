#include<iostream>
using namespace std;
int main()
{
	int N,M,a,b,c,temp,fir,dex;
	int del[100001];
	int pre[100001];
	int nex[100001];
	cin>>N;
	for(int i=0;i<=N;i++)
	{
		del[i]=0;
		pre[i]=0;
		nex[i]=0;
	}
	for(int j=2;j<=N;j++)
	{
		cin>>a>>b;
		if(b==0)
		{
			nex[pre[a]]=j;
			temp=pre[a];
			pre[a]=j;
			nex[j]=a;
			pre[j]=temp;
		}
		else
		{
			pre[nex[a]]=j;
			temp=nex[a];
			nex[a]=j;
			pre[j]=a;
			nex[j]=temp;
		}
	}
	cin>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>c;
		del[c]=c;
	}
	for(int i=0;i<N;i++)
	{
		if(pre[i]==0)
			fir=i;
	}
	dex=fir;
	while(1)
	{
		if(del[dex]==0)
		{
			cout<<dex<<" ";
		}if(nex[dex]==0)break;
		dex=nex[dex];
		
	}
	
	

	return 0;
}

