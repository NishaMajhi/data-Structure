/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]


Example 2:
Input: root = []
Output: []


Example 3:
Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    //using STACK data structure
     vector<int> preorderTraversal(TreeNode* root) {
    
         vector<int> res;
         
         if(root == NULL)
             return res;
         
         stack<TreeNode*> s;
         s.push(root);
         
         while(!s.empty()){
             
             TreeNode *t = s.top();
             s.pop();
             
             res.push_back(t->val);
             
             //firstly we will push right then left because in stack first in last out
             if(t->right)
                 s.push(t->right);
             if(t->left)
                 s.push(t->left);
         }
         
         return res;
     }
};
