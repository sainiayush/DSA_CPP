int height(Node* root){
 if(!root)
   return 0;
  return 1+max(root->left,root->right);
  }
void printGivenLevel(Node* root, int k){
 if(!root)
   return;
 if(k==1)
    cout<<root->data<<" ";
 else{
  printGivenLevel(root->left,k-1);
  printGivenLevel(root->right,k-1);
 }
  
}
void Reverse_level_order(Node* root){
 if(!root)
   return;
  
  int h=height(root);
  int i;
  
  for(i=h;i>=0;i--)
    printGivenLevel(root,i);
}
