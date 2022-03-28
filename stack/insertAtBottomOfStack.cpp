//---------push a element in the bottom of the stack-----

//store the top element of the stack and pop untill bottom of the stack 
//after reaching bottom insert the element and than push the storing element into the stack

#include <bits/stdc++.h>
using namespace std;

void display(stack<int> s)
{
    cout<<"data of stack"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void pushATBottom(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    pushATBottom(s,x);
    s.push(num);

}



int main()
{
    stack <int> s;
    int n;
    cout<<"enter size of stack : ";
    cin>>n;
    cout<<"enter "<<n<<" number"<<endl;
    while(n--)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    int x;
    cout<<"enter a element at the bottom of the stack : ";
    cin>>x;
    display(s);
    pushATBottom(s,x);
    display(s);
}
/*
output---
enter size of stack : 4
enter 4 number
1 2 3 4
enter a element at the bottom of the stack : 5
data of stack
4 3 2 1      
data of stack
4 3 2 1 5    
*/
