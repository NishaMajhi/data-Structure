//--------Sort stack------------

//if the stack is empty return
//otherwise store top of the stack and pop and fill the stored number in a sorted manner
//sorted manner -> if the stack is empty or top of the stack is less than element than push into the stack
//otherwise store top of the stack and pop and call sortedmanner function recursively , push the element top of the stack 

#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s)
{
    cout<<"data of stack : ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void pushInSortedManner(stack<int> &s,int num)
{
    if(s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }

    int n=s.top();
    s.pop();

    pushInSortedManner(s,num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);

    pushInSortedManner(s,num);
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
    sortStack(s);
    display(s);
}

/*
output------
enter size of stack : 5
enter 5 number
1 -4 5 10 -20
data of stack : -20 10 5 -4 1 
data of stack : 10 5 1 -4 -20 
*/
