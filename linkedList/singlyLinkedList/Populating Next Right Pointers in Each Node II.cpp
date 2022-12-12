/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
 

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]


Example 2:
Input: root = []
Output: []
 
 
Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100


Follow-up:
You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return root;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                Node *t = q.front();
                q.pop();
                if(i==(s-1)){
                    t->next = NULL;
                }
                else{
                    t->next = q.front();
                }

                if(t->left)
                   q.push(t->left);
                if(t->right)
                   q.push(t->right);
            }
        }

        return root;
    }
};