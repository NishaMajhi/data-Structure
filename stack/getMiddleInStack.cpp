#include<bits/stdc++.h>
using namespace std;

int findMid(stack<int>st,int count,int size)
{
     if(count == size/2)
     {
         return st.top();
     }

     int num = st.top();
     st.pop();

     int ans = findMid(st,count+1,size);
     st.push(num);

     return ans;
}

int getMiddle(stack<int> st)
{
    int size =st.size();
    int count = 0;
    int ans = findMid(st,count,size);
    return ans;
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
    cout<<"middle element in stack : "<<getMiddle(st);
}
