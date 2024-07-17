
#include<iostream>

#include<stdio.h>
using namespace std;
const int Maxsize=100;
template<class T>
struct Node{
	T value;
	int in=0; 
	int out=0;
};
struct Edge{
	int nfrom;
	int nto;
};
template<class T>
class Graph{
public:
	Node <T> nodes[Maxsize];
	Edge edges[Maxsize*5];
	int Adjmatrix[Maxsize][Maxsize];
	int size;
	int numedges;
	void CreateDirectedgraph(T nod[],int fr[],int too[],int n,int m){
		size=n;
		numedges=m;
		for(int i=0;i<n;i++)
			nodes[i].value=nod[i];		
		for(int i=0;i<n;i++)
			for(int j=0;i<n;i++)
				Adjmatrix[i][j]=0;
		for(int i=0;i<m;i++){
			edges[i].nfrom=fr[i];edges[i].nto=too[i];
			nodes[too[i]-1].in++;nodes[fr[i]-1].out++;
			
		}
		for(int i=0;i<m;i++)
			Adjmatrix[fr[i]-1][too[i]-1]=1;
		
	}
	void CreateUndirectedgraph(T nod[],int fr[],int too[],int n,int m){
		size=n;
		numedges=m;
		for(int i=0;i<n;i++)
			nodes[i].value=nod[i];		
		for(int i=0;i<n;i++)
			for(int j=0;i<n;i++)
				Adjmatrix[i][j]=0;
		for(int i=0;i<m;i++){
			edges[i].nfrom=fr[i];edges[i].nto=too[i];
			nodes[too[i]-1].in++;nodes[fr[i]-1].out++;
		}
		for(int i=0;i<m;i++)
			Adjmatrix[fr[i]-1][too[i]-1]=Adjmatrix[too[i]-1][fr[i]-1]=1;
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
				if(Adjmatrix[i][j]==1)
					cout<<this->nodes[j].value<<",";		
			}
		cout<<endl;
		}
	}
	void PrintDegree(){
		for(int i=0;i<size;i++)
			cout<<"顶点"<<nodes[i].value<<","<<"入度为"<<nodes[i].in<<","<<"出度为"<<nodes[i].out<<endl;
	}
};
int main()
{
	int n,m;char sep;Graph <char> G,H;
	cout<<"图 G 的顶点个数：";
	cin>>n;char nod[n];
	cout<<"请输入图 G 的顶点序列：";
	for(int i=0;i<n;i++)
		cin>>nod[i];
	cout<<"图 G 的边个数：";
	cin>>m;int fr[m];int too[m];
	cout<<"请输入图 G 的边："<<endl;
	for(int i=0;i<m;i++)
		cin>>fr[i]>>sep>>too[i];
	G.CreateDirectedgraph(nod,fr,too,n,m);
	cout<<"有向图 G 的邻接矩阵为："<<endl;
	G.PrintAdjmatrix();
	H.CreateUndirectedgraph(nod,fr,too,n,m);
	cout<<"无向图 H 的邻接矩阵为："<<endl;
	H.PrintAdjmatrix();
	cout<<"有向图 G 的邻接表为："<<endl;
	G.PrintAdjacencytables();
	cout<<"有向图 G 每个顶点的入度出度为："<<endl;
	G.PrintDegree();
	return 0;
}











