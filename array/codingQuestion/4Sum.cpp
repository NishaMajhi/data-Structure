/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/


class Solution {
public:
    
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
        
//         sort(nums.begin(),nums.end());
      
//        set<vector<int>> sv;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
    
//                 for(int k=j+1;k<n;k++)
//                 { 
                  
//                    int x = (long long)target - 
//                            (long long)nums[i]-
//                            (long long)nums[j]-(long long)nums[k];
                   
//                         if(binary_search(nums.begin()+k+1,nums.end(),x)){
//                             vector<int> v;
//                             v.push_back(nums[i]);
//                             v.push_back(nums[j]);
//                             v.push_back(nums[k]);
//                             v.push_back(x);
//                             sort(v.begin(),v.end());
//                             sv.insert(v);
//                         }
//                 }
//             }
//         }
//         vector<vector<int>> res(sv.begin(),sv.end());
//         return res;
//     }
// };
    
   vector<vector<int>> fourSum(vector<int>& v, int t) {
              
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(), v.end());
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long long req = (long long)t - (v[i] + v[j]);
                int low = j+1, high = n-1;
                
                while(low < high) {
                    int curr = v[low] + v[high];
                    if(curr > req) high--;
                    else if(curr < req) low++;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = v[i];
                        quadruplet[1] = v[j];
                        quadruplet[2] = v[low];
                        quadruplet[3] = v[high];
                        ans.push_back(quadruplet);
                        
                        while(low < high && v[low] == quadruplet[2]) ++low;
                        while(low < high && v[high] == quadruplet[3]) --high;
                    }
                }
                
                while(j+1<n && v[j] == v[j+1]) ++j;
                
            }
            
            while(i+1<n && v[i] == v[i+1]) ++i;
        }
        
        return ans;
       
       
    }
};
