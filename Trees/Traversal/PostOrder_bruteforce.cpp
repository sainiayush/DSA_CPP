void postorder_traversal(node* root){
 if(!root)
   return;
  
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  cout<<root->key<<" ";
  
}
