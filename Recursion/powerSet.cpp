// find all the subset of input array;


/*
example 1:
enter size : 3
1 2 3

3
2
2 3
1
1 3
1 2
1 2 3
count of total subset : 8

*

/
#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int> &arr, vector<vector<int>> &ans, vector<int> temp, int index, int &count1)
{
    // if we reach end of the input array
    if (index >= arr.size())
    {
        ans.push_back(temp);
        count1++;
        return;
    }

   

    // excluding
    powerSet(arr, ans, temp, index + 1, count1);

     // including index element in the temporary vector
    temp.push_back(arr[index]);
    powerSet(arr, ans, temp, index + 1, count1);
}

int main()
{
    int n, count1 = 0;
    cout << "enter size : ";
    cin >> n;
    // create input array and a temp vector for storing result of every subset
    vector<int> arr(n), temp;

    // for storing all subsets
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // call function
    powerSet(arr, ans, temp, 0, count1);

    // print all subsets
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // print total count of subset
    cout << "count of total subset : " << count1 << endl;
}
