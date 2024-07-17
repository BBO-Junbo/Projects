#include <iostream>
using namespace std;
const int defaultSzie=100;
template<class T>
class SeqList
{
protected:
    T *data;
    int maxSize;
    int last;
    void reSize(int newSize);
public:
    SeqList(int sz=defaultSzie);
    SeqList(SeqList<T>&L);
    ~SeqList(){delete[]data;}
    int Size()const{return maxSize;}
    int Length()const{return last+1;}
    int Search(T& x)const;
    int Locate(int i)const;
    bool getData(int i,T& x)const
        {if (i>0&&i<= last+1){x=data[i-1];return true;}else return false;}
    void setData(int i,T& x)
        {if (i>0&&i<= last+1)data[i-1]=x;}
    bool Insert(int i,T& x);
    bool Remove(int i,T& x);
    bool IsEmpty(){return (last==-1)?true:false;}
    bool IsFull(){return (last==maxSize-1)?true:false;}
    void input( ) ;
    void output( );


};

template<class T>
SeqList<T>::SeqList(int sz){
    if(sz>0){
        maxSize=sz;last=-1;
        data=new T[maxSize];
        if(data==NULL)
            {cerr<<"存储分配错误"<<endl;exit(1);}
    }
}

template<class T>
SeqList<T>::SeqList(SeqList<T>&L){
    maxSize=L.Size();last=L.Length()-1;T value;
    data=new T[maxSize];
    if(data==NULL)
        {cerr<<"存储分配错误"<<endl;exit(1);}
    for(int i=1;i<=last+1;i++)
        {L.getData(i,value);data[i-1]=value;}
}
template<class T>
void SeqList<T>::reSize(int newSize){
    if(newSize<=0)
        {cerr<<"无效的数组大小"<<endl;return;}
    if (newSize!=maxSize){
        T *newarray = new T[newSize];
        if (newarray ==NULL)
        {cerr <<"存储分配错误!"<< endl;exit(1);}
        int n =last+1;
        T *srcptr=data;
        T *destptr=newarray;
        while(n--)*destptr++=*srcptr++;
        delete[]data;
        data =newarray;maxSize=newSize;
    }
}
template<class T>
int SeqList<T>::Search(T& x)const{
    for(int i=0;i<=last;i++)
        if(data[i]==x) return i+1;
    return 0;
}
template<class T>
int SeqList<T>::Locate(int i)const{
    if(i>=1&&i<=last+1) return i;
    else return 0;
}
template <class T>
bool SeqList<T>::Insert(int i, T& x){
    if(last==maxSize-1)return false;
    if(i<0||i> last+1)return false;
    for (int j=last;j>=i;j--)
        data[j+1]=data[j];
    data[i]=x;
    last++;
    return true;
}
template <class T>
bool SeqList<T>::Remove(int i,T& x){
    if (last==-1)return false;
    if(i<0||i> last+1)return false;
    x= data[i-1];
    for (int j=i;j<= last;j++)
        data[j-1] = data[j];
    last--;
    return true;
}
template <class T>
void SeqList<T>::input( ){
    cout <<"开始建立顺序表，请输入表中元素个数";
    while (1){
       cin >> last;
       if (last<=maxSize) break;
       cout <<"表中元素个数输人有误,范围不能超过"<<maxSize-1<<":";
    }
    for (int i=0;i<last;i++){cout << i+1 <<"  "; cin >> data[i]; }
}
template <class T>
void SeqList<T>::output( ){
    cout <<"顺序表当前元素最后位置:"<< last << endl;
    for (int i= 0;i<= last; i++)cout << data[i] <"  ";
    cout << endl;
}
int main()
{
    char temp;
    SeqList<char> L;        //(1)初始化线性表L
    L.input();              //(2)依次采用尾插法插入 a,b,c,d,e 元素
    L.output();             //(3)输出顺序表L和顺序表L的长度
    cout<<"顺序表L的长度为："<<L.Length()<<endl;
    cout<<"判断顺序表 L 是否为空:";
    if(!L.IsEmpty())
        cout<<"表非空"<<endl;
    else                      //(4)判断顺序表 L 是否为空
        cout<<"表空"<<endl;
    L.getData(3,temp);        //(5)输出顺序表 L 的第 3 个元素
    cout<<"输出顺序表 L 的第 3 个元素:"<<temp<<endl;
    temp='d';                //（6） 输出元素 d 的位置
    cout<<"元素 d 的位置为"<<L.Search(temp)<<endl;
    temp='f';                 //（7） 在第 4 个元素位置上插入 f 元素
    L.Insert(4,temp);
    L.Remove(3,temp);         //（8） 删除 L 的第 3 个元素
    L.output();               //（9） 输出顺序表 L。
    L.~SeqList();
    return 0;                 //（10） 释放顺序表 L。
}


