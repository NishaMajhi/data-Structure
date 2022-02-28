// Split a cirular Linked List into Two Halves
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

void print(Node *head)
{
    cout << "data of linked list : ";
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
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

void splitLikedList(Node *head, Node **head1, Node **head2)
{
    Node *fast = head, *slow = head, *e = NULL;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next == head)
        e = fast;
    if (fast->next->next == head)
        e = fast->next;

    Node *st = slow->next;
    *head1 = head;
    slow->next = head;
    *head2 = st;
    e->next = st;
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
    tail->next = head;
    print(head);

    Node *head1, *head2;
    head1 = NULL;
    head2 = NULL;

    splitLikedList(head, &head1, &head2);
    cout << "first half : ";
    print(head1);
    cout << endl
         << "second half : ";
    print(head2);
}

/*
output:--------

enter the initial size of linked list : 6

enter 6 numbers : 1 2 3 4 5 6
data of linked list : 1 2 3 4 5 6         
first half : data of linked list : 1 2 3  

second half : data of linked list : 4 5 6 





enter the initial size of linked list : 7

enter 7 numbers : 1 2 3  4  5 6 7
data of linked list : 1 2 3 4 5 6 7 
first half : data of linked list : 1 2 3 4

second half : data of linked list : 5 6 7
*/
