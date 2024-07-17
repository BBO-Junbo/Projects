#include<iostream>
using namespace std;
template <typename T>
class Stack
{
public:
    Stack(int size=100);
    ~Stack(){}
    void push(T data);
    T pop();
    bool isEmpty()const;
    bool isFull()const;
    int getLength()const;
    void outPut()const;
    bool StackRelease();
private:
    T *pData;
    int stackSize;
    int top;
};

template<typename T>
Stack<T>::Stack(int size)
{
    pData=new T[size];
    this->stackSize=size;
    top=-1;
}
template<typename T>
void Stack<T>::push(T data)
{
    if(isFull())
    {   cout<<"Stack is full!"<<endl;
        exit(0);
    }
    else
    {
        top++;
        pData[top]=data;
    }
}
template<typename T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack is empty!"<<endl;
        exit(0);
    }
    else
    {
        T temp=pData[top];
        top--;
        return temp;
    }
}

template<typename T>
bool Stack<T>::isEmpty()const
{
    return top==-1;
}

template<typename T>
bool Stack<T>::isFull()const
{
    return this->stackSize==top-1;
}
template<typename T>
int Stack<T>::getLength()const
{
	return top+1;
}
template<typename T>
void Stack<T>::outPut()const
{
	for(int i=top;i>=0;i--)
	{
		cout<<pData[i]<<" ";
	}
}
template<typename T>
bool Stack<T>::StackRelease()
{
	delete []pData;
	cout<<"Stack has been released!";
}


int main()
{
	char temp;
	Stack <char> S;
	if(S.isEmpty())
		cout<<"Stack is empty!"<<endl;
	else
		cout<<"Stack isn't empty!"<<endl;
	temp='a';S.push(temp);
	temp='b';S.push(temp);
	temp='c';S.push(temp);
	temp='d';S.push(temp);
	temp='e';S.push(temp);
	cout<<"a b c d e "<<"Enter the stack."<<endl;
	cout<<"The length of stack is "<<S.getLength()<<endl;
	S.outPut();cout<<endl;
	S.StackRelease();
	
} 
