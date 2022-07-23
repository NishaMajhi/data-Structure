/*

Given a list arr of N integers, print sums of all subsets in it.

Example 1:

Input:
N = 2
arr[] = {2, 3}

Output:
0 2 3 5

Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.


Example 2:

Input:
N = 3
arr = {5, 2, 1}

Output:
0 1 2 3 5 6 7 8

Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer 
N as an input parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
*/

#include<bits/stdc++.h> 
using namespace std; 


class Solution
{
   
public:
    
    void sums(vector<int> &arr,int left,int right,int sum,vector<int> &ans){
        
        //if index goes out of arr.size then push the sum in  the ans vector
        if(left>right){
            ans.push_back(sum);
            return;
        }
        
        //including the number
        sums(arr,left+1,right,sum+arr[left],ans);
        
        //excluding the number
        sums(arr,left+1,right,sum,ans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        //create answer vector
        vector<int> ans;
        
        //find all subset sums
        sums(arr,0,N-1,0,ans);
        
        //sort all the subset sums
        sort(ans.begin(),ans.end());
        
        //return the answer
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
