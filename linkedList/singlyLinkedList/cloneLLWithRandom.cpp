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
