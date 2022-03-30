/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
*/
#include <bits/stdc++.h>
using namespace std;

/*
// Approach 1 - T.C-O(n^2) S.C-O(n)
bool knows(vector<vector<int>> v, int a, int b)
{
    return v[a][b];
}
int celebrity(vector<vector<int>> &v, int n)
{
    int zeroCount[n] = {0};
    int oneCount[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = knows(v, i, j);
            zeroCount[i] += x;
            oneCount[j] += x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((zeroCount[i] == 0) && ( oneCount[i] = n - 1))
            return i;
    }

    return -1;
}*/

//Approach 2 T.C = S.C = O(n)
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step 1 - push all the indexes into the Stack 
        for(int i=0;i<n;i++)
           s.push(i);
        //step 2 - get 2 element from stack and compare
        while(s.size()>1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b] == 1)
               s.push(b);
            else
               s.push(a);
        }
        //possible answer
        int ans = s.top();
        
        //step 3 - check zero count in Rows for possible answer
        int zeroCount = 0;
        for(int i=0;i<n;i++)
        {
            if(M[ans][i] == 0)
                 zeroCount++;
        }
        
        if(zeroCount != n)
           return -1;
         
        //step 4 - check one count in columns for possible answer
        int oneCount = 0;
        for(int i=0;i<n;i++)
        {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
            
        //step 5 return answer
        return ans;
    }

/*
// Approach 3 T.C-O(n) S.C-O(1)
int celebrity(vector<vector<int>> v, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[j][i] == 1) // j know i
            j--;
        else // j does not know i
            i++;
    }
    int candidate = i;
    for (int i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (v[candidate][i] == 1 || v[i][candidate] == 0)
                return -1;
        }
    }
    return candidate;
}
*/
int main()
{
    vector<vector<int>> v;
    int n;
    cout << "enter vector size : ";
    cin >> n;
    cout << "enter " << n * n << " data" << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            t.push_back(x);
        }
        v.push_back(t);
    }

    cout << "celebrity : " << celebrity(v, n);
}

/*
output-------
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.
*/
