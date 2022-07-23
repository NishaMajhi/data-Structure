/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of
candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency
of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]


Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/

class Solution {
public:
    
    void findCombination(vector<int>& candidates,int ind,int target,
                         vector<vector<int>> &ans,vector<int> &ds){
        
        //if we reached at the end of the array and target become 0 then we will add the  vector in the resultant vector
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
             return;
        }
        
        
        //for picking an element
        if(candidates[ind] <= target){
            
            //insert the element in the vector
            ds.push_back(candidates[ind]);
            
            //again call the function after reducing the target by value of candidates[ind] for next getting next elements
            findCombination(candidates,ind,target-candidates[ind],ans,ds);
            
          
            //if we got the target pop the last element that we added in the vector , for getting next possible combinations
            
            //and if we dont get the target by adding last element in the vector then pop the last element that the added in the vector because we want to try for next                     element in order to get target
            ds.pop_back();
        }
        
        //for not picking an element
         findCombination(candidates,ind+1,target,ans,ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        //create resultant vector
        vector<vector<int> > ans;
        
        //create temporary vector that hold the element that produce the sum evert time
        vector<int> v;
        
        findCombination(candidates,0,target,ans,v);
        
        return ans;
    }
};
