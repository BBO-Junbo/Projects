#include <iostream>
using namespace std;
template <class T>
struct HaffmanTreeNode{
	int weight;
	int parent;
	int leftchild;
	int rightchild;
	T data;
	string num;
};
struct MIN{
    int s1;
    int s2;
} ;
template <class T>
void CreatHaffmanTree(HaffmanTreeNode<T> hafmtree[],int leafweight[],T hfmtree_T[],int n)
{ 
	for (int i=1;i<=n;i++){
		hafmtree[i].weight=hfmtree_T[i];
		hafmtree[i].data=hfmtree_T[i];
		hafmtree[i].parent=0;hafmtree[i].leftchild=0;hafmtree[i].rightchild=0;
	}
if (n <= 1)														
		return;
	int min1, min2;													
	int rnode, lnode;													
	for (int i = n + 1; i <= 2 * n -1; i++)							
	{
		int min1 = 32767; int lnode = -1;											
		int min2 =32767; int rnode = -1;
		for (int j = 1; j <= i - 1; j++)												
		{														
				if (hafmtree[j].weight < min1 && hafmtree[j].parent == -1)		
				{
					min2 = min1;	rnode = lnode;				
					min1 = hafmtree[j].weight; lnode = j;						
				}
				else if (hafmtree[j].weight < min2 && hafmtree[j].parent == -1)		
				{
					min2 = hafmtree[j].weight;
					rnode = j;
				}
		}
		hafmtree[lnode].parent = hafmtree[rnode].parent = i;						
		hafmtree[i].leftchild = lnode; hafmtree[i].rightchild = rnode;							
		hafmtree[i].weight = hafmtree[lnode].weight + hafmtree[rnode].weight;			
	}


  	

}

template<class T>
void HaffmanEncode(HaffmanTreeNode <T>hafmtree[], string s, int m)
{
    string estring;
    for(int i=0;i<=s.size();i++){
        for(int x = 1; x <= m; x++){
            if(hafmtree[x].data == s[i]){
            	estring = estring + hafmtree[x].num;
                x=m;
            }
        }
    }
    cout<<estring<<endl;
}
template<class T>
void HaffmanDecode(HaffmanTreeNode <T>hafmtree[], string s, int m)
{
    string estring;
    int pos=0,first=0;
    for(int x=0;x<=s.size();x++){
        pos++;
        for(int i=1;i<=m;i++){
            if(hafmtree[i].num == s.substr(first, pos)){
                cout<<hafmtree[i].data;
                first = pos + first;
                pos = 0;
            }
        }
    }
    cout<<endl;
}

int main()
{
	int n=1;string s,temp_s;
	cout<<"Plaese enter the num of HaffmanTree's LeafNode:";
	cin>>n;
	HaffmanTreeNode <char> haffmantree[2*n];int hfmtree_weight[n];char hfmtree_char[n];
	cout<<endl<<"Plaese enter the char and weight of HaffmanTree's LeafNode:"<<endl;
	for(int i=0;i<n;i++)
		cin>>hfmtree_char[i]>>hfmtree_weight[i];
	CreatHaffmanTree(haffmantree,hfmtree_weight, hfmtree_char,n);
	s="PLAN";
	cout<<"The haffmancode of char'P' is ";HaffmanEncode(haffmantree,s,4);
	/*
×Ö·û P µÄ¹þ·òÂü±àÂëÎª£º£¨ºóÃæ×Ô¼ºÌî£©
×Ö·û L µÄ¹þ·òÂü±àÂëÎª£º
×Ö·û A µÄ¹þ·òÂü±àÂëÎª£º
×Ö·û N µÄ¹þ·òÂü±àÂëÎª£º
×Ö·û T µÄ¹þ·òÂü±àÂëÎª*/
	
	
	
}
