#include<iostream>
using namespace std;
template <typename T>
class Queue{
public:
    Queue(int maxsize=100);
    ~Queue(){}
    void enQueue(T data);
    T deQueue();
    bool isEmpty()const;
    bool isFull()const;
    int getSize()const{return size;}
    void outPut()const;
    bool QueueRelease();
private:
    T *pData;
    int MAXSIZE;
	int size;
    int QueueSize;
    int front;
    int rear;
    
};
template <typename T>
Queue<T>::Queue(int maxsize){
	pData=new T[maxsize];
    this->size=0;
    this->MAXSIZE=maxsize;
    this->front=this->rear=0;
}
template <typename T>
void Queue<T>::enQueue(T data)
{
	if (this->isFull()){
		cout<<"Queue is full!"<<endl;
	}
	this->pData[this->rear]=data;		
	this->rear=(this->rear + 1)%MAXSIZE;    
	this->size++;	
}
template<typename T>
T Queue<T>::deQueue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty!"<<endl;
        exit(0);
    }
    else
    {
        T temp=pData[front];
        this->front=(this->front+1)%MAXSIZE;
        return temp;
    }
}
template<typename T>
bool Queue<T>::isEmpty()const
{
    return this->size==0;
}
template<typename T>
bool Queue<T>::isFull()const
{
    return (this->rear+1)%MAXSIZE==this->front;
}
template<typename T>
void Queue<T>::outPut()const
{
	cout<<"The elements in the current queue are£º" ;
	for(int i=this->front;i<this->rear;i++)
		cout<<pData[i]<<' ';
	cout<<endl;
		
}
template<typename T>
bool Queue<T>::QueueRelease()
{
	delete []pData;
	cout<<"Queue has been released!";
}
int main()
{
	Queue<char> Q;
	char temp;
	if(Q.isEmpty())
		cout<<"Queue is empty!"<<endl;
	else
		cout<<"Queue isn't' empty!"<<endl;
	temp='a';Q.enQueue(temp);
	temp='b';Q.enQueue(temp);
	temp='c';Q.enQueue(temp);
	cout<<"a b c "<<"Enter the queue."<<endl;
	Q.outPut();
	cout<<Q.deQueue()<<" exits the queue."<<endl;
	cout<<"There are "<<Q.getSize()<<" elements in the Queue."<<endl;
	temp='d';Q.enQueue(temp);
	temp='e';Q.enQueue(temp);
	temp='f';Q.enQueue(temp);
	cout<<"d e f "<<"Enter the queue."<<endl;
	Q.outPut();
	Q.QueueRelease();
}

