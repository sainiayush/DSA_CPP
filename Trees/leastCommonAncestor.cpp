Node* lcA(Node* root, Node* p, Node* q){
  if(!root || root == p || root == q) return root;

  Node* left = lcA(root->left, p, q);
  Node* right = lcA(root->right, p, q);

  if(!left) return right;
  if(!right) return left;
  else return root;
}
