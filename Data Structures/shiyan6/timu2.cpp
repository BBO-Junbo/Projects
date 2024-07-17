#include<iostream>
#include<stdio.h>
using namespace std;
const int Maxsize=100;
template<class T>
struct Node{
	T value;
	int in=0; 
	int out=0;
	int sum=0;
};
struct Edge{
	int nfrom;
	int nto;
	int weight;
};
template<class T>
class Graph{
public:
	Node <T> nodes[Maxsize];
	Edge edges[Maxsize*5];
	int Adjmatrix[Maxsize][Maxsize];
	int size;
	int numedges;
	void CreateWeightedDirectedgraph(T nod[],int fr[],int too[],int wei[],int n,int m){
		size=n;
		numedges=m;
		for(int i=0;i<n;i++)
			nodes[i].value=nod[i];		
		for(int i=0;i<n;i++)
			for(int j=0;i<n;i++)
				Adjmatrix[i][j]=0;
		for(int i=0;i<m;i++){
			edges[i].nfrom=fr[i];edges[i].nto=too[i];edges[i].weight=wei[i];
			nodes[too[i]-1].in++;nodes[fr[i]-1].out++;
			Adjmatrix[fr[i]-1][too[i]-1]=wei[i];
			nodes[fr[i]-1].sum+=wei[i];
		}
			
		
	}
	void PrintAdjmatrix(){
		cout<<"   ";
		for(int i=0;i<size;i++)
			cout<<nodes[i].value<<"  ";
		cout<<endl;
		for(int i=0;i<size;i++){
			cout<<nodes[i].value<<"  ";
			for(int j=0;j<size;j++){
				cout<<Adjmatrix[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	void PrintAdjacencytables(){
		bool signal=true;
		for(int i=0;i<size;i++){
			cout<<this->nodes[i].value<<":";
			for(int j=0;j<size;j++){
				if(Adjmatrix[i][j]!=0)
					cout<<this->nodes[j].value<<" "<<Adjmatrix[i][j]<<",";		
			}
		cout<<endl;
		}
	}
	void PrintDegree(){
		for(int i=0;i<size;i++)
			cout<<"����"<<nodes[i].value<<","<<"���Ϊ"<<nodes[i].in<<","<<"����Ϊ"<<nodes[i].out<<endl;
	}
	T getMaxsumNode(){
		int max=nodes[0].sum;
		char maxnode;
		for(int i=0;i<size;i++)
			if(nodes[i].sum>max){
				max=nodes[i].sum;
				maxnode=nodes[i].value;
			}
				
		return maxnode;
	}
	int getMaxSum(){
		int max=nodes[0].sum;
		for(int i=0;i<size;i++)
			if(nodes[i].sum>max)
				max=nodes[i].sum;
		return max;
	}
};
int main()
{
	int n,m;char sep;Graph <char> P;
	cout<<"ͼ P �Ķ��������";
	cin>>n;char nod[n];
	cout<<"������ͼ P �Ķ������У�";
	for(int i=0;i<n;i++)
		cin>>nod[i];
	cout<<"ͼ G �ı߸�����";
	cin>>m;int fr[m];int too[m],wei[m];
	cout<<"������ͼ G �ıߣ�"<<endl;
	for(int i=0;i<m;i++)
		cin>>fr[i]>>sep>>too[i]>>wei[i];
	P.CreateWeightedDirectedgraph(nod,fr,too,wei,n,m);
	cout<<"����ͼ P ���ڽӾ���Ϊ��"<<endl;
	P.PrintAdjmatrix();
	cout<<"����ͼ P ���ڽӱ�Ϊ��"<<endl;
	P.PrintAdjacencytables();
	cout<<"��Ȩ����ͼ P �У��Ӷ���"<<P.getMaxsumNode()<<"�����ı�Ȩ��֮�����,��ֵΪ"<<P.getMaxSum()<<endl;
}

