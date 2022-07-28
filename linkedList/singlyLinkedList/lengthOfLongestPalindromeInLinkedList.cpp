/*
Length of longest palindrome in linked list

Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list . Then in the next line are N space separated values of the given linked list.

Output:
For each test case output will be the required max length of the palindrome present in the given linked list.

User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.

*/

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

int check(Node *&f, Node *&s)
{
    Node *a = f;
    Node *b = s;
    int count = 0;
    while (a != NULL && b != NULL)
    {
        if (a->data == b->data)
        {
            count++;
            a = a->next;
            b = b->next;
        }
        else
        {
            break;
        }
    }
    return count;
}

int lengthOfLongestPalindrom(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;
    int ans = 1;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        ans = max(ans, 2 * check(curr, next));     // even;
        ans = max(ans, 2 * check(prev, next) + 1); // odd
        prev = curr;
        curr = next;
    }

    return ans;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int choice, data;
    do
    {
        cout << "enter data : ";
        cin >> data;
        push(head,tail,data);
        cout << "press 1 for continue : ";
        cin >> choice;

    } while (choice == 1);

    // print(head);
    int len = lengthOfLongestPalindrom(head);
    cout << len << endl;
}