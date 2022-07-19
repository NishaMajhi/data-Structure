/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1

Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0

Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle

Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //funtion to find meet point in Linked List
    ListNode *meetPoint(ListNode *head)
    {
       //create two pointer and assign head
        ListNode *fast = head;
        ListNode *slow = head;
        
        //traverse the LIned List untill both are not same
         while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
             
             //if found same then return any of the one node
             if(fast == slow)
                 return fast;
         }
        
        //if not fornd the meet point return NULL
        return NULL;
        
        
    }
    ListNode *detectCycle(ListNode *head) {
        
           if(head == NULL)
               return NULL;
        
//         //approach 1 t.c = s.c = O(n)
        
//         // create a map to store List Node and their position
//         unordered_map<ListNode* , int> m;
        
//         ListNode *temp = head;
        
//         //variable to keep track for node position
//         int i=0;
        
//         while(temp != NULL){
            
//             //if node is already present return node
//             if(m.find(temp) != m.end())
//                 return temp;
            
//             //if not then insert the node with position and incerease the position
//             m[temp]=i;
//             i++;
            
//             //update temp to next node
//             temp = temp->next;
//         }
        
//         //otherwise return NULL
//        return NULL;
        
        
        
        //approach 2 t.c=O(n) s.c=O(1)
        
        //find the meet point in the Linked List
        ListNode *meet = meetPoint(head);
        
        //if meet become NULL mean no loop then return NULL
        if(meet == NULL)
            return NULL;
       //create a node to traverse from the start of the Linked List
        ListNode *start = head;
              
        //traverse the Linked List untill both are not same
        while(start != meet){
            start=start->next;
            meet=meet->next;
        }
        
        //return the start of the loop
        return start;
        
    }
};



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
