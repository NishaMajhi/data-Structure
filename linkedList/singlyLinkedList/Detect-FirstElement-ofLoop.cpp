//find first element of loop

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

// approach - 1 T.C = S.C = O(N)
Node *firstElementOfLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    // using map :----------
    // unordered_map<Node *, bool> visit;
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     if (visit[temp] == true)
    //         return temp;

    //     visit[temp] = true;
    //     temp = temp->next;
    // }
    // return NULL;

    // using set:----------
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return head;

        s.insert(head);
        head = head->next;
    }
    return NULL;
}

// approach - 2 T.C = O(N) and S.C = O(1)
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

    // Approach 1
    // tail->next = head->next;
    // Node *t = firstElementOfLoop(head);
    // if (t != NULL)
    // {
    //     cout << "Linked List is circular in nature" << endl;
    //        cout<<" first element of loop = "<<t->data<<endl;
    // }
    // else
    //     cout << "Linked List is not circular" << endl;

    // Approach 2
    tail->next = head->next->next->next;
    Node *temp = getFirstElemen(head);
    if (temp != NULL)
    {
        cout << "Linked List is circular in nature" << endl;
        cout << "first element of loop = " << temp->data << endl;
    }
    else
        cout << "Linked List is not circular" << endl;
}
