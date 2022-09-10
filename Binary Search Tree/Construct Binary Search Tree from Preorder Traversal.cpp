/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val,
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Example 2:
Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
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



/*
class Solution {
public:

//     t.c = O(nlogn) s.c = O(n)
    TreeNode* construct(vector<int>& pre,int pst,int pend,
                        vector<int>& in,int inst,int inend,map<int,int> &inmap){
        
        if(pst > pend || inst > inend)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[pst]);
        
        int pos = inmap[pre[pst]];
        int left = pos-inst;
        
        root->left = construct(pre,pst+1,pst+left,in,inst,pos-1,inmap);
        root->right = construct(pre,pst+left+1,pend,in,pos+1,inend,inmap);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        vector<int> in;
        for(int i=0; i<pre.size(); i++)
            in.push_back(pre[i]);
        
        sort(in.begin(),in.end());
        
        map<int,int> mp;
        for(int i=0; i<in.size(); i++)
            mp[in[i]] = i;
        
        int prest = 0, prend = pre.size()-1;
        int inst = 0, inend = in.size()-1;
        
        return construct(pre,prest,prend,in,inst,inend,mp);
    }
    
};
*/



class Solution {
public:
  
    //t.c = O(n) s.c = O(1)
    TreeNode* build(vector<int> &p,int &i,int range){
        if(i >= p.size() || p[i] > range)
            return NULL;
        
        TreeNode*  root = new TreeNode(p[i++]);
        
        root->left = build(p,i,root->val);
        root->right = build(p,i,range);
        
        return root;
    }
    
    
     TreeNode* bstFromPreorder(vector<int>& pre) {
         int i=0;
         return build(pre,i,INT_MAX);
     }
};
