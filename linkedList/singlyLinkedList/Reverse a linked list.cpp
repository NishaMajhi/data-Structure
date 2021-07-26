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

void reverseLnkedList(Node **head)
{
    Node *prev=0,*current,*nextNode;
    current=nextNode=(*head);
    while(current!=NULL)
    {
        nextNode=nextNode->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    (*head)=prev;
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

    reverseLnkedList(&head);
    display(head);
    return 0;
}
