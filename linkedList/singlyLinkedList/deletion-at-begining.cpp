#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
};


void push(Node **head,Node **temp,int data)
{
    Node *newNode;
    newNode= new Node();

    if((*head)==NULL)
        {
             newNode->data=data;
             newNode->next=(*head);
             (*head)=(*temp)=newNode;
        }

    else{
               newNode->data=data;
               newNode->next=NULL;
               (*temp)->next=newNode;
               (*temp)=newNode;
         }
}

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}


void deleteAtBegin(Node **head)
{
    Node *temp;
    temp=(*head);
    (*head)=(*head)->next;
    delete(temp);
}

int main()
{
    Node *head=NULL,*temp=NULL;
    int choice,data,pos;
    do
    {
        cout<<"enter a data to pushed in link list : ";
        cin>>data;
        push(&head,&temp,data);
        cout<<"press 1 for continue : ";
        cin>>choice;
    }while(choice==1);
     display(head);

     deleteAtBegin(&head);
     cout<<endl;
     display(head);
  return 0;
}
