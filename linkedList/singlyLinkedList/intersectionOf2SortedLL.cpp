
//find the intersection of two sorted Linked List
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

Node * intersection(Node* h1,Node *h2)
{
    Node *ansh,*anst;
    ansh = anst = NULL;
    while(h1 != NULL && h2 != NULL)
    {
        int v1 = h1->data;
        int v2 = h2->data;
        if(v1 == v2)
        {
            push(ansh,anst,v1);
            h1 = h1->next;
            h2 = h2->next;
        }
        else if(v1 < v2)
        {
            h1 = h1->next;
        }
        else
           h2 = h2->next;
    }

    return ansh;
}

int main()
{
    Node *head1, *tail1;
    head1 = tail1 = NULL;

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
        push(head1, tail1, d);
    }
    Node *head2, *tail2;
    head2 = tail2 = NULL;

    // creating initial nodes in Linked List
    int m;
    cout << "enter the  size of second linked list : ";
    cin >> m;
    cout << endl
         << "enter " << m << " numbers : ";
    while (m--)
    {
        int d;
        cin >> d;
        push(head2, tail2, d);
    }

    Node *ans = intersection(head1,head2);
    print(ans);
}

/*
output:-------
enter the initial size of linked list : 6

enter 6 numbers : 1 2 3 4 5 6
enter the  size of second linked list : 4

enter 4 numbers : 2 4 6 8
data of linked list : 2 4 6 
*/
