#include<iostream>
using namespace std;

int iterativeBinarySearch(int arr[],int l,int r,int key)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
                  r=mid-1;
             else
                l=mid+1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[],int l,int r,int key)
{
    if(r>=l)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
               return recursiveBinarySearch(arr,l,mid-1,key);
             else
                return recursiveBinarySearch(arr,mid+1,r,key);
    }
    return -1;
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"enter array size  : ";
    cin>>n;
    int arr[n];
    cout<<"enter array in sorted form  : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    display(arr,n);
    int key;
    cout<<endl<<"enter key element : ";
    cin>>key;
   // int ans=iterativeBinarySearch(arr,0,n-1,key);
    int ans=recursiveBinarySearch(arr,0,n-1,key);
    if(ans==-1)
        cout<<key<<" not found "<<endl;
    else
        cout<<key<<" found at position : "<<ans+1;
    return 0;

}
