/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        if(s.size() == 0 || s.size() == 1)
            return s.size();
//     approach 1 : t.c=O(n^2) s.c=O(n)
      
//         int len=INT_MIN;
//         for(int i=0;i<s.size();i++){
            
//              unordered_set<int> set;
            
//              for(int j=i;j<s.size();j++){
                
//                 if(set.find(s[j]) != set.end()){
//                     len=max(len,(j-i));
//                     break;
//                 }
                
//                 set.insert(s[i]);
                
//             }
//         }
        
//         return len;
        
        
//    approach 2 : t.c=O(2*n) s.c=O(n)
      
        int left=0,len = INT_MIN;
        unordered_set<int> set;
        for(int right=0;right<s.size();right++){
            
            if(set.find(s[right]) != set.end()){
             
                while(left < right && set.find(s[right]) != set.end()){
                   set.erase(s[left]);
                   left++;
                }
            }
            
            set.insert(s[right]);
            len=max(len,(right-left+1));
        }
        
        return len;
    }
};
