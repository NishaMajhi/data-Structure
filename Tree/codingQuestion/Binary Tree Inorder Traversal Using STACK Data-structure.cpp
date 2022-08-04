/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]


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


//approach 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        vector<int> v;
        if(root==NULL)
            return v;
        TreeNode *p=root;
        stack<TreeNode* > s;
        
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p=p->left;
            }
            
            else
            {
                TreeNode *t = s.top();
                v.push_back(t->val);
                s.pop();
                p=t->right;
            }
        }
        
        return v;
        
        
    }
};

//approach 2
class Solution {
public:
    
         vector<int> inorderTraversal(TreeNode* root) {
          
             vector<int> res;
             
             TreeNode *t=root;
             if(t == NULL)
                 return res;
             
             stack<TreeNode*> s;
             
             while(true){
                 
                 if(t!=NULL){
                     s.push(t);
                     t=t->left;
                 }
                 else{
                     if(s.empty())
                         break;
                     t=s.top();
                     s.pop();
                     res.push_back(t->val);
                     t=t->right;
                 }
             }
             
             return res;
         }
}
