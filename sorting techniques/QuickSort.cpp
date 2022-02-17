#include<iostream>
using namespace std;

//int c=0,s=0;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partitions(int arr[],int low ,int high)
{
    int x=low+rand()%(high-low);
    swap(arr[x],arr[high]);
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        //c++;
        if(arr[j]<=pivot)
        {
          //  s++;
             i++;
            swap(arr[i],arr[j]);
        }
    }
        swap(arr[i+1],arr[high]);
       // s++;
        return (i+1);
}


void quickSort(int arr[],int low,int high)
{
    if(low>=high)
    {
        return ;
    }

        int pi=partitions(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    display(arr,n);
   // cout<<"comparisons = "<<c<<endl;
    //cout<<"swap = "<<s<<endl;
    }
    return 0;
}
