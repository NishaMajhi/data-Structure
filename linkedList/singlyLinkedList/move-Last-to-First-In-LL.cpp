// Move last element to front of a given Linked List
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

Node *moveLastToirst(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    curr->next = head;
    head = curr;
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
    //for(int i=0;i<2;i++)       //for rotating n times 
    head = moveLastToirst(head);
    print(head);
}

/*
output:--------
enter the initial size of linked list : 10

enter 10 numbers : 1 2 3 4 5 6  7 8 9 10
data of linked list : 10 1 2 3 4 5 6 7 8 9 
*/
