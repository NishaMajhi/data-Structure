/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
and inorder is the inorder traversal of the same tree,
construct and return the binary tree.

 

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]



Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
    
    TreeNode* buildTreeWithInPre(vector<int> &pre,int pSt,int pEnd,vector<int> &in,int inSt,
                        int inEnd,map<int,int> &inMap){
        
        if(pSt>pEnd || inSt>inEnd)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[pSt]);
        
        int rootPosInInorder = inMap[root->val];
        int left = rootPosInInorder - inSt;
        
        root->left = buildTreeWithInPre(pre,pSt+1,pSt+left,
                               in,inSt,rootPosInInorder-1,inMap);
        
        root->right = buildTreeWithInPre(pre,pSt+left+1,pEnd,
                                      in,rootPosInInorder+1,inEnd,inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }
        
        int psize = preorder.size()-1;
        int insize = inorder.size()-1;
        
        TreeNode *root = buildTreeWithInPre(preorder,0,psize,
                                   inorder,0,insize,inorderMap);
        
        return root;
    }
};

