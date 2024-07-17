
#include<iostream>

using namespace std;
template<class T>
struct BinTreeNode{
	T data;
	BinTreeNode<T> *leftchild,*rightchild;
	BinTreeNode():leftchild(NULL),rightchild(NULL){}
};
template<class T>
class BinTree{
public:
	BinTree(){}
	~BinTree(){clear(root);cout<<"Binary Tree has been destoryed"<<endl;}
	BinTreeNode<T> *  CreatBinTree(T arr[],int len,int index=0);
	BinTreeNode<T> *  Search(BinTreeNode<T> *subtree,T item);
	int NodeNum(BinTreeNode<T> *subtree,int num=1);
	int LeafNum(BinTreeNode<T> *subtree,int num=0);
	void clear(BinTreeNode<T> *subtree);
	void PreOrder(BinTreeNode<T> *subtree);
	void InOrder(BinTreeNode<T> *subtree);
	void PostOrder(BinTreeNode<T> *subtree);
	void ExchangeLandR(BinTreeNode<T> *subtree);
	bool IscompletelyBintree(BinTreeNode<T> *subtree,int index=0);
	BinTreeNode<T> *root;
};
template<class T>
void BinTree<T>::clear(BinTreeNode<T> *subtree){
	if (subtree){
        clear(subtree->leftchild);
        clear(subtree->rightchild);
        delete root;
        root=NULL;
    }
}
template<class T>
BinTreeNode<T> * BinTree<T>::CreatBinTree(T arr[],int len,int index){
	if(index>len)
		return NULL;
	BinTreeNode<T>* tempNode = new BinTreeNode<T>;
	if(arr[index]=='!'){
		tempNode->data=NULL;
		tempNode->leftchild = NULL;
		tempNode->rightchild = NULL;
	}	
    tempNode->data = arr[index];
    if(arr[index * 2 + 1]!='!')
    	tempNode->leftchild = CreatBinTree(arr, len, index * 2 + 1); 
    else 
    	tempNode->leftchild=NULL;
    if(arr[index * 2 + 2]!='!')
    	tempNode->rightchild = CreatBinTree(arr, len, index * 2 + 2);
    else
    	tempNode->rightchild=NULL;
    root = tempNode;
    return root;
}
template<class T>
BinTreeNode<T> *  BinTree<T>::Search(BinTreeNode<T> *subtree,T item){
	if (!subtree) return NULL;
	if (subtree->data == item) return subtree;
	if (Search(subtree->leftchild, item))
		return Search(subtree->leftchild, item); 
	else 
		return Search(subtree->rightchild, item);
}
template<class T>
int BinTree<T>::NodeNum(BinTreeNode<T> *subtree,int num){
	if(subtree!=NULL){
        num=NodeNum(subtree->leftchild,num); 
        num=NodeNum(subtree->rightchild,num);
	}
	return num;
}
template<class T>
int BinTree<T>::LeafNum(BinTreeNode<T> *subtree,int num){
	if(subtree!=NULL){
		if(subtree->leftchild==NULL&&subtree->rightchild==NULL)
            num++;
        num=LeafNum(subtree->leftchild,num); 
        num=LeafNum(subtree->rightchild,num);
	}
	return num;

}
template<class T>
void BinTree<T>::PreOrder(BinTreeNode<T> *subtree){
	if(subtree){
		cout<<subtree->data<<' ';
		PreOrder(subtree->leftchild);
		PreOrder(subtree->rightchild);
	}
}
template<class T>
void BinTree<T>::InOrder(BinTreeNode<T> *subtree){
	if(subtree){
	InOrder(subtree->leftchild);
	cout<<subtree->data<<' ';
	InOrder(subtree->rightchild);
	}
}
template<class T>
void BinTree<T>::PostOrder(BinTreeNode<T> *subtree){
	if(subtree){
	PostOrder(subtree->leftchild);
	PostOrder(subtree->rightchild);
	cout<<subtree->data<<' ';
	}
}
template<class T>
void BinTree<T>::ExchangeLandR(BinTreeNode<T> *subtree){
	BinTreeNode<T> *temp;
	temp=subtree->leftchild;
	subtree->leftchild=subtree->rightchild;
	subtree->rightchild=temp;
	if(subtree->rightchild!=NULL)
		ExchangeLandR(subtree->rightchild);
	if(subtree->leftchild!=NULL)
		ExchangeLandR(subtree->leftchild);	
}
template<class T>
bool BinTree<T>::IscompletelyBintree(BinTreeNode<T> *subtree,int index)
{
	int num=NodeNum(subtree);
	if(subtree->leftchild==NULL&&subtree->rightchild!=NULL)
		return false;
	else if(subtree->rightchild==NULL&&subtree->leftchild!=NULL)
		return false;
	else if(subtree->rightchild!=NULL&&subtree->leftchild!=NULL){
		IscompletelyBintree(subtree->leftchild,index);
		IscompletelyBintree(subtree->rightchild,index);
	}
	if(index>num)
		return true;
}
int main()
{
	BinTree <char> tree;
	char temparry[]={'A','B','D','C','E','F','G','!','!','!','!','Y'};
	tree.CreatBinTree(temparry,11);
	cout<<"Binary Tree has been constructed!"<<endl;
	BinTreeNode<char> *temp=tree.Search(tree.root,'D');
	cout<<"Element 'D's leftchild is: "<<temp->leftchild->data<<endl; 
	cout<<"Element 'D's rightchild is: "<<temp->rightchild->data<<endl; 
	cout<<"The num of Leaf is: "<<tree.LeafNum(tree.root)<<endl;
	cout<<"Pre-order traversal:";
	tree.PreOrder(tree.root);
	cout<<endl;
	tree.ExchangeLandR(tree.root);
	cout<<"Exchange Leftchild with Rightchild"<<endl;
	cout<<"Post-order traversal:";
	tree.PostOrder(tree.root);
	cout<<endl;
	bool tempbool;
	tempbool=tree.IscompletelyBintree(tree.root);
	cout<<"IS it a completely Binarytree? ";
	if(tempbool==true)
		cout<<" Yes"<<endl;
	else
		cout<<" No"<<endl;
	return 0;
}
