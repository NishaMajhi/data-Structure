//remove Duplicate element in a sorted Linked List

#include<bits/stdc++.h>
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

Node* removeDuplicateInSortedLL(Node* head)
{
     Node *curr = head;
     while(curr != NULL)
     {
         if((curr->next != NULL) && (curr->data ==  curr->next->data))
         {
             Node *nextNode = curr->next->next;
             Node * nodeToDelete  = curr->next;
             nodeToDelete->next = NULL;
             delete nodeToDelete;
             curr->next =  nextNode;
         }
         else{
             curr = curr->next;
         }
     }
     return head;
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
    head = removeDuplicateInSortedLL(head);
    print(head);

}

/*
output:--------

enter the initial size of linked list : 6

enter 6 numbers : 1 2 3 3 3 4 5
data of linked list : 1 2 3 3 3 4 
data of linked list : 1 2 3 4 

*/
