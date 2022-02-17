#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h)
{
    int s1 = l, s2 = m + 1;
    if (arr[m] <= arr[s2])
        return;
    while (s1 <= m && s2 <= h)
    {
        if (arr[s1] <= arr[s2])
            s1++;
        else
        {
            int val = arr[s2];
            int index = s2;
            while (index != s1)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[s1]=val;
            s1++;
            s2++;
            m++;
        }
    }
}
void inPlaceMmergeSort(int arr[], int l, int h)
{
    int m = (l + h) / 2;
    if (l < h)
    {
        inPlaceMmergeSort(arr, l, m);
        inPlaceMmergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    inPlaceMmergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}