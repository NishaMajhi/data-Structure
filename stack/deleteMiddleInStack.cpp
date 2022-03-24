//delete middle element in stack
#include<bits/stdc++.h>
using namespace std;

void findMid(stack<int> &st,int count,int size)
{
     if(count == size/2)
     {
         st.pop();
         return;
     }

     int num = st.top();
     st.pop();

     findMid(st,count+1,size);
     st.push(num);

     
}
void display(stack<int> st)
{
    cout<<"data of stack -- ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<endl;
}

void getMiddle(stack<int> &st)
{
    int size =st.size();
    int count = 0;
    findMid(st,count,size);
   
}

int main()
{
    stack<int> st;
    int n;
    cout<<"enter stack size : ";
    cin>>n;
    cout<<"enter "<<n<<" data to be push in stack "<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    display(st);
    getMiddle(st);
    display(st);
}

/*
output-------
enter stack size : 6
enter 6 data to be push in stack 
1 2 3 4 5 6
data of stack -- 6 5 4 3 2 1 

data of stack -- 6 5 4 2 1

*/
