/*
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}

Output: 180

Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long l=1,r=1,mProd=INT_MIN;
	    for(int i=0;i<n;i++){
	          l=l*arr[i];
	          r=r*arr[n-1-i];
	          mProd=max(mProd,max(l,r));
	          if(l==0)
	             l=1;
	          if(r==0)
	              r=1;
	          
	    }
	    
	    return mProd;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
