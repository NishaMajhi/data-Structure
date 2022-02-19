#include <iostream>
using namespace std;

void print(int (&arr)[], int &n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void deleteAtBegining(int (&arr)[], int &n)
{
    for (int i = 0; i < n; i++)
        arr[i] = arr[i + 1];
    n--;
}

void deleteAtEnd(int &n)
{
    n--;
}

void deleteAtPosition(int (&arr)[], int &n, int pos)
{
    if (pos >= n){
        cout << "hello";
        return;
    }
    else
    {
        for (int i = pos - 1; i < n; i++)
            arr[i] = arr[i + 1];
    }
    n--;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pos;
    cin >> pos;
    deleteAtBegining(arr,n);
    print(arr, n);
    deleteAtEnd(n);
    print(arr,n);
    deleteAtPosition(arr, n, pos);
    print(arr, n);
    return 0;
}

/*output:----
6
1 2 3 4 5 6
2
2 3 4 5 6 
2 3 4 5
2 4 5*/
