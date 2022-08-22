/*
Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.


Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3



Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100


Your Task:
Since this is a function problem. You don't have to take input.
Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105
 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only.
As it is a function problem, hence a user should not read any input from stdin/console.
The task is to complete the function specified, and not to write the full code.
*/


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
            
            //if line is not previously exists then push node value correspondence to line
            if(mp.find(line) ==  mp.end())
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
