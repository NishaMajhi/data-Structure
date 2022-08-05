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
    
        //using 1-STACK
        vector<int> ans;
       
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        TreeNode *curr = root;
        while(!s.empty() || curr != NULL){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = s.top()->right;
                if(temp == NULL){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp == s.top()->right){
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    curr = temp;
            }
        }
        
        return ans;
    }
       
}
