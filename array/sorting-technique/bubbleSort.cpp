#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    int i=0;
    while(i<n-1)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
        i++;
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"enter size ";
    cin>>n;
    int a[n];
    cout<<"enter array elements :"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    display(a,n);
    
    bubbleSort(a,n);
    
    display(a,n);
    return 0;
}
