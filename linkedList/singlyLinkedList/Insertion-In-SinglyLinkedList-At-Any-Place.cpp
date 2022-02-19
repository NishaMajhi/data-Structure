//taking user input for creating and inserting
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
// Insert at begining
void insertAtHead(Node *&head, int d)
{
    Node *temp = head;
    head = create(d);
    head->next = temp;
}

// insert at end
void insertAtTail(Node *&tail, int d)
{
    tail->next = create(d);
    tail = tail->next;
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

// input ,output --------
enter the initial size of linked list : 5

enter 5 numbers : 5 10 15 20 30
data of linked list : 5 10 15 20 30 
head data = 5 tail data =  30

enter a data to be insert at begining : 2
data of linked list : 2 5 10 15 20 30 
head data = 2 tail data =  30

enter a data to be insert at end : 35
data of linked list : 2 5 10 15 20 30 35 
head data = 2 tail data =  35

enter a data and a position  : 25 6
data of linked list : 2 5 10 15 20 25 30 35 
head data = 2 tail data =  35

//another way of creating and inserting  (compile time inputs)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Traversal
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Insert at begining
void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// insert at end
void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
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

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head, *tail;

    head = tail = NULL;

    // creating 1st Node
    Node *node1 = new Node(10);
    head = tail = node1;
    print(head);

    // insert at front
    insertAtHead(head, 20);
    print(head);

    // insert at end
    insertAtTail(tail, 30);
    print(head);

    // insert at a position
    insertAtPostion(tail, head, 25, 4);
    print(head);

    insertAtTail(tail, 100);
    print(head);
}

//output:---
10 
20 10
20 10 30
20 10 30 25
20 10 30 25 100
