#include<iostream>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partitions(int arr[],int low ,int high)
{
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            Swap(&arr[i],&arr[j]);
            i++;
        }
    }
        Swap(&arr[i],&arr[high]);

    return (i);
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partitions(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main()
{
    int n;
    cout<<"enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"enter array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    display(arr,n);
    quickSort(arr,0,n-1);

    display(arr,n);

    return 0;
}
