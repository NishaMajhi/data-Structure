/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
*/

//recursive approach 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        
        if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
        
    }
   
}       
        
#include<bits/stdc++.h>
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

//Iterative approach
Node *solution(Node *head1,Node *head2)
{
     
    Node *curr1 = head1;
    Node *next1 = head1->next;
    Node *curr2 = head2;
    Node *next2 = NULL;
    while (curr2 != NULL && next1 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }

    return head1;
}

Node *merge(Node *head1, Node *head2)
{
    if(head1->data <= head2->data)
        head1 = solution(head1,head2);

    else
       head1 =  solution(head2,head1);

    return head1;
}

int main()
{
    Node *head, *head1, *tail, *tail1;
    head = tail = NULL;
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
        push(head, tail, d);
    }

    int m;
    cout << "enter the initial size of second linked list : ";
    cin >> m;
    cout << endl
         << "enter " << m << " numbers : ";
    while (m--)
    {
        int d;
        cin >> d;
        push(head1, tail1, d);
    }
    print(head);
    print(head1);

    head = merge(head, head1);
    print(head);
}

/*
output:----------------

enter the initial size of linked list : 4

enter 4 numbers : 10 20 30 40
enter the initial size of second linked list : 4

enter 4 numbers : 5 10 15 20
data of linked list : 10 20 30 40 
data of linked list : 5 10 15 20 
data of linked list : 5 10 10 15 20 20 30 40 

*/
