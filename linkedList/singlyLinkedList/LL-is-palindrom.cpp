/*
Given the head of a singly linked list, return true if it is a palindrome.
 
Example 1:

Input: head = [1,2,2,1]
Output: true


Example 2:

Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        //approach 1 t.c=s.c=O(n)
        //create a vector to store LL data
        vector<int> v;
        
        ListNode *temp = head;
        
        //store the data of LL in vector
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        //traverse the vector to check palindrom
        int i = 0,j = v.size()-1;
        while(i<=j){
            if(v[i] != v[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
};


// find  Linked List  is palindrom or not
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

Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *getMid(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//approach 2 t.c=O(n) s.c=O(1)
bool palindrom(Node *head)
{ 
    if(head->next == NULL)
       return true;

    Node *mid = getMid(head);

    Node *temp = mid->next;
    mid->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = mid->next;
    while (head2!= NULL)
    {
        if (head1->data != head2->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = mid->next;
    mid->next = reverse(temp);

    return true;
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

    if (palindrom(head1) == true)
        cout << "palindrom";
    else
        cout << "not palindrom";

    return 0;
}

/*
output:------
enter the size of first linked list : 4

enter 4 numbers : 1 2 3 4
not palindrom

enter the size of first linked list : 5

enter 5 numbers : 1 2 3 2 1
palindrom
*/
