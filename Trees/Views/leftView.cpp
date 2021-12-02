vector<int>leftView(Node *node){
  vector<int>ans;

  if(!node) return ans;

  recursionLeft(node,0,ans);

  return ans;
}
