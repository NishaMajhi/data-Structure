/*
 Implement a stack using an array.
*/

#include<iostream>
using namespace std;

class Stack
{
public :
    int top;
    int n;
    int a[];
    Stack(int x)
    {
        top=-1;
        n=x;
        a[n];
    }
    void push();
    void display();
    void peek();
    void pop();
};

void Stack :: push()
{
    int x;
    cout<<endl<<"enter data to be pushed in stack - ";
    cin>>x;
    cout<<endl;
    if(top>=n-1)
    {
        cout<<"----------overflow condition----------------- "<<endl;
    }
    else{
        top++;
        a[top]=x;
    }
}
void Stack :: peek()
{
    if(top==-1)
    {
        cout<<"---------------underflow  condition-------------"<<endl;
    }
    else{
        cout<<"peek is "<<a[top]<<endl;
    }
}

void Stack :: pop()
{
    if(top==-1)
    {
        cout<<"-------underflow condition------- "<<endl;
    }
    else
    {
        cout<<"******* successfully deleted - "<<a[top]<<endl;
        top--;
    }
}

void Stack :: display()
{
    for(int i=top;i>=0;i--)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl;
}


int main()
{
    int ch,n;
    cout<<"enter stack size ";
    cin>>n;
    Stack s=n;
    do
    {
        cout<<endl<<"1 -> push"<<endl<<"2 -> pop"<<endl<<"3 -> peek"<<endl<<"4 -> display"<<endl;
        cout<<endl<<"enter your choice "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        default :
            cout<<"invalid choice ";
        }
    }while(ch!=0);

    return 0;
}
