int maxPath(Node *root, int& maxi){
  if(!root) return 0;

  int left = max(0,maxPath(root->left,maxi));
  int right = max(0,maxPath(root->right,maxi));

  maxi = max(maxi,root->data+left+right);

  return max(left,right)+root->data;
}

int maxPathsum (Node *root){
  int maxi = INT_MIN;
  maxPath(root, maxi);
  return maxi;

}
