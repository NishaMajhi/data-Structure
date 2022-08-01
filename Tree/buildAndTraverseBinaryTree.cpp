/*
create a Binary Tree and print all the using level order traversal(recursice/iterative)
*/

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
void levelOrderTraversaRecursiveAppoach(Node *root)
{
    if (root == NULL)
        return;
    // find height of binary tree
    int height = heightOfBinaryTree(root);

    // print all node at given level
    for (int i = 1; i <= height; i++)
    {
        printGivenHeightNode(root, i);
    }
}

// iterative approach
void levelOrderTraversalIteraticeAppoach(Node *root)
{
    // we use one queue data structure only
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // get node from queue
        Node *t = q.front();
        q.pop();

        // this is use to print all the data in a tree format
        if (t == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // this is normally we use to print all the data in linear form
            cout << t->data << " ";
            if (t->left != NULL)
            {
                q.push(t->left);
            }
            if (t->right != NULL)
            {
                q.push(t->right);
            }
        }
    }
}

int main()
{

    Node *root = NULL;

    // creation of binary tree
    root = buildBinaryTree(root);

    // Iterative Approach -> level order traversal of binary tree
    cout << "Level order tarversal" << endl;
    levelOrderTraversalIteraticeAppoach(root);

    // Recursive Approach -> level order traversal of binary tree
    // cout << "Level order tarversal" << endl;
    // levelOrderTraversaRecursiveAppoach(root);
}

/*
output using iterative approach in a tree format---------------

enter node data : 1

enter data for left child of 1 : enter node data : 2

enter data for left child of 2 : enter node data : 4

enter data for left child of 4 : enter node data : -1

enter data for right child of 4 : enter node data : -1

enter data for right child of 2 : enter node data : 5

enter data for left child of 5 : enter node data : -1

enter data for right child of 5 : enter node data : -1

enter data for right child of 1 : enter node data : 3

enter data for left child of 3 : enter node data : -1

enter data for right child of 3 : enter node data : 9

enter data for left child of 9 : enter node data : -1

enter data for right child of 9 : enter node data : -1
Level order tarversal
1
2 3
4 5 9
------------------------------------------------------------------------------------------------------
output using Recursive approach in a linear format

enter node data : 1

enter data for left child of 1 : enter node data : 2

enter data for left child of 2 : enter node data : 4

enter data for left child of 4 : enter node data : -1

enter data for right child of 4 : enter node data : -1

enter data for right child of 2 : enter node data : 5

enter data for left child of 5 : enter node data : -1

enter data for right child of 5 : enter node data : -1

enter data for right child of 1 : enter node data : 3

enter data for left child of 3 : enter node data : -1

enter data for right child of 3 : enter node data : 9

enter data for left child of 9 : enter node data : -1

enter data for right child of 9 : enter node data : -1
Level order tarversal
1 2 3 4 5 9
*/
