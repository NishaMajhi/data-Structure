// Add Another Linked List in place of given range in Linked List
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

void changeLinkedList(Node *&head1, Node *head2, int a, int b)
{
    Node *temp = head1;
    Node *prev = NULL;
    Node *tail1 = NULL, *tail2 = NULL;
    // finding address of ending range in First LL
    while (temp->data != b)
    {
        tail1 = temp->next;
        temp = temp->next;
    }
    Node *h2 = head2;
    // finding tail of second LL
    while (h2->next != NULL)
    {
        tail2 = h2->next;
        h2 = h2->next;
    }
    temp = head1;
    // add
    while (temp != NULL)
    {
        if (temp->data != a)
        {
            prev = temp;
            temp = temp->next;
        }
        else
        {
            prev->next = head2;
            tail2->next = tail1->next;
            return;
        }
    }
}

int main()
{
    Node *head, *tail;
    head = tail = NULL;

    // creating initial nodes in Linked List
    int n;
    cout << "enter the  size of linked list : ";
    cin >> n;
    cout << endl
         << "enter " << n << " numbers : ";
    while (n--)
    {
        int d;
        cin >> d;
        push(head, tail, d);
    }

    Node *head1, *tail1;
    head1 = tail1 = NULL;
    print(head);

    // creating Another Linked List
    int m;
    cout << endl
         << "enter the size of Another linked list : ";
    cin >> m;
    cout << endl
         << "enter " << m << " numbers : ";
    while (m--)
    {
        int d;
        cin >> d;
        push(head1, tail1, d);
    }

    int a, b;
    cout << endl
         << "enter ranges between starting and ending of Linked List : ";
    cin >> a >> b;
    changeLinkedList(head, head1, a, b);
    print(head);
    return 0;
}

/*
output------
enter the  size of linked list : 5

enter 5 numbers : 1 2 3 4 5
data of linked list : 1 2 3 4 5 

enter the size of Another linked list : 4

enter 4 numbers : 9 8 7 6 

enter ranges between starting and ending of Linked List : 2 3
data of linked list : 1 9 8 7 6 4 5

PS D:\pacement\SingleLinkedList> cd "d:\pacement\SingleLinkedList\" ; if ($?) { g++ addAnotherLL-In-LL.cpp -o addAnotherLL-In-LL } ; if ($?) { .\addAnotherLL-In-LL }
enter the  size of linked list : 5

enter 5 numbers : 1 2 3 4 5
data of linked list : 1 2 3 4 5 

enter the size of Another linked list : 4

enter 4 numbers : 9 8 7 6

enter ranges between starting and ending of Linked List : 2 4
data of linked list : 1 9 8 7 6 5 

*/
