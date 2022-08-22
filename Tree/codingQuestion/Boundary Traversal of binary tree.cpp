/*

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- 
the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root.
The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree.
Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:


 

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
Explanation:


As you can see we have not taken the right subtree. 

Your Task:
This is a function problem. You don't have to take input.
Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105*/


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



/*
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    bool isLeaf(Node *root){
        if(!root->left && !root->right)
           return true;
        return false;
    }
    
    void leftBoundary(Node *root,vector<int> &vec){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr))
               vec.push_back(curr->data);
               
            if(curr->left)
               curr = curr->left;
            else
               curr = curr->right;
        }
    }
    
    void addLeaf(Node* root,vector<int> &vec){
        if(isLeaf(root)){
            vec.push_back(root->data);
            return;
        }
        
        if(root->left){
           addLeaf(root->left,vec);
        }
        if(root->right){
           addLeaf(root->right,vec);   
        }
    }
    
     void rightBoundary(Node *root,vector<int> &vec){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr))
               temp.push_back(curr->data);
               
            if(curr->right)
               curr = curr->right;
            else
               curr = curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            vec.push_back(temp[i]);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root == NULL)
           return res;
         
        //if root is not leafnode then add it to answer   
        if(!isLeaf(root))
           res.push_back(root->data);
    
        //visit left side of tree excluding leaves node       
        leftBoundary(root,res);
        
        //add all leaves node after visiting left side
        addLeaf(root,res);
        
        //add all right node in reverse order ecluding leaves and root node
        rightBoundary(root,res);
        
        
        return res;
    }
};



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
