int maxWidth(Node *root){
  if(!root) return 0;

  int maxi = 0;

  queue<pair<Node*, int>>q;
  q.ps({root,0});

  while(!q.empty()){
    int sz = q.size();
    int min = q.front().second;
    int first(0), last(0);
    int curr_level(0);
    loop(i,0,sz){
      Node* front = q.front().first;
      curr_level = q.front().second - min;
      q.pop();
      if(i==0) first = curr_level;
      if(i==sz-1) last = curr_level;
      
      if(front->left) q.push({front->left, 2*curr_level+1});
      if(front->right) q.push({front->right, 2*curr_level+2});
    }
    maxi = max(maxi, last-first+1);
  }
  return maxi;
}
