
#include<iostream>
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
Node *sort(Node *head)
{
    //Appraoch -1
    // int zeroCount = 0,oneCount = 0, twoCount = 0;
    // Node *temp = head;
    // while(temp != NULL)
    // {
    //     if(temp->data == 0)
    //        zeroCount++;
    //     else if(temp->data == 1)
    //        oneCount++;
    //     else
    //        twoCount++;

    //     temp = temp->next;
    // }

    // temp = head;
    // while(temp != NULL)
    // {
    //     if(zeroCount != 0){
    //        temp->data = 0;
    //        zeroCount--;
    //     }
    //     else if(oneCount != 0)
    //     {
    //         temp->data = 1;
    //         oneCount--;
    //     }
    //     else if(twoCount != 0){
    //         temp->data = 2;
    //         twoCount--;
    //     }

    //     temp = temp->next;
    // }


   //Approach 2
    Node *zh = create(0), *zt = zh; // zero head tail
    Node *oh = create(0), *ot = oh; // one head tail
    Node *sh = create(0), *st = sh; // second head tail
    while (head != NULL)
    {
        if (head->data == 0)
        {
            zt->next = head;
            zt = head;
        }
        else if (head->data == 1)
        {
            ot->next = head;
            ot = head;
        }
        else
        {
            st->next = head;
            st = head;
        }
        head = head->next;
    }

    st->next = NULL;
    ot->next = sh->next;
    zt->next = oh->next;

    return zh->next;
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
    // print(head);

    head = sort(head);
    print(head);
}
