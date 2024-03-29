/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]



Example 2:

Input: root = [1]
Output: [[1]]



Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;
        
        queue<TreeNode* > q;
        q.push(root);
        
        int flag = true;    //true mean left-to-right  and false mean right-to-left
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> curr(n);
            
            for(int i=0;i<n;i++){
                
                TreeNode *node = q.front();
                q.pop();
                
                //if flag = 0 insert from begining 
                //if flag = 1 insert from end
                int index = (flag) ? i : (n-1-i);
                
                curr[index] =  node->val;
                
                if(node->left) 
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            //assign flag to its opposite
            flag = !(flag);
            result.push_back(curr);
        }
        
        
        return result;
    }
};
