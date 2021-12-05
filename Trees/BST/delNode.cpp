//Delete a Node Function BEGINS
Node* findLastRightChild(Node *root){
  if(root->right == NULL) return root;

  return findLastRightChild(root->right);
}

Node* helper(Node* root){

  if(root->left == NULL) return root->right;

  else if(root->right == NULL) return root->left;

  else{
    Node* rightChild = root->right;
    Node* lastRightChild = findLastRightChild(root->left);
    lastRightChild->right = rightChild;
    return root->left;
  }
}
Node* delNodeinBST(Node *root, int x){
  ROOT_basecase(NULL)
  
  if(root->data == x){
    return helper(root);
  }

  Node* curr = root;

  while(root){
    if(root->data > x){
      if(root->left && root->left->data == x){
        root->left = helper(root->left);
        break;
      } else{
        root = root->left;
      }
    } else{
      if(root->right && root->right->data == x){
        root->right = helper(root->right);
        break;
      } else{
        root = root->right;
      }
    }
  }
  return curr;
}
// DELETE node function ENDS
