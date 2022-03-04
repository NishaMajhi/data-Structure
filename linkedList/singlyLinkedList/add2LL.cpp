// add two linked list and give the answer in a form ofLinked List
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
        return;
    }
    else
    {
        tail->next = create(d);
        tail = tail->next;
    }
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
/*
//Approach - 1
Node *addTwoLL(Node *head1, Node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node *ansHead = NULL, *ansTail = NULL;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        push(ansHead, ansTail, digit);
        carry = sum / 10;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        int sum = carry + head1->data ;
        int digit = sum % 10;
        push(ansHead, ansTail, digit);
        carry = sum / 10;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        push(ansHead, ansTail, digit);
        carry = sum / 10;
        head2 = head2->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        push(ansHead, ansTail, carry);
        carry = sum / 10;
    }


    return ansHead;
}*/

// More Optimise

Node *addTwoLL(Node *head1, Node *head2)
{
    //step 1 reverse the LL
    head1 = reverse(head1);
    head2 = reverse(head2);

    //step 2 add from left
    Node *ansHead = NULL, *ansTail = NULL;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int value1 = 0;
        if (head1 != NULL)
            value1 = head1->data;

        int value2 = 0;
        if (head2 != NULL)
            value2 = head2->data;

        int sum = carry + value1 + value2;
        int digit = sum % 10;
        push(ansHead, ansTail, digit);
        carry = sum / 10;
        if (head1 != NULL)
            head1 = head1->next;

        if (head2 != NULL)
            head2 = head2->next;
    }

    // step 3 reverse the ans LL
    ansHead = reverse(ansHead);
    return ansHead;
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

    Node *head2, *tail2;
    head2 = tail2 = NULL;

    // creating initial nodes in Linked List
    int m;
    cout << "enter the size of second linked list : ";
    cin >> m;
    cout << endl
         << "enter " << m << " numbers : ";
    while (m--)
    {
        int d;
        cin >> d;
        push(head2, tail2, d);
    }

    Node *ans = addTwoLL(head1, head2);
    print(ans);
}

/*
output:----------
enter the size of first linked list : 4

enter 4 numbers : 1 1 1 5
enter the size of second linked list : 3

enter 3 numbers : 1 7 9
data of linked list : 1 2 9 4 
*/
