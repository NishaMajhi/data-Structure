//remove the loop from Linked List

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
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

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

//using hashing map values
void removeloop(Node* &head)
{
    unordered_map<Node*,int> mp;
    Node *prev = NULL;
    Node *temp = head;
    while(temp != NULL)
    {
        if(mp[temp])
        {
          prev->next = NULL;
          return;
        }
        mp[temp]++;
        prev = temp;
        temp = temp->next;
    }
}

Node *floydCycleDelect(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow)
            return fast;
    }

    return NULL;
}

Node *getFirstElemen(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *midPoint = floydCycleDelect(head);

    if (midPoint == NULL)
        return NULL;

    Node *slow = head;
    while (slow != midPoint)
    {
        slow = slow->next;
        midPoint = midPoint->next;
    }

    return slow;
}

void removeLoop(Node* &head)
{
    if(head == NULL)
       return;

    Node *startLoop = getFirstElemen(head);
    Node *temp = startLoop;
    while(temp->next != startLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
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

    // remove loop
    tail->next = head->next->next->next;
    removeloop(head);
    print(head);
    cout << "head data = " << head->data << " tail data =  " << tail->data << endl
         << endl;
   
       
}
