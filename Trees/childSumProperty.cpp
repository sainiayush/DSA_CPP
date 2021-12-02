void childSumProperty(Node* root){
  if(!root) return ;

  int childSum(0);

  if(root->left) childSum += root->left->data;
  if(root->right) childSum += root->right->data;

  if(childSum>=root->data){
    root->data = childSum;
  } else{
    if(root->left) root->left->data = root->data;
    if(root->right) root->right->data = root->data;
  }

  childSumProperty(root->left);
  childSumProperty(root->right);

  int tot=0;
  if(root->left) tot += root->left->data;
  if(root->right) tot += root->right->data;

  if(root->left or root->right) root->data = tot;
}
