void BFS_NULL(Node* root){
 if(!root)
   return;
  
  queue<Node*>q;
  q.push(root);
  q.push(NULL);
  
  while(!q.empty()){
   Node* f= q.front();
    if(!f){
     cout<<endl;
      q.pop();
     if(!q.empty())
       q.push(NULL);
    } else{
      cout<<f->data<<" ";
      
      if(f->left)
        q.push(f->left);
      
      if(f->right)
        q.push(f->right);
      
    }
  }
  
}
