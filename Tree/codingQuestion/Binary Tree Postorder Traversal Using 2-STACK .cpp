/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]


Example 2:
Input: root = []
Output: []


Example 3:
Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
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
    
    vector<int> postorderTraversal(TreeNode* root) {
    
        //using 2-Stack
        vector<int> v;
        
        if(root == NULL)
            return v;
        
        stack<TreeNode*>s1,s2;
        s1.push(root);
        
        while(!s1.empty()){
            
            TreeNode *t = s1.top();
            s2.push(t);
            s1.pop();
            
            if(t->left)
                s1.push(t->left);
            if(t->right)
                s1.push(t->right);
        }
        
        while(!s2.empty()){
            v.push_back(s2.top()->val);
            s2.pop();
        }
        
        return v;
    }
}
