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
            {cerr<<"�洢�������"<<endl;exit(1);}
    }
}

template<class T>
SeqList<T>::SeqList(SeqList<T>&L){
    maxSize=L.Size();last=L.Length()-1;T value;
    data=new T[maxSize];
    if(data==NULL)
        {cerr<<"�洢�������"<<endl;exit(1);}
    for(int i=1;i<=last+1;i++)
        {L.getData(i,value);data[i-1]=value;}
}
template<class T>
void SeqList<T>::reSize(int newSize){
    if(newSize<=0)
        {cerr<<"��Ч�������С"<<endl;return;}
    if (newSize!=maxSize){
        T *newarray = new T[newSize];
        if (newarray ==NULL)
        {cerr <<"�洢�������!"<< endl;exit(1);}
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
    cout <<"��ʼ����˳������������Ԫ�ظ���";
    while (1){
       cin >> last;
       if (last<=maxSize) break;
       cout <<"����Ԫ�ظ�����������,��Χ���ܳ���"<<maxSize-1<<":";
    }
    for (int i=0;i<last;i++){cout << i+1 <<"  "; cin >> data[i]; }
}
template <class T>
void SeqList<T>::output( ){
    cout <<"˳���ǰԪ�����λ��:"<< last << endl;
    for (int i= 0;i<= last; i++)cout << data[i] <"  ";
    cout << endl;
}
int main()
{
    char temp;
    SeqList<char> L;        //(1)��ʼ�����Ա�L
    L.input();              //(2)���β���β�巨���� a,b,c,d,e Ԫ��
    L.output();             //(3)���˳���L��˳���L�ĳ���
    cout<<"˳���L�ĳ���Ϊ��"<<L.Length()<<endl;
    cout<<"�ж�˳��� L �Ƿ�Ϊ��:";
    if(!L.IsEmpty())
        cout<<"��ǿ�"<<endl;
    else                      //(4)�ж�˳��� L �Ƿ�Ϊ��
        cout<<"���"<<endl;
    L.getData(3,temp);        //(5)���˳��� L �ĵ� 3 ��Ԫ��
    cout<<"���˳��� L �ĵ� 3 ��Ԫ��:"<<temp<<endl;
    temp='d';                //��6�� ���Ԫ�� d ��λ��
    cout<<"Ԫ�� d ��λ��Ϊ"<<L.Search(temp)<<endl;
    temp='f';                 //��7�� �ڵ� 4 ��Ԫ��λ���ϲ��� f Ԫ��
    L.Insert(4,temp);
    L.Remove(3,temp);         //��8�� ɾ�� L �ĵ� 3 ��Ԫ��
    L.output();               //��9�� ���˳��� L��
    L.~SeqList();
    return 0;                 //��10�� �ͷ�˳��� L��
}


