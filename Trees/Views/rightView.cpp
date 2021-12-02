vector<int>rightView(Node *node){
  vector<int>ans;

  if(!node) return ans;

  recursionRight(node,0,ans);

  return ans;
}
