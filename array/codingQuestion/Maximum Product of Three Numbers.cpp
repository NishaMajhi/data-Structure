/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:
Input: nums = [1,2,3]
Output: 6


Example 2:
Input: nums = [1,2,3,4]
Output: 24


Example 3:
Input: nums = [-1,-2,-3]
Output: -6


Example 4:
Input: nums = [-100,-98,-1,2,3,4]
Output: 39200
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3)
            return -1;
        
        sort(nums.begin(),nums.end());
        
        int ans = max( (nums[n-1]*nums[n-2]*nums[n-3]) , (nums[0]*nums[1]*nums[n-1]) );
        
        return ans;
    }
};
