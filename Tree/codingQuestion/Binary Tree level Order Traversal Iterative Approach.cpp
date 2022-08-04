/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


Example 2:
Input: root = [1]
Output: [[1]]


Example 3:
Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

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
       
    vector<vector<int>> levelOrder(TreeNode* root) {
               
        //create resultant vector
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        //create a Queue for storing node
        queue<TreeNode*> q;
        
        //push the first node along with NULL value because 1sr level is complete
        q.push(root);
        q.push(NULL);
        
        //create a temporary vector to store data of each levels
        vector<int> v;
        
        while(!q.empty()){
            
            TreeNode *t = q.front();
            q.pop();
            
            //if current node is NULL means a level is completed
            if(t == NULL){
                ans.push_back(v);
                
                //if queue still has some nodes after completing a level
                if(!q.empty()){
                   q.push(NULL);
                }
               //clear the previous data from vector in order to store new values of new level
                v.clear();
            }
            
            else{
                v.push_back(t->val);
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        
        return ans;
    }
};



//approach 2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
    
        if(root == NULL)
            return res;
    
    
        queue<TreeNode*> q;
        q.push(root);
    
    
        while(!q.empty())
        {
           int n = q.size();
           vector<int> v;
        
           for(int i = 0; i < n; i++)
           {
               TreeNode* curr = q.front();
               q.pop();
            
               v.push_back(curr->val);
            
               if(curr->left)
                   q.push(curr->left);
            
               if(curr->right)
                   q.push(curr->right);                
            }  
        
           res.push_back(v);
        }
        
        return res;
    }
};
