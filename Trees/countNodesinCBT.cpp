int leftHeight(Node* left){
  int hght(0);

  while(left){
    hght++;
    left = left->left;
  }
  return hght;
}

int rightHeight(Node* right){
  int hght(0);

  while(right){
    hght++;
    right = right->right;
  }
  return hght;
}

int countNodes(Node* root){
  if(!root) return 0;

  int left = leftHeight(root);
  int right = rightHeight(root);

  if(left==right) return (1<<left)-1;

  return 1 + countNodes(root->left) + countNodes(root->right);
}
