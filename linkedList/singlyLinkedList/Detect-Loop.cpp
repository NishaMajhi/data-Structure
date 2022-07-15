/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 
Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true

Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:

Input: head = [1,2], pos = 0
Output: true

Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.


Example 3:

Input: head = [1], pos = -1
Output: false

Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 
*/

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
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    // using map
    // unordered_map<Node *, bool> visit;
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     if (visit[temp] == true)
    //         return true;

    //     visit[temp] = true;
    //     temp = temp->next;
    // }
    // return false;

    //using set
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;

        s.insert(head);
        head = head->next;
    }
    return false;

}

// approach - 2 T.C = O(N) and S.C = O(1)
bool floydCycleDelect(Node *head)
{
    if (head == NULL)
        return false;

    Node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        
        slow = slow->next;

        if(fast == slow)
           return true;
    }

    return false;
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

    // for checking loop Approach 1
    // tail->next = head->next;
    // if (detectLoop(head))
    // {
    //     cout << "Linked List is circular in nature" << endl;
    // }
    // else
    //     cout << "Linked List is not circular" << endl;

    //for checking loop Approach 2
    tail->next = head->next->next->next;
    if (floydCycleDelect(head))
        cout << "Linked List is circular in nature" << endl;
    else
        cout << "Linked List is not circular" << endl;
}
