/*
Given a Binary search tree. Your task is to complete the function which will return 
the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4



Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest()
which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height h at a given time.


Constraints:
1 <= N <= 1000
1 <= K <= N
*/


/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    
    void inorder(Node* root,vector<int> &t){
        if(root == NULL)
           return;
        inorder(root->left,t);
        t.push_back(root->data);
        inorder(root->right,t);
    }
    
    int kthLargest(Node *root, int K)
    {
         vector<int> t;
         inorder(root,t);
         if(t.size() < K)
           return -1;
          
         int n = t.size();
         return t[n-K];
         
    }
};
