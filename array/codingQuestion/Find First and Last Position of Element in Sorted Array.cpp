/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]


Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     
        vector<int> ans;
        int n = nums.size();
        int f = -1,l = -1;
        
        //loop for finding first position of target element in sorted array
        int i = 0,j = n-1;
        while(i <= j){
           int mid = (i + j)/2;
           if(nums[mid] == target){
                  f = mid;
                  j = mid-1;
           }
            else if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        
       //loop for finding last position of target element in sorted array
        i = 0; j = n-1;
        while(i <= j){
           int mid = (i + j)/2;
           if(nums[mid] == target){
                   l = mid;
                   i = mid+1;
           }
            else if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }
};
