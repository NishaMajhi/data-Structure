// remove Duplicate element in a Unsorted Linked List
#include <bits/stdc++.h>
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
// Approach - 1 t.c = O(n^2) s.c = O(1)
// Node* removeDuplicateInUnSortedLL(Node* head)
// {
//      if (head == NULL)
//          return head;

//      Node *curr = head;
//      while(curr != NULL)
//      {
//          Node *temp = curr->next;
//          Node *prev = NULL;
//          while(temp != NULL)
//          {
//              if(curr->data == temp->data)
//              {
//                  prev->next = temp->next;
//                  Node *delNode = temp;
//                  temp = temp->next;
//                  delete delNode;

//              }
//              else{
//                 prev = temp;
//                 temp = temp->next;
//              }
//          }
//          curr = curr->next;
//      }
//      return head;
// }

// using set t.c = O(n) s.c = O(1)
Node *removeDuplicateInUnSortedLL(Node *head)
{
    if (head == NULL)
        return head;

    unordered_set<int> s;
    s.insert(head->data);
    Node *prev = head;
    Node *curr = head->next;
    while (curr != NULL)
    {
        if (s.find(curr->data) != s.end())
        {
            Node *delNode = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete (delNode);
        }

        else
        {
            s.insert(curr->data);
            prev = curr;
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
    
    head = removeDuplicateInUnSortedLL(head);
    print(head);
}

/*
output:-----
enter the initial size of linked list : 10

enter 10 numbers : 3 4 3 4 3 4 1 2 1 2
data of linked list : 3 4 1 2 

*/
