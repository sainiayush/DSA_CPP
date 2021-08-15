vector<int> BFS(node* root){
 vector<int>ans;
  
  if(!root)
    return ans;
  
  queue<node*> q;
  
  q.push(root);
  
  while(!q.empty()){
   node* f=q.front();
    ans.push_back(f->data);
    q.pop();
    
    if(f->lefft)
      q.push(f->left);
    
    if(f->right)
      q.push(f->right);    
  }
  return ans;
  
}
