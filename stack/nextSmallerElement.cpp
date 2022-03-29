//find next greater element in the array
#include<bits/stdc++.h>
using namespace std;

void nextSmallerElement(int arr[], int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }

        // we found smaller than current array element
        ans[i] = s.top();
        //push the current element in the satck
        s.push(curr);
    }
   
    cout<<"next smaller elements"<<endl;
    for(int i=0; i<n; i++)
     cout<<ans[i]<<" ";

    cout<<endl;
}
int main()
{
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" number"<<endl;
    for(int i = 0; i<n; i++)
      cin>>arr[i];
    nextSmallerElement(arr,n);

}
/*
output----
enter size of array : 5
enter 5 number
2 5 1 0 9
next smaller elements
1 1 0 -1 -1 
*/
