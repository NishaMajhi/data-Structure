// check whether the array is sorted or not

#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> arr, int index)
{

    // base case
    if (index >= arr.size())
        return true;
    if (arr[index] < arr[index - 1])
        return false;

    return sorted(arr, index + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    bool ans =  sorted(arr, 1);
    cout<<ans;
}
