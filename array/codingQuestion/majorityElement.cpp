/*
 Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
 
 example 1:------------
 Input: nums = [3,2,3]
Output: [3]

Example 2:-------------
Input: nums = [1,2]
Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int,int> mp;
        // vector<int> ans;
        // int size = nums.size();
        // for(int i=0;i<size;i++){
        //    mp[nums[i]]++; 
        // }
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     if((*it).second > (size/3))
        //         ans.push_back((*it).first);
        // }
        // return ans;
        
        
        //moore's algorithm
        int n = nums.size();
        int sz = n;
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++) {
           if (nums[i] == num1)
              count1++;
           else if (nums[i] == num2)
              count2++;
           else if (count1 == 0) {
               num1 = nums[i];
               count1 = 1;
           } else if (count2 == 0) {
               num2 = nums[i];
               count2 = 1;
           } else {
               count1--;
               count2--;
             }
        }
       vector < int > ans;
       count1 = count2 = 0;
       for (i = 0; i < sz; i++) {
          if (nums[i] == num1)
             count1++;
          else if (nums[i] == num2)
             count2++;
       }
       if (count1 > sz / 3)
          ans.push_back(num1);
       if (count2 > sz / 3)
          ans.push_back(num2);
       return ans;
    }
};
