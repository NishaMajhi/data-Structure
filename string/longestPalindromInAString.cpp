/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, 
return the substring which occurs first ( with the least starting index).

Input:
S = "aaaabbaa"
Output: aabbaa

Explanation: The longest Palindromic
substring is "aabbaa".

*/

string longestPalin (string S) {
        int start = 0;
        int end = 1;
        int low , high;
        for(int i = 1;i<S.length();i++){
            //even part
            low = i-1;
            high = i;
            while(low >= 0 && high <= S.length() && S[low] == S[high]){
                if(high - low + 1 >end){
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }
            
            //odd part
            low = i-1;
            high = i+1;
            while(low >= 0 && high <= S.length() && S[low] == S[high]){
                if(high - low + 1 >end){
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }
        }
        
        return S.substr(start,end);
    }
