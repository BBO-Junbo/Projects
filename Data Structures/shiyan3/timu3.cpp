#include<iostream>
using namespace std;
template <typename T>
class Stack
{
public:
    Stack(int size=100);
    ~Stack();
    void push(T data);
    T pop();
    bool isEmpty()const;
    bool isFull()const;
    int getLength()const;
    void outPut()const;
    int getTop()const{return top;}
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
Stack<T>::~Stack()
{
	delete []pData;
}
int pre(char c)
{
	if (c=='+'||c=='-' ) return 1;  
	else if (c=='*'||c=='/' ) return 2;  
	else return 0;
} 
void calculate (Stack<double> &num,Stack<char> &cha) 
{
	double a=num.pData[num.top];
	num.pop(); 
	double b=num.pData[num.top];
	num.pop();
	char c=cha.pData[num.top];
	cha.pop();
	switch (c)
	{
		case '+' : num.push(b+a); break;
		case '-' : num.push(b-a); break;
		case '*' : num.push(b*a); break; 
		case '/' : num.push(b/a); break; 
	}
}
int main()
{
	Stack<double> num;
	Stack<char> symbol;
	char s[100];
	cin>>s;
	for (int i=0;s[i]!='\0';i++) 
	{
		if (isdigit(s[i]))
		{
			double temp=&s[i];
			num.push(temp);
			while (isdigit(s[i])||s[i]=='.') i++;
			i--;
		}
		else 
		{
			if (symbol.empty()) symbol.push(s[i]);
			else if (s[i]=='(')   symbol.push(s[i]);
			else if (s[i]==')') 
			{
				while (symbol.top()!='(') calculate (num,symbol); 
				symbol.pop();
			}
			else if (pre(s[i])>pre(symbol.top())) symbol.push(s[i]);
			else if (pre(s[i])<=pre(symbol.top())) 
			{
				while (!symbol.empty()&&pre(s[i])<=pre(symbol.top()))  calculate (num,symbol);
				cha.push(s[i]);
			}
		}
	}
	printf ("%.2f\n",num.top());
	num.pop(); 
	cha.pop();

} 
