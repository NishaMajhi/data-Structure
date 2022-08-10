/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:
Input: nums = [2,2,1]
Output: 1


Example 2:
Input: nums = [4,1,2,1,2]
Output: 4


Example 3:
Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

*/



// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
        
//         T.C = S.C = O(n)
//         if(nums.size() <= 0)
//             return 0;
        
//         int n = nums.size();
//         vector<int> freq(n,0);
        
//         for(int i=0;i<n;i++){
//             freq[nums[i]]++;
//         }
        
//         for(int i=0;i<n;i++){
//             if(freq[i] == 1)
//                 return i;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        
      //t.c = O(nlogn) s.c = (1)
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
