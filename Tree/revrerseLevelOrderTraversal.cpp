#include <bits/stdc++.h>
using namespace std;

// Creating node structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // creating constructor for assing value to node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build binary tree
Node *buildBinaryTree(Node *root)
{

    // enter node value
    int d;
    cout << "enter node data : ";
    cin >> d;

    // if data is -1 means node value id NULL
    if (d == -1)
        return NULL;

    // create node with value
    root = new Node(d);

    // call function for left side of current node
    cout << endl
         << "enter data for left child of " << d << " : ";
    root->left = buildBinaryTree(root->left);

    // call function for left side of current node
    cout << endl
         << "enter data for right child of " << d << " : ";
    root->right = buildBinaryTree(root->right);

    // return current root
    return root;
}

// find height of binary tree
int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        // find left height
        int leftHeight = heightOfBinaryTree(root->left);
        // find right height
        int rightHeight = heightOfBinaryTree(root->right);
        // compare and return height value
        if (leftHeight >= rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

void printGivenHeightNode(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else
    {
        // call function for left side
        printGivenHeightNode(root->left, level - 1);
        // call function for right side
        printGivenHeightNode(root->right, level - 1);
    }
}

// Recursive approach
void reverseLevelOrderTraversaRecursiveAppoach(Node *root)
{
    if (root == NULL)
        return;
    // find height of binary tree
    int height = heightOfBinaryTree(root);

    // print all node at given level
    for (int i = height; i >= 1; i--)
    {
        printGivenHeightNode(root, i);
    }
}

// iterative approach
void reverseLevelOrderTraversaIterativeAppoach(Node *root)
{
    // we use one queue data structure only
    queue<Node *> q;
    stack<Node *> st;
    q.push(root);

    while (!q.empty())
    {
        // get node from queue
        Node *t = q.front();
        st.push(t);
        q.pop();

        // this is normally we use to print all the data in linear form
        if (t->right != NULL)
        {
            q.push(t->right);
        }
        if (t->left != NULL)
        {
            q.push(t->left);
        }
    }

    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}

int main()
{

    Node *root = NULL;

    // creation of binary tree
    root = buildBinaryTree(root);

    // Iterative Approach -> level order traversal of binary tree
    cout << "Reverse Level order tarversal using Iterative approach" << endl;
    reverseLevelOrderTraversaIterativeAppoach(root);
    cout<<endl;

    // Recursive Approach -> level order traversal of binary tree
    cout << "Reverse Level order tarversal using Recursive approach" << endl;
    reverseLevelOrderTraversaRecursiveAppoach(root);
}