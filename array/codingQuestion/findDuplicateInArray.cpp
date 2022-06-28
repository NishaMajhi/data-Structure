/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
*/


//approach 1 t.c=O(nlogn) s.c=O(1)
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}

//approach 2 t.c=O(n) s.c=O(n)
int findDuplicate(vector<int> v){
  map<int,int> freq;
  for(int i=0;i<v.size();i++){
    if(freq[v[i]] == 0)
      freq[v[i]] = 1;
    else
      return v[i];
  }
}

int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  int freq[n + 1] = {0};
  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0) {
      freq[arr[i]] += 1;
    } else {
      return arr[i];
    }
  }
  return 0;
}


//approach 3 t.c=O(n) s.c=O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow  = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
