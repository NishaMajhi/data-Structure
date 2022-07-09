/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{

    // approach 1 t.c=O(nlogn) s .c=O(1)
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int count = 1, maxlen = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
            count++;
        else
            count = 1;

        maxlen = max(maxlen, count);
    }
    return maxlen;

    // approach 1 t.c=O(n) s .c=O(n)
    //  unordered_set<int> hashSet;
    //  for (int num : nums)
    //  {
    //      hashSet.insert(num);
    //  }

    // int len = 0;

    // for (int num : nums)
    // {
    //     if (!hashSet.count(num - 1))
    //     {
    //         int currentNum = num;
    //         int count = 1;

    //         while (hashSet.count(currentNum + 1))
    //         {
    //             currentNum += 1;
    //             count += 1;
    //         }

    //       len = max(len, count);
    //     }
    // }

    // return len;
}

int main()
{
    vector<int> v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(v) << endl;
    return 0;
}
