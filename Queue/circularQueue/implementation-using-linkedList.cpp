#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node *next;
};

void enqueue(Node **f,Node **r)
{
    int x;
    cout<<endl<<"enter data : ";
    cin>>x;
    cout<<endl;
    Node *newNode=new Node();
    newNode->data=x;
    newNode->next=0;
    if((*r)==0)
    {
        (*f)=(*r)=newNode;
        (*r)->next=(*f);
    }
    else
    {
        (*r)->next=newNode;
        (*r)=newNode;
        (*r)->next=(*f);
    }

}

void dequeue(Node **f,Node **r)
{
    Node *t=new Node();
    t=(*f);
    if((*f)==0&&(*r)==0)
    {
        cout<<endl<<"Queue is empty : "<<endl<<endl;
    }
    else if((*f)==(*r))
    {
        cout<<endl<<"dequeued element is : "<<(*f)->data<<endl;
        (*f)=(*r)=0;
        delete(t);
    }
    else
    {
       cout<<endl<<"dequeued element is : "<<(*f)->data<<endl;
       (*f)=(*f)->next;
       (*r)->next=(*f);
       delete(t);
    }
}

void peek(Node **f)
{
    if((*f)==0)
    {
        cout<<endl<<"queue is empty : ";
    }
    else
    {
        cout<<endl<<"front element of queue is : "<<(*f)->data<<endl<<endl;
    }
}

void display(Node **f)
{
    if((*f)==0)
    {
        cout<<endl<<"queue id empty : ";
    }
    else
    {
        cout<<endl;
        Node *t=new Node();
        t=(*f);
        while(t->next!=(*f))
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<t->data;
    }cout<<endl<<endl;
}
 int main()
{
    Node *front=new Node();
    Node *rear=new Node();
    front=rear=0;
    int choice;
    do
    {
        cout<<"1: enqueue "<<endl<<"2: dequeue"<<endl<<"3: peek"<<endl<<"4: display"<<endl;
        cout<<"enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                enqueue(&front,&rear);
                break;
            case 2:
                dequeue(&front,&rear);
                break;
            case 3:
                peek(&front);
                break;
            case 4:
                display(&front);
                break;
            default:
                cout<<endl<<"invalid choice : "<<endl<<endl;
        }
    }while(choice!=0);

    delete(front);
    delete (rear);
    return 0;
}
