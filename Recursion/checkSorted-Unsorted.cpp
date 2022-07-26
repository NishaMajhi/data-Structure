// check whether the array is sorted or not


/*
example 1:
5
1 2 3 4 5
1


example 2:
5
1 3 2 4 5
0

*/


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
