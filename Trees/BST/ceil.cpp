int findCeil(Node* root, int key){
  int ceil = -1;
  
  while(root){
    if(root->data == key){
      ceil = root->data;
      return ceil;
    } else if(root->data < key) root = root->right;
    else{
      ceil = root->data;
      root = root->left;
    }
  }
  return ceil; 
}
