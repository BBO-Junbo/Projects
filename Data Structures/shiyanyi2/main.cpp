#include <iostream>

using namespace std;
template<class T>
class LinkNode{
public:
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr=NULL){link=ptr;}
    LinkNode(const T& item,LinkNode<T> *ptr=NULL)
        {data=item;link=ptr;}
};
template<class T>
class List{
public:
    List(){first=new LinkNode<T>;}
    List(const T& x){first = new LinkNode<T>(x);}
    List(List<T>& L);
    ~List(){makeEmpty();};
    void makeEmpty();
    int Length();
    LinkNode<T> *getHead(){return first;}
    int Search(T x);
    LinkNode<T> *Locate(int i);
    bool getData(int i,T& x);
    void setData(int i,T& x);
    bool Insert(int i,T& x);
    bool Remove(int i,T& x);
    bool IsEmpty()
        {return first->link==NULL ?true:false;}
    bool IsFull(){return false;}
    void inputRear(T endTag);
    void output();
protected:
    LinkNode<T> * first;
};

template<class T>
List<T>::List(List<T>& L){
    T value;
    LinkNode<T>*srcptr = L.first;
    LinkNode<T>*destptr = first = new LinkNode<T>;
    while(srcptr->link !=NULL){
        value=srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        destptr = destptr->link;
        srcptr=srcptr->link;
    }
    destptr->link =NULL;
}

template <class T>
void List<T>::makeEmpty(){
    LinkNode<T>*q;
    while(first->link!=NULL){
        q =first->link;
        first->link =q->link;
        delete q;
    }
}

template <class T>
int List<T>::Length(){
    LinkNode<T>*p= first->link;
    int count=0;
    while(p!=NULL){p=p->link;count++;}
    return count;
}

template<class T>
int List<T>::Search(T x){
    LinkNode<T>*current = first->link;
    int pos=0;
    while(current !=NULL){
        pos++;
        if (current->data==x) break;
        else current = current->link;
     }
    return pos;
}
template <class T>
LinkNode<T>*List<T>::Locate(int i){
    if (i< 0) return NULL;
    LinkNode<T> *current = first;int k=0;
    while (current!= NULL&& k<i)
    {current = current->link;k++;}
    return current;
}

template <class T>
bool List<T>::getData(int i,T& x){
    if (i<=0) return false;
    LinkNode<T>*current= Locate(i);
    if (current==NULL) return false;
    else{x=current->data;return true;};
}

template <class T>
void List<T>::setData(int i,T& x){
    if (i<= 0) return;
    LinkNode<T>*current = Locate(i);
    if (current ==NULL) return;
    else current->data=x;
}
template <class T>
bool List<T>::Insert(int i, T& x){
    LinkNode<T> * current = Locate(i);
    if (current ==NULL) return false;
    LinkNode<T> * newNode = new LinkNode<T>(x);
    if(newNode==NULL){cerr <<"存储分配错误!"<<endl;exit(1);}
    newNode->link= current->link;
    current->link=newNode;
    return true;
}

template<class T>
bool List<T>::Remove(int i,T& x){
    LinkNode<T> * current = Locate(i-1);
    if (current==NULL||current->link ==NULL) return false;
    LinkNode<T>*del= current->link;
    current->link = del->link;
    x= del->data; delete del;
    return true;
}

template<class T>
void List<T>::output(){
    LinkNode<T>*current = first->link;
    while (current !=NULL){
        cout<<current->data<<"  ";
        current= current->link;
    }
    cout << endl;
}

template<class T>
void List<T>::inputRear(T endTag){
    LinkNode<T>*newNode,* last;T val;
    makeEmpty();
    cin>> val; last = first;
    while(val!=endTag){
        newNode =new LinkNode<T>(val);
        if(newNode==NULL){cerr <<"存储分配错误!"<<endl;exit(1);}
        last->link=newNode; last = newNode;
    cin >> val;
    }
    last->link=NULL;
}
int main()
{
    char temp;
    List<char> H;           //（1） 初始化单链表 H
    H.inputRear('0');       //（2） 依次采用尾插法插入 a,b,c,d,e 元素
    H.output();             //（3） 输出单链表 H 及 H 的长度
    cout<<"单链表H的长度:"<<H.Length()<<endl;
    H.getData(2,temp);      //（4） 输出单链表 H 的第 2 个元素
    cout<<"单链表 H 的第 2 个元素:"<<temp<<endl;
    temp='e';                 //（5） 输出元素 e 的位置
    cout<<"元素 e 的位置:"<<H.Search(temp)<<endl;
    temp='f';               //（6） 在第 4 个元素位置上插入 f 元素。
    H.Insert(4,temp);
    temp='g';                        //（7） 修改 H 的第 3 个元素为 g。
    H.setData(3,temp);
    H.output();//（8） 输出单链表 H。

}

