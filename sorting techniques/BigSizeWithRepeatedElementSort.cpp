// sorting of a big size array with repeated element

#include <bits/stdc++.h>
using namespace std;
void RSort(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int index = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        while ((it->second)--)
        {
            arr[index++] = it->first;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    RSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
