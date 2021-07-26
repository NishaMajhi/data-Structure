#include<iostream>
using namespace std;

class Node
{
    public:
       int data;
       Node *next;
};

void push(Node **head,int data)
{
    Node *temp;
    Node *newNode=new Node();
    if((*head)==NULL)
    {
       newNode->data=data;
       newNode->next=(*head);
       (*head)=temp=newNode;
    }
    else
    {
        newNode->data=data;
        newNode->next=NULL;
        temp->next=newNode;
        temp=newNode;
    }
}

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-";
        head=head->next;
    }
}

int listlength(Node *head)
{
    Node *current=head;
    int cnt=0;
    while(current->next!=NULL)
    {
        cnt++;
        current=current->next;
    }
    return cnt;
}

int main()

{
    Node *head=NULL;
    int choice, data;
    do
    {
        cout<<"enter data : ";
        cin>>data;
        push(&head,data);
        cout<<"press 1 for continue : ";
        cin>>choice;

    }while(choice==1);

    display(head);
    cout<<endl;

    int cnt=listlength(head);
    cout<<cnt+1;
  
    return 0;
}
