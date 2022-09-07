/*
insert a given node val in BST
*/

Node* insertion(Node *root,int val)
{
    if(root==NULL)
    {
         return createNode(val);
    }

    if(val > root->data)
    {
        root->right = insertion(root->right,val);
    }
    else{
      root->left = insertion(root->left,val);
    }

    return root;
}
