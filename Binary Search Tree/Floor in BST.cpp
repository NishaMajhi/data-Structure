/*
Given a BST and a number X, find Floor of X.
Note: floorInBST(X) is a number that is either equal to X or is immediately smaller than X.


Example 1:

Input: 10 5 15 2 6 -1 -1 -1 -1 -1 -1
X = 7
Output: 6


Example 2:

Input: 2 1 3 -1 -1 -1 -1
X = 2
Output: 2

Your task:
You don't need to read input or print anything. Just complete the function floorInBST() to implement floor in BST which returns the floor of X in the given BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105
*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(root == NULL)
        return -1;
    int floor = -1;
    while(root != NULL){
        if(root->val == X){
            floor = root->val;
            return floor;
        }
        else if(root->val > X){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        }
    }
    
    return floor;
}
