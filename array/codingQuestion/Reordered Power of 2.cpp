/*
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:
Input: n = 1
Output: true


Example 2:
Input: n = 10
Output: false
 

Constraints:
1 <= n <= 109
*/


class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        //we convert the number into string as we want to sort the number in ascending order
        string str = to_string(n);
        sort(str.begin(),str.end());

       //now we find number of power of two(2) and store in string vector as we want to sort in ascending order  
        //10^9 = 2^30  
        vector<string> v;
        for(int i=0;i<=30;i++){
            int p = pow(2,i);
            v.push_back(to_string(p));
        }

        // sort each string of vector
        for(int i=0;i<v.size();i++){
            sort(v[i].begin(),v[i].end());
        }

        // we check if any string is same as input number return true
        for(int i=0;i<v.size();i++){
            if(str == v[i])
               return true;
        }
        
       //otherwise return false
        return false;

    }
};
