// Find  Maximum Sum with Twin in LL
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

void print(Node *head)
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
//  Approach 1 T.C = S.C = (n)
int maxSumByTwin(Node *head)
{
    vector<int> v;
    while (head != NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }
    int i = 0, j = v.size() - 1;
    int sum = 0, maxSum = 0;
    while (i <= j)
    {
        sum = v[i++] + v[j--];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// Approach 2 T.C = O(n) S.C = O(1)
Node *getMid(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int maxSumFromTwin(Node *head)
{
    Node *mid = getMid(head);
    Node *temp = mid->next;
    mid->next = reverse(temp);
    Node *h1 = head;
    Node *h2 = mid->next;
    int sum = 0, maxSum = 0;
    while (h2 != NULL)
    {
        sum = h1->data + h2->data;
        maxSum = max(maxSum, sum);
        h1 = h1->next;
        h2 = h2->next;
    }

    return maxSum;
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

    cout << "maximum sum by twin with Approach 1 :  " << maxSumByTwin(head) << endl;

    cout << "maximum Sum by twin with Approach 2 : " << maxSumFromTwin(head);
    return 0;
}
/*
output-------
enter the initial size of linked list : 6

enter 6 numbers : 1 9 2 8 3 7 
maximum sum by twin with Approach 1 :  12
maximum Sum by twin with Approach 2 : 12 
*/
