/*
You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7



Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;      

        //t.c = (n*n)
        // while(nums.size()>=k){
        //     int maxEle = *max_element(nums.begin(),nums.begin()+k);//O(n) operation
        //     ans.push_back(maxEle);
        //     nums.erase(nums.begin()+0);
        // }
        // return ans;
        
        
        
        //t.c = O(n*k)
        // for(int i=0;i<nums.size()-k+1;i++){
        //     int maxEle = nums[i];
        //     for(int j=i;j<k+i;j++){
        //         maxEle = max(maxEle,nums[j]);
        //     }
        //     ans.push_back(maxEle);
        // }
        // return ans;
        
        
        
        //t.c = O(n) -- in this we are storing element in decreasing order from front od deque
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            //remove all out of index  from front of deque
            if(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            //remove all the indexes from back of deque which are samller then current index element
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            //push cureent index in deque
            dq.push_back(i);
            //if window size in exceed push the value in the ans vector index at deque's front 
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
