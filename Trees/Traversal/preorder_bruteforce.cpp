void preorder_traversal(Node *root){
  if(!root)
    return;
 cout<<root->key<<" "; 
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}
