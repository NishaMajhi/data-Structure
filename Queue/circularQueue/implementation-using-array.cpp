#include<iostream>
using namespace std;

void enqueue(int arr[],int n,int *f,int *r)
{
     int x;
    cout<<endl<<"enter data to enqueued : ";
    cin>>x;
    cout<<endl;
    if((*f)==-1&&(*r)==-1)
    {
       (*f)=(*r)=0;
       arr[(*r)]=x;
    }
   else if(((*r)+1)%n==(*f))
    {
        cout<<endl<<"Circular Queue is full : "<<endl<<endl;
        return ;
    }
    else
    {
        (*r)=((*r)+1)%n;
        arr[(*r)]=x;
    }
}

void dequeue(int arr[],int n,int *f,int *r)
{
   if((*f)==-1&&(*r)==-1)
   {
       cout<<endl<<"Circular Queue is empty : "<<endl;
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
       (*f)=((*f)+1)%n;
   }
}

void peek(int arr[],int *f)
{
    cout<<endl<<"front element of queue is : "<<arr[(*f)]<<endl<<endl;
}

void display(int arr[],int n,int *f,int *r)
{
    cout<<endl;
    if((*f)==-1&&(*r)==-1)
    {
        cout<<endl<<"Circular Queue is empty : "<<endl<<endl;
         return ;
    }

   else if((*r)>=(*f))
    {
        for(int i=(*f);i<=(*r);i++)
            cout<<arr[i]<<" ";
    }

    else
    {
        for(int i=(*f);i<n;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=(*r);i++)
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
                dequeue(arr,n,&front,&rear);
                break;
            case 3:
                peek(arr,&front);
                break;
            case 4:
                display(arr,n,&front,&rear);
                break;
            default:
                cout<<endl<<"invalid choice : "<<endl<<endl;
        }
    }while(choice!=0);

    return 0;
}
