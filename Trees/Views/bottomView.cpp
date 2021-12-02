vector<int> bottomView(Node *root){
  vector<int> ans;

  if(!root) return ans;

  map<int,int> mp;
  queue<pair<Node*, int>>q;
  q.push({root,0});

  while(!q.empty()){
    auto it = q.front();
    q.pop();
    Node* curr = it.first;
    int x = it.second;

    mp[x]=curr->data;

    if(curr->left) q.push({curr->left, x-1});
    if(curr->right) q.push({curr->right, x+1});
  }

  for(auto m: mp){
    ans.push_back(m.second);
  }
  return ans;
}
