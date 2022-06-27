/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Example 2:
Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/


#include<bits/stdc++.h>
using namespace std;

/*
//t.c=O(n2)
void sort012(int a[], int n)
{
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
           count0++;
        if(a[i]==1)
           count1++;
        if(a[i]==2)
           count2++;
    }
    
    for(int i=0;i<n;i++){
        while(count0--){
            a[i]=0;
        }
        while(count1--){
            a[i]=1;
        }
        while(count2--){
            a[i]=2;
        }
    }
}
*/

class Solution
{
    //t.c=O(n)
    public:
    void sort012(int a[], int n)
    {       
        int index=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                swap(a[i],a[index++]);
            }
        }
        for(int i=index;i<n;i++){
            if(a[i]==1){
                swap(a[i],a[index++]);
            }
        }
    }
    
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
