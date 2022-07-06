/*
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

example:----
5
1 2 3 4 3
missing is :  5
duplicate is  3


*/

#include <bits/stdc++.h>
using namespace std;
//t.c = s.c = O(n)
vector<int> findMissingDuplicate(vector<int> v, int n)
{
    vector<int> freq(n,0);
    //store frequency of all numbers
    for(int i=0;i<n;i++){
        freq[v[i]]++;
          
    }
    vector<int> ans;
    //finding the missing number 
    for(int i=1;i<=n;i++){
        if(freq[i]==0)
          ans.push_back(i);
    }

    //finding the duplicate number
    for(int i=1;i<=n;i++){
        if(freq[i]>1)
          ans.push_back(i);
    }

    return ans;
}

//t.c = O(n)  s.c = O(1)
vector<int> findMissingDuplicate(vector<int> v, int n)
{
    vector<int> ans;
    int sum = (n * (n + 1)) / 2;  // find sum of all n numbers
    int prod = (n * (n + 1) * (2 * n + 1)) / 6;  // finding square of all n numbers
    int missingNumber = 0, duplicateNumber = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= v[i];
        prod -= v[i] * v[i];
    }

    missingNumber = (sum + prod / sum) / 2;
    duplicateNumber = missingNumber - sum;
    ans.push_back(missingNumber);
    ans.push_back(duplicateNumber);
    return ans;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> ans = findMissingDuplicate(v, n);
    cout << "missing is :  " << ans[0] << endl;
    cout << "duplicate is  " << ans[1];
}
