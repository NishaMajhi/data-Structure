/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/




#include<iostream>
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
        cout << temp->data << " ";
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

Node *RecursiveReverse(Node* head)
{
     //recursive approach
   if(head == NULL || head->next == NULL)
      return head;

   Node *temp = RecursiveReverse(head->next);
   head->next->next = head;
   head ->next = NULL;

   return temp;
}

void IterativeReverse(Node* &head)
{
   //iterative approach
   if(head == NULL || head->next == NULL){
      return;
   }

   Node* cur = head;
   Node* prev = NULL;
   Node* next = NULL;
   while(cur != NULL)
   {
       next = cur->next;  // storing next address
       cur->next = prev;  //assining previous address to cur->next 
       prev = cur;
       cur = next;
   }

    head = prev;
  
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
    IterativeReverse(head);
    print(head);
    head = RecursiveReverse(head);
    print(head);
}

/*
output:--

enter the initial size of linked list : 8

enter 8 numbers : 1 2 3 4 5 6 7 8
data of linked list : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 
data of linked list : 8 <- 7 <- 6 <- 5 <- 4 <- 3 <- 2 <- 1 <- 
data of linked list : 1 <- 2 <- 3 <- 4 <- 5 <- 6 <- 7 <- 8 <- 

*/
