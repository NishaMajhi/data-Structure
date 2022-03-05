//Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
};

Node *create(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = newNode->bottom = NULL;
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
Node *merge(Node *d,Node *r)
{
    if(d == NULL)   
        return r;
    
    if(r == NULL)
         return d;
      
    
    Node *res = create(1);
    Node *temp = res;
    
    while(d != NULL && r!= NULL)
    {
        if(d->data <= r->data)
        {
           temp->bottom = d;
           temp = temp->bottom;
           d = d->bottom;
        }
        else
        {
            temp->bottom = r;
            temp = r;
            r =r->bottom;
        }
    }
    
    if(d)
    {
        temp->bottom = d;
    }
    else
    {
        temp->bottom = r;
    }

    
    return res->bottom;
}

Node *flatten(Node *root)
{
 
    if(root == NULL)
      return NULL;
      
    Node *down = root;
    
    Node *right = flatten(root->next);
    
    Node *res = merge(down,right);
    
    return res;
    
   
}

int main()
{
    Node *head, *tail;
    head = tail = NULL;

    // creating initial nodes in Linked List
    int n;
    cout << "enter the size of linked list : ";
    cin >> n;
    cout << endl
         << "enter " << n << " numbers : ";
    while (n--)
    {
        int d;
        cin >> d;
        push(head, tail, d);
    }
    head = flatten(head);
    print(head);
}
