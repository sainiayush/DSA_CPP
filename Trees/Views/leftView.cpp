void recursionLeft(Node *root, int level, vector<int> &res) {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursionLeft(root->left, level+1, res);
        recursionLeft(root->right, level+1, res);
    }
vector<int>leftView(Node *node){
  vector<int>ans;

  if(!node) return ans;

  recursionLeft(node,0,ans);

  return ans;
}
