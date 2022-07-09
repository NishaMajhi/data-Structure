/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}

Output: 5

Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n,
where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
using namespace std;

//t.c=s.c=O(n)
int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    int len = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            len = i + 1;
        }
        else if (mp.find(sum) != mp.end())
        {
            len = max(len, i - mp[sum]);
        }
        else
            mp[sum] = i;
    }
    return len;
}
//t.c=O(n^2)  s.c=O(1)
int maxLen(vector<int> v)
{
    sort(v.begin(), v.end());
    int len = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == 0)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main()
{
    vector<int> v = {9, -3, 3, -1, 6, -5};
    cout << maxLen(v) << endl;
    return 0;
}
