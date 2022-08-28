/*
Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums. 

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]


Example 2:
Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        
        int n = nums.size();
        if(!n)
            return ans;
        
        int freq[100001] = {0};
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
