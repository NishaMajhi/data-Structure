/*
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

 

Example 1:

Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0



Example 2:

Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
 

Constraints:

2 <= nums.length <= 105
-109 <= nums[i] <= 109
1 <= indexDiff <= nums.length
0 <= valueDiff <= 109
*/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        
        //TLE
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(abs(i-j) <= indexDiff && abs(nums[i]-nums[j]) <= valueDiff)
        //             return true;
        //     }
        // }
        // return false;
        
        
        vector<pair<long ,long> > vec;
        //push all data with their index
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        //sort vector based on data
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(vec[i].first-vec[j].first) <= valueDiff){
                    if(abs(vec[i].second - vec[j].second) <= indexDiff)
                        return true;
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};

