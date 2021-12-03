vector<int> morrisInorder(Node* node){
  vector<int> result;
  if(!node) return result;

  Node* curr = node;

  while(curr){
    if(!curr->left){
      result.push_back(curr->data);
      curr = curr->right;
    } else{
      Node* prev = curr->left;

      while(prev->right and prev->right != curr){
        prev = prev->right;
      }

      if(!prev->right){
        prev->right = curr;
        curr = curr->left;
      } else{
        prev->right = NULL;
        result.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
  return result;

}
