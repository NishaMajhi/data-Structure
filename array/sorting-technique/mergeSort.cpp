#include <iostream>
using namespace std;

void Merge(int arr[], int lowerBound, int mid, int upperBound)
{

    int s1 = mid - lowerBound + 1;
    int s2 = upperBound - mid;

    int leftArray[s1];
    for (int i = 0; i < s1; i++)
    {
        leftArray[i] = arr[lowerBound + i];
    }

    int rightArray[s2];
    for (int j = 0; j < s2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = lowerBound;
    while (i < s1 && j < s2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];

            j++;
        }
        k++;
    }

    while (i < s1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < s2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lowerBound, int upperBound)
{
    int mid;
    if (upperBound > lowerBound)
    {

        mid = (lowerBound + upperBound) / 2;
        mergeSort(arr, lowerBound, mid);
        mergeSort(arr, mid + 1, upperBound);
        Merge(arr, lowerBound, mid, upperBound);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        mergeSort(arr, 0, n - 1);
        display(arr,n);
        /*bool c=false;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
                c=true;
                break;
        }
        if(c)

            cout<<" YES "<<endl;
        else

            cout<<" No "<<endl;*/
    }
    return 0;
}
