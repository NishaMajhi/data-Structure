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


void insertAtBegining(Node **head,int data)
{
    Node *newNode;
    newNode=new Node();
    newNode->data=data;
    newNode->next=(*head);
    (*head)=newNode;
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


int main()
{
    Node *head=NULL,*temp=NULL;
    int choice,data,element;
    do
    {
        cout<<"enter a data to pushed in link list : ";
        cin>>data;
        push(&head,&temp,data);
        cout<<"press 1 for continue : ";
        cin>>choice;
    }while(choice==1);
     display(head);

    cout<<endl<<"enter a element insert in first : ";
    cin>>element;
    insertAtBegining(&head,element);
    display(head);
  return 0;
}
