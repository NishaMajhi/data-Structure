//Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

/* 
Input:
S = i.like.this.program.very.much

Output:
much.very.program.this.like.i

Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i*/

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
      
      string s1="", s2="";
      for(int i=0;i<S.length();i++)
      {
          if(S[i] == '.'){
              s1 = "."+s2+s1;
              s2 = "";
          }
          else{
              s2 += S[i];
          }
      }
      return s2+s1;
    }
};
