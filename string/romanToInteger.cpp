/*
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000


Input:
s = V
Output: 5

*/

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int res = mp[str[str.length()-1]];
        
        for(int i=str.length()-2;i>=0;i--){
            if(mp[str[i]] < mp[str[i+1]]) 
               res -= mp[str[i]];
             else
                res += mp[str[i]];
        
        }
        
        return res;
    }
};
