/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. 

For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2

Output: 3 1 2

Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.



Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60

Output: 40 20 60 30



Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView()
which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105


Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only.
As it is a function problem, hence a user should not read any input from the stdin/console.
The task is to complete the function specified, and not to write the full code.
*/


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        vector<int> res;
        if(!root)
           return res;
           
        //take a map for getting the result from left(small) to right(big) -- ascending 
        // instead of unordered map  
        //map for storing only first value of each line virtically
        map<int,int> mp;
        
        //queue for storing node with line number 
        queue<pair<Node* , int> > q;
        q.push({root,0});
        
        while(!q.empty()){
            
            //take out the front pair from queue
            auto it = q.front();
            q.pop();
            
            //get node and line from the front of queue
            Node *temp = it.first;
            int line = it.second;
            
            // push node value correspondence to line
            mp[line] = temp->data;
             
            //check if current node has left node
            //then push the current node->data into the queue with line = current line-1
            if(temp->left)
               q.push({temp->left,line-1});
               
            //check if current node has right node
            //then push current the node->data into the queue with line = current line+1
            if(temp->right)
               q.push({temp->right,line+1});
        }
        
        //get the node->data from the map into resultant vector
        for(auto it:mp){
            res.push_back(it.second);
        }
        
        return res;
    }
};
