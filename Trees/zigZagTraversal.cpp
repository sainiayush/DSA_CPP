vector<vector<int>> spiralTraversal(Node *root){
  vector<vector<int>>ans;
  if(!root) return ans;

  bool leftToRight = true;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();

    vector<int>v(size);
    for(int i=0;i<size;i++){
      Node* front = q.front();
      q.pop();
      int index = (leftToRight)? i : size-i-1;
      v[index] = front->data;

      if(front->left) q.push(front->left);
      if(front->right) q.push(front->right);
    }
    leftToRight = !leftToRight;
    ans.emplace_back(v);
  }

  return ans;
}
