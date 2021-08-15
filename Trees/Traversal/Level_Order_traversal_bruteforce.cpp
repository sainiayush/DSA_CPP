int height(Node* root){
  if(!root)
    return 0;
  
  return 1+max(root->left,root->right);
}
void PrintbyLevel(Node* root, int level){
  if(!root)
    return;
  if(level==1)
    cout<<root->key<<" ";
  else{
    PrintbyLevel(root->left,level-1);
    PrintbyLevel(root->right,level-1);
  }
  
}
void BFS(Node* root){
 if(!root)
   return;
  int h = height(root);
  cout<<root->key<<" ";
  for(int i=1;i<=h;i++){
   PrintbyLevel(root,i); 
  }
}
