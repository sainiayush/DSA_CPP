bool isLeaf(Node *root){
  return (!root->left && !root->right);
}


// Function for leftSide Boundary Traversal
void leftTraversal(Node *root, vector<int>& ans){
  Node* curr = root->left;
  while(curr){
    if(!isLeaf(curr)) ans.emplace_back(curr->data);
    if(curr->left) curr = curr->left;
    else curr = curr->right;
  }
}

// Function for traversing all the leafs in inorder fashion
void leafTraversal(Node *root, vector<int>& ans){
 
  if(isLeaf(root)) {
    ans.emplace_back(root->data);
    return;
  }
  if(root->left) leafTraversal(root->left,ans);
  if(root->right) leafTraversal(root->right,ans);
}

// Function for RightSide Boundary Traversal in reverse order
void rightTraversal(Node *root, vector<int>& ans){
  Node* curr= root->right;

  stack<int>temp;

  while(curr){
   if(!isLeaf(curr)) temp.push(curr->data);
    if(curr->right) curr = curr->right;
    else curr = curr->left;
  }

  while(!temp.empty()){
    ans.emplace_back(temp.top());
    temp.pop();
  }
}
vector<int> boundaryTraversal(Node *root){
  vector<int>ans;
  if(!root) return ans;

  if(!isLeaf(root)) ans.emplace_back(root->data);
  leftTraversal(root, ans);
  leafTraversal(root, ans);
  rightTraversal(root, ans);

  return ans;
}
