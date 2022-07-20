/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node ha
s its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point
to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y,
then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]


Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]


Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/

class Node
{
public:
    int data;
    Node *next;
    Node *random;
};

Node *create(int d)
{
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = newNode->random = NULL;
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

void printRandom(Node *head)
{
    while (head != NULL)
    {
        cout << " head data: " << head->data << " ";
        if (head->random != NULL)
        {
            cout << " head random data" << head->random->data;
        }
        else
        {
            cout << " head random data: NULL";
        }
        head = head->next;
        cout << endl;
    }
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

Node *cloneList(Node *head)
{
    //step-1 create a Clone LL by using original->next
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        push(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    //step-2 mapping original LL with clone LL
    unordered_map<Node *, Node *> mp;
    Node *original = head;
    Node *clone = cloneHead;
    while (original != NULL)
    {
        mp[original] = clone;
        original = original->next;
        clone = clone->next;
    }

    //step-3 set clone->random
    original = head;
    clone = cloneHead;
    while (original != NULL)
    {
        clone->random = mp[original->random];
        original = original->next;
        clone = clone->next;
    }
    //step-4 return cloneHead
    return cloneHead;
}
