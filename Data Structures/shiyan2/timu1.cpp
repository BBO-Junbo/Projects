#include<iostream>
using namespace std;
class LinkNode{
public:
    int data;
    LinkNode *link;
    LinkNode(LinkNode *ptr=NULL){link=ptr;}
    LinkNode(const int item,LinkNode *ptr=NULL)
        {data=item;link=ptr;}
};
class List{
public:	
	List(){first=new LinkNode;}
	~List(){makeEmpty();};
	void makeEmpty();
	int Search(int x);
	int _Search(int x);
 	bool pushfront(int i,int x);
 	bool pushback(int i, int x);
 	bool Remove(int i);
 	LinkNode* Locate(int i); 
 	bool IsEmpty(){return first->link==NULL ?true:false;}
    bool IsFull(){return false;}
    void output();
protected:
    LinkNode *first;
};
void List::makeEmpty(){
    LinkNode *q;
    while(first->link!=NULL){
        q =first->link;
        first->link =q->link;
        delete q;
    }
}
int List::Search(int x){
    LinkNode *current = first->link;
    int pos=0;
    while(current !=NULL){
        pos++;
        if (current->data==x) break;
        else current = current->link;
     }
    return pos;
}
int List::_Search(int x){
    LinkNode *current = first->link;
    int pos=0;
    while(current !=NULL){
        pos++;
        if (current->link->data==x) break;
        else current = current->link;
     }
    return pos;
}
bool List::pushfront(int i, int  x){
    LinkNode *current = Locate(Search(i)-1);
    if (current ==NULL) return false;
    LinkNode * newNode = new LinkNode(x);
    if(newNode==NULL){cerr <<"链表为空"<<endl;exit(1);}
    newNode->link= current->link;
    current->link=newNode;
    return true;
}
bool List::pushback(int i, int  x){
    LinkNode *current = Locate(Search(i));
    if (current ==NULL) return false;
    LinkNode * newNode = new LinkNode(x);
    if(newNode==NULL){cerr <<"链表为空"<<endl;exit(1);}
    newNode->link= current->link;
    current->link=newNode;
    return true;
}
bool List::Remove(int i){
    LinkNode * current = Locate(Search(i)-1);
    if (current==NULL||current->link ==NULL) return false;
    LinkNode *del= current->link;
    current->link = del->link;
    delete del;
    return true;
}
LinkNode* List::Locate(int i){
    if (i< 0) return NULL;
    LinkNode *current = first;
	int k=0;
    while (current!= NULL&& k<i)
    {current = current->link;k++;}
    return current;
}
void List::output(){
    LinkNode *current = (first->link)->link;
    while (current !=NULL){
        cout<<current->data<<" ";
        current= current->link;
    }
}
int main()
{
	int N,M,a,b,c;
	List L;
	L.pushback(0,0);
	L.pushback(0,1);
	cin>>N;
	for(int j=2;j<=N;j++)
	{
		cin>>a>>b;
		if(b==0)
			L.pushfront(a,j);
		else
		 	L.pushback(a,j);
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>c;
		L.Remove(c);
	}
	L.output();
	

	return 0;
}
