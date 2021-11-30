vector<vector<int>> verticalOrderTraversal(Node *root){

  vector<vector<int>> ans;
  if(!root) return ans;
  
  queue<pair<Node*, pair<int,int>>>order;

  map<int, map<int, multiset<int>>> nodes;
  
  order.push({root,{0,0}});

  while(!order.empty()){
    auto front = order.front();
    order.pop();

    Node* curr = front.first;
    int x = front.second.first, y = front.second.second;

    nodes[x][y].insert(curr->data);

    if(curr->left) order.push({curr->left, {x-1, y+1}});
    if(curr->right) order.push({curr->right, {x+1, y+1}});
  }

  for(auto p: nodes){
    vector<int>col;
    for(auto q: p.second){
      col.insert(col.end(), q.second.begin(),q.second.end());
    }
    ans.emplace_back(col);
  }

  return ans;
}
