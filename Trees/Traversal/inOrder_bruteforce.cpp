void inOrder(node *root){
  if(!root)
    return;
  
  inOrder(root->left);
  cout<<root->key<<" ";
  inOrder(root->right);
}
