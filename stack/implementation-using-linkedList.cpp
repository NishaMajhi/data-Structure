#include<iostream>
using namespace std;

class Node
{
   public:
      int data;
      Node *next;
};

void push(Node **top)
{
    int x;
    cout<<endl<<"enter data to be pushed : ";
    cin>>x;
    cout<<endl;
    Node *newNode = new Node();
    newNode->data=x;
    newNode->next=(*top);
    (*top)=newNode;

}

void pop(Node **top)
{
    cout<<endl;
   if((*top)==0)
        cout<<"underflow condition : "<<endl;
   else
   {
       Node *temp=new Node();
       temp=(*top);
       cout<<"deleted element is : "<<temp->data<<endl<<endl;
       (*top)=(*top)->next;
       delete(temp);
   }

}

void peek(Node **top)
{
    cout<<endl;
  if((*top)==0)
    cout<<"underflow condition : "<<endl;
  else
    cout<<"peek element is : "<<(*top)->data<<endl<<endl;

}

void display(Node **top)
{
    cout<<endl;
    if((*top)==0)
        cout<<"underflow condition : "<<endl;
    else
    {
       Node *temp=new Node();
       temp=(*top);
       while(temp!=0)
       {
           cout<<temp->data<<" ";
           temp=temp->next;
       }
    }
    cout<<endl<<endl;

}

int main()
{
    Node *top=0;
    int choice;
    do
    {
        cout<<"1: push"<<endl<<"2: pop"<<endl<<"3: peek"<<endl<<"4: display"<<endl;
        cout<<"enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(&top);
                break;
            case 4:
                display(&top);
                break;
            default:
                cout<<endl<<"invalid choice : "<<endl<<endl;
        }
    }while(choice!=0);
}
