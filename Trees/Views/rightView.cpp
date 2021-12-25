void recursionRight(Node *root, int level, vector<int> &res) {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursionRight(root->right, level+1, res);
        recursionRight(root->left, level+1, res);
    }
vector<int>rightView(Node *node){
  vector<int>ans;

  if(!node) return ans;

  recursionRight(node,0,ans);

  return ans;
}
