/*
The cost of stock on each day is given in an array A[] of size N.
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1,
whereas wrong solutions will result in an output of 0.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.


Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.
*/

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int> > vec;
        int i=0,j=1;
        while(A[i]>A[j] && j<n){
            i++;j++;
        }
        while(j<n){
            if(A[j-1]<=A[j]){
                j++;
            }
            else{
                vec.push_back({i,j-1});
                i=j;
                j=i+1;
            }
        }
        if(A[i]<=A[j-1] && i!=(j-1))
           vec.push_back({i,j-1});
           
           return vec;
        
        
    }
};

/*
you are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


#include<bits/stdc++.h>

using namespace std;
int maxProfit(int arr[]) {
  int maxPro = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < 6; i++) {
    minPrice = min(minPrice, arr[i]);
    maxPro = max(maxPro, arr[i] - minPrice);
  }
  return maxPro;
}
int main() {
  int arr[] = {7,1,5,3,6,4};
  int maxPro = maxProfit(arr);
  cout << "Max profit is: " << maxPro << endl;
}
