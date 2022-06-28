/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:
Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].

Example 2:
Input:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}
Your Task:
Complete the function overlappedInterval() that takes the list N intervals as input parameters and returns sorted list of intervals after merging.
*/


//Time Complexity: O(N*Log(N)).
//Auxiliary Space: O(Log(N)) or O(N).
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        
         vector<vector<int> >  res;
         if(intervals.size()==0)
            return res;
        sort(intervals.begin(),intervals.end());
         res.push_back(intervals[0]);
         int i=0;
         for(int j=1;j<intervals.size();j++){
             if(res[i][1] >= intervals[j][0]){
                 res[i][1]=max(res[i][1],intervals[j][1]);
             }
             else{
                 i++;
                 res.push_back(intervals[j]);
             }
         }
         return res;
 }

// Time Complexity: O(NlogN)+O(N*N)
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> merge(vector<pair<int, int>> &arr)
{

    vector<pair<int, int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int st = arr[i].first, en = arr[i].second;
        
        if(!res.empty()){
           if(res.back().second >= st){
            continue;
           }
        }

        for(int j=i+1;j<arr.size();j++){
            if(en >= arr[j].first){
                end = arr[j].second; 
            }
        }

        res.push_back({st,en});
    }

    return res;
}

int main()
{
    vector<pair<int, int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<pair<int, int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans)
    {
        cout << it.first << " " << it.second << "\n";
    }
}
