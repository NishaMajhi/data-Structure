/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/



class Solution {
public:
    
    bool ifExists(char i,char j){
       if(i == '(' &&  j == ')') 
           return true;
       if(i == '{' &&  j == '}')
            return true;
       if(i == '[' &&  j == ']') 
            return true;
        
       return false;
    }
    
    bool isValid(string s) {
        
        int n = s.size();
        
        stack<char> st;
        
        for(int i=0;i<n;i++){
            
           char ch = s[i];
            
            if(ch == '(' ||  ch == '{' ||  ch == '[')
                st.push(ch);
            
            else{
                if(!st.empty() && ifExists(st.top() , ch) == true){
                    st.pop();
                }                    
                else
                    return false;
            }
        }
        if(st.empty())
           return true;
        
        return false;
    }
};
