#include<iostream>
using namespace std;
const int maxsize=100;
void DFS(int map[maxsize][maxsize],int x,int y,int n,int m)
{
	if(x<0||y<0||x>=n||y>=m) return;
        else if(map[x][y] == 1){
            map[x][y] = 0;
            DFS(map, x-1,y,n,m);
            DFS(map, x+1, y,n,m);
            DFS(map, x, y+1,n,m);
            DFS(map,x, y-1,n,m);
    
        }
}

int main()
{
	int n,m,map[maxsize][maxsize],count = 0;char seq;
	cout<<"请输入地图的高和宽:";
	cin>> n>>seq>>m;
	cout<<"请输入地图"<<endl;
	for(int x=0;x<n;x++)
        for(int y = 0;y<m; y++)
        	cin>>map[x][y];  	
    for(int x=0;x<n;x++){
        for(int y = 0;y<m; y++){
            if(map[x][y] == 1){
                    DFS(map, x, y,n,m);
                    count++;
                    
                }
            }
    }
    cout<<"敌军小队数量："<<count<<endl;

    return 0;
}
