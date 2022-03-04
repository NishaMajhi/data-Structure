// add 1 in Linked List
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
        return;
    }
    else
    {
        tail->next = create(d);
        tail = tail->next;
    }
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}


Node *add1InLL(Node *head)
{
    head = reverse(head);
    Node *ans = head;
    Node *prev = NULL;
    while(head != NULL)
    {
        if(head->data < 9)
        {
            head->data += 1;
            return reverse(ans);
        }
        else{
            head->data = 0;
            prev = head;
            head = head->next;
        }
    }

    Node *t = create(1);
    prev->next = t;
    return reverse(ans);
}

int main()
{
    Node *head1, *tail1;
    head1 = tail1 = NULL;

    // creating initial nodes in Linked List
    int n;
    cout << "enter the size of first linked list : ";
    cin >> n;
    cout << endl
         << "enter " << n << " numbers : ";
    while (n--)
    {
        int d;
        cin >> d;
        push(head1, tail1, d);
    }
    Node * ans = add1InLL(head1);
    cout<<"after 1 adding ";
    print(ans);
}

/*
output:-------
enter the size of first linked list : 4

enter 4 numbers : 9 9 9 9
after 1 adding data of linked list : 1 0 0 0 0 



enter the size of first linked list : 4

enter 4 numbers : 1 2 3 4
after 1 adding data of linked list : 1 2 3 5 
*/
