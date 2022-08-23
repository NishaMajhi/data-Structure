/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree,
construct and return the binary tree. 


Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]



Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    
    TreeNode* buildTreeWithInPost(vector<int> &post,int pSt,int pEnd,vector<int> &in,int inSt,
                        int inEnd,map<int,int> &inMap){
        
        if(pSt>pEnd || inSt>inEnd)
            return NULL;
        
        TreeNode *root = new TreeNode(post[pEnd]);
        
        int rootPosInInorder = inMap[post[pEnd]];
        int left = rootPosInInorder - inSt;
        
        root->left = buildTreeWithInPost(post,pSt,pSt+left-1,
                               in,inSt,rootPosInInorder-1,inMap);
        
        root->right = buildTreeWithInPost(post,pSt+left,pEnd-1,
                                      in,rootPosInInorder+1,inEnd,inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() != postorder.size())
            return NULL;
        
        map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }
        
        int psize = postorder.size()-1;
        int insize = inorder.size()-1;
        
        TreeNode *root = buildTreeWithInPost(postorder,0,psize,
                                   inorder,0,insize,inorderMap);
        
        return root;
    
    }
};

 
    
        
        
