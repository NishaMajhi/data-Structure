#include <iostream>
using namespace std;

void print(int (&arr)[], int &n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertAtBegining(int (&arr)[],int &n,int d)
{
    for(int i=n-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=d;
    n++;
}

void insertAtEnd(int (&arr)[],int &n,int d)
{
    arr[n]=d;
    n++;
}

void insertAtPosition(int (&arr)[],int &n,int d,int pos)
{
    if(pos<0 || pos>n)
      return ;

    else{
       for(int i=n-1;i>pos;i--)
           arr[i+1]=arr[i];
       }
       arr[pos-1]=d;
       n++;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a,b,c,pos;
    cin>>a>>b>>c>>pos;
    insertAtBegining(arr,n,a);
    print(arr,n);
    insertAtEnd(arr,n,b);
    print(arr,n);
    insertAtPosition(arr,n,c,pos);
    print(arr,n);
}

/*
output:----
5
1 2 3 4 5
0 6 9 3
0 1 2 3 4 5     
0 1 2 3 4 5 6   
0 1 9 3 4 4 5 6 */
