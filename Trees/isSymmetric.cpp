bool isSymmetricHelp(Node* left, Node* right){
  if(!left || !right) return left==right;

  if(left->data != right->data) return false;

  return (isSymmetricHelp(left->left, right->right) 
          && 
          isSymmetricHelp(left->right, right->left));
}
bool isSymmetric(Node *root){
  
  return (!root || isSymmetricHelp(root->left, root->right));
}
