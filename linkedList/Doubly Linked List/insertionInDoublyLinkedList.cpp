#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node *next;
};

Node *create(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = newNode->prev = NULL;
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
        Node* t = create(d);
        t->prev = tail;
        tail->next = t;
        tail = t;
    }
}

// Insert at begining
void insertAtHead(Node *&head, int d)
{
    Node *temp;
    temp = create(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// insert at end
void insertAtTail(Node *&tail, int d)
{
    Node* temp = create(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// insert at a position
void insertAtPostion(Node *&tail, Node *&head, int d, int pos)
{
    // if position is 1
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    // if position is last
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *newNode = create(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
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
    cout << "head data = " << head->data << " tail data =  " << tail->data << endl
         << endl;

    // insertion at begining
    int a;
    cout << "enter a data to be insert at begining : ";
    cin >> a;
    insertAtHead(head, a);
    print(head);
    cout << "head data = " << head->data << " tail data =  " << tail->data << endl
         << endl;

    // insertion at end
    int b;
    cout << "enter a data to be insert at end : ";
    cin >> b;
    insertAtTail(tail, b);
    print(head);
    cout << "head data = " << head->data << " tail data =  " << tail->data << endl
         << endl;

    // insert at a position
    int c, pos;
    cout << "enter a data and a position  : ";
    cin >> c >> pos;
    insertAtPostion(tail, head, c, pos);
    print(head);
    cout << "head data = " << head->data << " tail data =  " << tail->data << endl
         << endl;
}

/*
output:-----

enter the initial size of linked list : 5

enter 5 numbers : 1 2 3 4 5
data of linked list : 1 2 3 4 5         
head data = 1 tail data =  5

enter a data to be insert at begining : 10
data of linked list : 10 1 2 3 4 5 
head data = 10 tail data =  5      

enter a data to be insert at end : 6
data of linked list : 10 1 2 3 4 5 6 
head data = 10 tail data =  6

enter a data and a position  : 9 2
data of linked list : 10 9 1 2 3 4 5 6 
head data = 10 tail data =  6

*/
