// reverse a Lnked List in K size group
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

Node *reverseKsize(Node *head, int k)
{
    if (head == NULL)
        return head;

    int i = 0;
    Node *cur = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (cur != NULL && i < k)
    {
        next = cur->next; // storing next address
        cur->next = prev; // assining previous address to cur->next
        prev = cur;
        cur = next;
        i++;
    }

    if(next != NULL){
        head->next = reverseKsize(next , k);
    }

    return prev;
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
    int k;
    cout<<"enter group size : ";
    cin>>k;
    head = reverseKsize(head,k);
    print(head);
}

/*

output:---
enter the initial size of linked list : 6

enter 6 numbers : 1 2 3 4 5 6 
data of linked list : 1 2 3 4 5 6 
enter group size : 2
data of linked list : 2 1 4 3 6 5 


enter the initial size of linked list : 6

enter 6 numbers : 1 2 3 4  5 6
data of linked list : 1 2 3 4 5 6 
enter group size : 3
data of linked list : 3 2 1 6 5 4 

*/
