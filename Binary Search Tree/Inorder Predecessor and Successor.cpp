/*
There is BST given with root node with key part as an integer only. 
You need to find the in-order successor and predecessor of a given key.
If either predecessor or successor is not found, then set it to NULL.



Example:

Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1


Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains n denoting the number of edges of the BST. 
The next line contains the edges of the BST. The last line contains the key.

Output:
Find the predecessor and successor of the key in BST and sets pre and suc as predecessor and successor, respectively Otherwise, set to NULL.

Your Task:
You don't need to print anything. You only need to set p.pre to the predecessor and s.succ to the successor.
p and s have been passed in the function parameter.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100
*/


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

Node* predec(Node *root,int val){
    Node *res = NULL;
    while(root != NULL){
        if(root->key < val){
            res = root;
            root = (root->right);
        }
        else
           root = (root->left);
    }
    
    return res;
}

Node* succ(Node *root,int val){
    Node *res = NULL;
    while(root != NULL){
        if(root->key > val){
           res = root;
           root = (root->left);
        }
        else
           root = (root->right);
    }
    
    return res;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    pre = predec(root,key);
    suc = succ(root,key);

}
