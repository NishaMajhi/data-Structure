/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.
 


Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"



Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"



Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/


class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;

        // declared an empty string
        string ans = "";

        // traversing the num1 and num2 string till the leftmost digit
        // and till carry > 0
        while(i>=0 || j>=0 || carry){
            //declared an int var sum and assigned 0 to it
            long sum = 0;

            // convert the char to int and add it to sum variable
            if(i>=0){
                sum+=num1[i]-'0';
                i--;
            }

            // similarily convert the char to int and it to sum var
            if(j>=0){
                sum+=num2[j]-'0';
                j--;
            }

            sum+=carry;
            carry=sum/10;
            sum = sum%10;
            
            /* concatenate the last digit of the sum after converting 
             it into string using to_string function */ 
            ans+=to_string(sum);
        }

        /* as the required sum is obtained in the reverse manner , 
         reverse the sum to obtain the actual answer */
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
