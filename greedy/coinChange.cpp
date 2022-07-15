/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each 
of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2

Explanation: Use one 25 cent coin
and one 5 cent coin


Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 

Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

*/



#include <bits/stdc++.h>
using namespace std;


class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    
	    //greedy solution
	    
	   // int coin=0;
	   // for(int i=0;i<M;i++){
	   //     if(V >= coins[i]){
	   //         V=V-coins[i];
	   //         coin++;
	   //     }
	   // }
	   // if(coin==0)
	   //    return -1;
	   //return coin;
	    
	    
	    
	    //dp solution
	    
	   vector<long> dp(V+1,INT_MAX);
	   dp[0]=0;
	   for(int i=0;i<M;i++){
	       for(int j=1;j<=V;j++){
	           if(j-coins[i]>=0)
	              dp[j]=min(dp[j],1+dp[j-coins[i]]);
	       }
	   }
	   
	   return dp[V]==INT_MAX?-1:dp[V];
	}
	  
};


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
