/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        // vector<int> result;
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     if(mp.find(target-nums[i]) != mp.end()){
        //         result.push_back(mp[target-nums[i]]);
        //         result.push_back(i);
        //         return result;
        //     }
        //     mp[nums[i]]=i;
        // }
        // return result;
        
        
        
        
        vector<int> result,temp;
        temp=nums;
        int i=0,j=nums.size()-1;
        int x,y;
        sort(temp.begin(),temp.end());
        while(i<j){
            if(temp[i]+temp[j]==target){
                x=temp[i];
                y=temp[j];
                break;
            }
            else if(temp[i]+temp[j]>target){
                j--;
            }
            else
                i++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(x==nums[i])
                result.push_back(i);
            else if(y==nums[i])
                result.push_back(i);
        }
        return result;
    }
};
