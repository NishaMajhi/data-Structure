/*

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/


//iterative approach
class Solution
{
public:
    static int lengthOfLinkedList(ListNode *head)
    {

        int length = 0;
        while (head != NULL)
        {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL)
            return head;

        int length = lengthOfLinkedList(head);

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        ListNode *cur;
        ListNode *nex;

        while (length >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummyHead->next;
    }
};


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

//recursive approach
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
