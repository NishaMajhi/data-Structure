/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

 

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.



Example 2:
Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/


class Solution {
public:
    vector<int> nextSmallerElementIndex(vector<int>& heights,int n){
        stack<int> st;
        vector<int> res(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> prevSmallerElementIndex(vector<int>& heights,int n){
        stack<int> st;
        vector<int> res(n);
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //Storing next smaller element index
        vector<int> next=nextSmallerElementIndex(heights,n);
        //Storing prev smaller element index
        vector<int> prev=prevSmallerElementIndex(heights,n);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            ans=max(ans,l*b);
        }
        return ans;
    }
};
