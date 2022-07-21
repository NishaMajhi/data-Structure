/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        //preSum for storing the left most boundary of ith element
        int preSum[n];
        
        //sufSum for storing the right most boundary of ith element
        int sufSum[n];
        
        //storing the left most boundary of ith element
        preSum[0]=height[0];
        for(int i=1;i<n;i++){
            preSum[i]=max(preSum[i-1],height[i]);
        }
        
        //storing the right most boundary of ith element
        sufSum[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufSum[i]=max(sufSum[i+1],height[i]);
        }
        
        int totalWater = 0;
        
        //calculate total water by reducing the height of current elements height by finding              the min boundary
        for(int i=0;i<n;i++){
            totalWater += min(preSum[i],sufSum[i]) - height[i];
        }
        
        //RETURN TOTAL WATER
        return totalWater;
    }
};
