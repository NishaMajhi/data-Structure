#include<iostream>
using namespace std;

void selectionSort(int a[],int n,int &c,int &s)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(a[minIndex]>a[j])
                minIndex=j;
                c++;
        }

        int t=a[i];
        a[i]=a[minIndex];
        a[minIndex]=t;
        s++;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int i,n,c=0,s=0;
       cin>>n;
       int a[n];
       for(i=0;i<n;i++)
         {
            cin>>a[i];
         }

      selectionSort(a,n,c,s);
        for(i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }
       cout<<endl;
       cout<<" comparisons = "<<c<<endl;
       cout<<" Swap = "<<s<<endl;
    }
    return 0;
}
