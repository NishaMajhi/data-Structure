#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n,int &c,int &shift)
{
    for(int i=1;i<n;i++)
    {
        int j;
        int key=arr[i];
        j=i-1;
        while(j>=0&&key<arr[j])
        {
            c++;
            arr[j+1]=arr[j];
            j--;
            shift++;
        }
        arr[j+1]=key;
        shift++;
    }
}
void display(int arr[],int n)
{
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,c=0,s=0;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)
        {
           cin>>arr[i];
        }
    InsertionSort(arr,n,c,s);
    cout<<" Comparisons = "<<c<<endl;
    cout<<" Shift = "<<s<<endl;
    }
    return 0;
}
