//----Reverse a Stack using recursion

//store the top of the stack and pop , 
//reverse the stack and push the stored element untill stack is empty

#include<bits/stdc++.h>
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
void reverse(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();

    reverse(s);
    pushATBottom(s,num);
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
    display(s);
    reverse(s);
    display(s);
}
/*
output----
enter size of stack : 5
enter 5 number
1 2 3 4 5
data of stack
5 4 3 2 1    
data of stack
1 2 3 4 5 
*/
