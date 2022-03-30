/*A celebrity is a person who is known to all but does not know anyone at a party. 
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person.
Here M[i][i] will always be 0.
Note: Follow 0 based indexing.*/

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
output-------
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.
*/
