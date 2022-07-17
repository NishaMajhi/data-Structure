#include<iostream>
using namespace std;

void enqueue(int arr[],int n,int *f,int *r)
{
     int x;
    cout<<endl<<"enter data to enqueued : ";
    cin>>x;
    if((*r)==n-1)
    {
        cout<<endl<<"Queue is full : "<<endl<<endl;
        return ;
    }
    else if((*f)==-1&&(*r)==-1)
    {
       (*f)++;
       (*r)++;
       arr[(*r)]=x;
    }
    else
    {
        (*r)++;
        arr[(*r)]=x;
    }
}

void dequeue(int arr[],int *f,int *r)
{
   if((*f)==-1)
   {
       cout<<endl<<"Queue is empty : "<<endl;
       return ;
   }
   else if((*f)==(*r))
   {
       cout<<endl<<"dequeued element is : "<<arr[(*f)]<<endl<<endl;
       (*f)=(*r)=-1;
   }
   else
   {
       cout<<endl<<"dequeued element is : "<<arr[(*f)]<<endl<<endl;
       (*f)++;
   }
}

void peek(int arr[],int *f)
{
    if((*f)==0)
    {
        cout<<endl<<"Queue is empty : "<<endl;
        return ;
    }
    else
    {
      cout<<endl<<"front element of queue is : "<<arr[(*f)]<<endl<<endl;
    }
}

void display(int arr[],int *f,int *r)
{
    cout<<endl;
    if((*f)==-1&&(*r)==-1)
    {
        cout<<endl<<"queue is empty : "<<endl;
        return ;
    }
    cout<<endl;
    for(int i=(*f);i<=(*r);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

 int main()
{
    int n;
    cout<<"enter array size : ";
    cin>>n;
    int arr[n];

    int front,rear;
    front=rear=-1;
    int choice;
    do
    {
        cout<<"1: enqueue "<<endl<<"2: dequeue"<<endl<<"3: peek"<<endl<<"4: display"<<endl;
        cout<<"enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                enqueue(arr,n,&front,&rear);
                break;
            case 2:
                dequeue(arr,&front,&rear);
                break;
            case 3:
                peek(arr,&front);
                break;
            case 4:
                display(arr,&front,&rear);
                break;
            default:
                cout<<endl<<"invalid choice : "<<endl<<endl;
        }
    }while(choice!=0);
      
    return 0;
}
