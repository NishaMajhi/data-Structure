/*
Preorder Inorder Postorder Traversals in One Traversal. Write a program to print Preorder, Inorder, and Postorder traversal of the tree in a single traversal.

Example 1:
Input:
enter node data : 1
enter data for left child of 1 : enter node data : 2
enter data for left child of 2 : enter node data : 3
enter data for left child of 3 : enter node data : -1
enter data for right child of 3 : enter node data : -1
enter data for right child of 2 : enter node data : 4
enter data for left child of 4 : enter node data : -1
enter data for right child of 4 : enter node data : -1
enter data for right child of 1 : enter node data : 5
enter data for left child of 5 : enter node data : 6
enter data for left child of 6 : enter node data : -1
enter data for right child of 6 : enter node data : -1
enter data for right child of 5 : enter node data : 7
enter data for left child of 7 : enter node data : -1
enter data for right child of 7 : enter node data : -1

Output:
PreOrder Traversal : 1 2 3 4 5 6 7 
InOrder Traversal : 3 2 4 1 6 5 7
PostOrder Traversal : 3 4 2 6 7 5 1 
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

void PreInPostTraversal(Node *root, vector<int> &pre, vector<int> &In, vector<int> &post)
{
    if (root == NULL)
        return;

    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        // root position is 1 in preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        // root position is 2 in inorder
        else if (it.second == 2)
        {
            In.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        // root position is 3 in postorder
        else
        {
            post.push_back(it.first->data);
        }
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    Node *root = NULL;

    // creation of binary tree
    root = buildBinaryTree(root);

    vector<int> pre, in, post;
    PreInPostTraversal(root, pre, in, post);

    cout << "PreOrder Traversal : ";
    display(pre);

    cout << "InOrder Traversal : ";
    display(in);

    cout << "PostOrder Traversal : ";
    display(post);
}
