#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

//creation of a Node
Node *create(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

//traverse the List
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

//creation of initial Linked List
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

//deletion of a Node at any position
void deletionInLinkedList(Node* &head,Node* &tail,int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        cout << "deleted element = " << temp->data << endl;
        delete temp;
    }
    else
    {
        Node *cur = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        if(cur->next ==  NULL)
        {
           tail=prev;
        }

        prev->next = cur->next;
        cur->next->prev = prev;
        cur->next = cur->prev = NULL;
        cout << "deleted element = " << cur->data << endl;
        delete cur;
    }

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
    int pos;
    cout<<"enter position : ";
    cin>>pos;
    deletionInLinkedList(head,tail,pos);
    print(head);
    cout<<"head = "<<head->data<<" tail = "<<tail->data<<endl;
}

/*

output:----


//delete at any random psition
enter the initial size of linked list : 8

enter 8 numbers : 1 2 3 4  5 6 7 8
data of linked list : 1 2 3 4 5 6 7 8 
enter position : 2
deleted element = 2
data of linked list : 1 3 4 5 6 7 8 
head = 1 tail = 8

//delete 1st element
enter the initial size of linked list : 8

enter 8 numbers : 1 2 3 4 5 6 7 8
data of linked list : 1 2 3 4 5 6 7 8 
enter position : 1
deleted element = 1
data of linked list : 2 3 4 5 6 7 8
head = 2 tail = 8

//delete last element
enter the initial size of linked list : 8

enter 8 numbers : 1 2 3 4 5 6 7 8
data of linked list : 1 2 3 4 5 6 7 8 
enter position : 8
deleted element = 8
data of linked list : 1 2 3 4 5 6 7 
head = 1 tail = 7

*/
