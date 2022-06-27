/*
Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 109 + 7.

Example :
1
1 1
1 2 1
1 3 3 1
For N = 3, return 3rd row i.e 1 2 1

Example 1:

Input:
N = 4
Output: 1 3 3 1
Explanation: 4th row of pascal's triangle
is 1 3 3 1.

Example 2:

Input:
N = 5
Output: 1 4 6 4 1
Explanation: 5th row of pascal's triangle
is 1 4 6 4 1.

*/

class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        
        ll m=1000000007;
        vector<vector<ll> > vec;
        for(int i=0;i<n;i++){
           vector<ll> t(i+1,1);
            
            for(int j=1;j<i;j++){
                t[j]=((vec[i-1][j-1])%m + (vec[i-1][j])%m)%m;
            }
            
            if(i == (n-1))
               return t;
               
            vec.push_back(t);
            
        }
        
        return {0};
    }
}
