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
	cout<<"ͼ G �Ķ��������";
	cin>>n;int link[maxsize][maxsize]={0};bool visited[n]={false};
	cout<<"������ͼ G �ıߵĸ�����";
	cin>>m;
	cout<<"������ͼ G �ıߣ�"<<endl;
	for(int i=0;i<m;i++){
		cin>>a>>seq>>b;
		link[a-1][b-1]=1;
	}
	cout<<"��������������ⶥ�㣺"; 
	cin>>a>>seq>>b;int help[n]={0};
	DFS(link,a-1,n,visited);
	if(visited[a-1]==visited[b-1]&&visited[b-1]==true)
		cout<<"True"<<endl;
	else
		cout<<"Fales"<<endl;
	
} 
/*��Ŀһ��
����һ���� n �����������ͼ G��ÿ����������Ϊ
�� 1 �� n ��������ͼ��ÿ�Զ��������һ�������ӣ�ͬʱ
û�ж�����ڴ���������һص�����ıߡ�
�����д����ȷ���Ƿ���ڴӶ��� O ������ D ����
Ч·����
��1�� ����ͼ P �Ķ������кͱ� ͼ G
��2�� ���붥�� O �Ͷ��� D �ı��
��3�� ����Ӷ��� O ������ D ����Ч·������� True��������� False
���룺
��1��ͼ G �Ķ��������5
������ͼ G �ıߣ�
1��2
1��3
2��4
5��6
5��7
6��7
��2��1��4
�����������ʽ�ο�����
��3��Tru*/
