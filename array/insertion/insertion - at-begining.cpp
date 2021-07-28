#include<iostream>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[20];
    int n;
    cout<<"enter size ";
    cin>>n;
    cout<<"enter array element : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int element;
    cout<<"enter data to be insert at begining : ";
    cin>>element;
    for(int i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    n++;
    arr[0]=element;

    display(arr,n);
    return 0;
}
