int height(Node *root,int& dia){
  if(!root) return 0;

  int lh = height(root->left,dia);
  int rh = height(root->right,dia);

  dia = max(dia,rh+lh);

  return 1+max(rh,lh);
}
int diameter(Node *root){
  int dia = 0;
  height(root,dia);
  return dia;
}
