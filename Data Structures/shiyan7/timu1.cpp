#include<iostream>
using namespace std;
const int maxsize=100;
void DFS(int link[maxsize][maxsize],int i,int n,bool visited[])
{
	int j;
	visited[i]=true;    
	for(j=0;j<n;j++)
	{
		if(link[i][j]==1&&!visited[j])   
			DFS(link,j,n,visited);
	} 
}

int main()
{
	int n,m,a,b;char seq;
	cout<<"图 G 的顶点个数：";
	cin>>n;int link[maxsize][maxsize]={0};bool visited[n]={false};
	cout<<"请输入图 G 的边的个数：";
	cin>>m;
	cout<<"请输入图 G 的边："<<endl;
	for(int i=0;i<m;i++){
		cin>>a>>seq>>b;
		link[a-1][b-1]=1;
	}
	cout<<"请输入两个待检测顶点："; 
	cin>>a>>seq>>b;int help[n]={0};
	DFS(link,a-1,n,visited);
	if(visited[a-1]==visited[b-1]&&visited[b-1]==true)
		cout<<"True"<<endl;
	else
		cout<<"Fales"<<endl;
	
} 
/*题目一：
存在一个有 n 个顶点的无向图 G。每个顶点的序号为
从 1 到 n 的整数。图中每对顶点由最多一条边连接，同时
没有顶点存在从自身出发且回到自身的边。
请你编写程序，确定是否存在从顶点 O 到顶点 D 的有
效路径。
（1） 输入图 P 的顶点序列和边 图 G
（2） 输入顶点 O 和顶点 D 的编号
（3） 如果从顶点 O 到顶点 D 的有效路径，输出 True，否则输出 False
输入：
（1）图 G 的顶点个数：5
请输入图 G 的边：
1，2
1，3
2，4
5，6
5，7
6，7
（2）1，4
输出（仅作格式参考）：
（3）Tru*/
