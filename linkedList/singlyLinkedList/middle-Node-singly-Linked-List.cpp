#include <iostream>
using namespace std; 

class Node
{
public:
    int data;
    Node *next;
};

Node *create(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void print(Node *&head)
{
    cout << "data of linked list : ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void push(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        head = create(d);
        tail = head;
    }
    else
    {
        tail->next = create(d);
        tail = tail->next;
    }
}

Node* middleNode(Node* &head)
{
     //approach 1
   //base cases
   if(head == NULL || head->next == NULL)
       return head;
   if(head->next->next == NULL)
       return head->next->next; 
  
   //finding length of LL
   int len = 0;
   Node *temp = head;
   while(temp != NULL){
       len++;
       temp = temp->next;
   }

   //remaining Algorithm
   int mid = (len/2) ;
   Node* cur = head;
   while(mid--){
       cur = cur->next;
   }

   return cur;

   //approach 2 more optimise
    // base cases
    // if(head == NULL || head->next == NULL)
    //    return head;
    // if(head->next->next == NULL)
    //    return head->next->next;
    
    
    // Node *forward = head->next;
    // Node *backward = head;
    // while(forward != NULL){
    //     forward = forward->next;
    //     if(forward != NULL){
    //          forward = forward->next;
    //     }
    //     backward = backward->next;
    // }

    // return backward;
}

int main()
{
    Node *head, *tail;
    head = tail = NULL;

    // creating initial nodes in Linked List
    int n;
    cout << "enter the initial size of linked list : ";
    cin >> n;
    cout << endl
         << "enter " << n << " numbers : ";
    while (n--)
    {
        int d;
        cin >> d;
        push(head, tail, d);
    }
    print(head);
    Node *temp = middleNode(head);
    cout<<"Middle element =  "<<temp->data<<endl;

}
/*
outout:-----
enter the initial size of linked list : 8 // for even length

enter 8 numbers : 1 2 3 4 5 6 7 8
data of linked list : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 
Middle element =  5


enter the initial size of linked list : 7 //for odd length

enter 7 numbers : 1 2 3 4 5 6 7 
data of linked list : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 
Middle element =  4
*/
