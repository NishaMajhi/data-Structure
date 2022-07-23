/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 
Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]


Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
    public:
    
    //create resultant vector
   vector<vector<int>> res;
    
    //create set of vector for avoiding duplicacy
    set<vector<int>> s;
    
    void backtrack(vector<int> &nums,int idx,vector<int> &v)
    {
        //if we reach at the end of the array
        if(idx>=nums.size())
        {
            //we check whether the vector is already present or not
            if(!s.count(v))
            {
                //if not then insert into the resultant vector
                res.push_back(v);
                //insert into the set also for future checking
                s.insert(v);
            }
            return;
        }
        
        //push the element
        v.push_back(nums[idx]);
        
        //againg call the function
        backtrack(nums,idx+1,v);
        
        //pop out the last element if is not making current answer or made current answer
        v.pop_back();
        
        //again call
        backtrack(nums,idx+1,v);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        //sort the input array so that all duplicant will be adjacent
        sort(nums.begin(),nums.end());
        
        //create temporary vector that have the elements at every subset
        vector<int> v;
        
        backtrack(nums,0,v);
        
        return res;
        
    }
};
