#include<bits/stdc++.h>

using namespace std;
struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x){
    data = x;
    left = right = NULL;
  }
};
vector<int>pre, in, post;
Node* buildTree(){
  int val;
  cin>>val;

  if(val==-1) return NULL;

  Node *root = new Node(val);
  root->left = buildTree();
  root->right = buildTree();

  return root;
}

int maxDepthusingLevelOrder(Node* root){
  int depth(0);
  if(!root) return depth;

  queue<pair<Node*, int>>q;
  q.push(make_pair(root,1));

  while(!q.empty()){
    Node *front = q.front().first;
    if(front->left) q.push(make_pair(front->left,q.front().second+1));
    if(front->right) q.push(make_pair(front->right,q.front().second+1));

    if(q.size()==1) depth = q.front().second;
    q.pop();
  }
  return depth;
}

int DepthUsingRecursion(Node* root){
  if(!root) return 0;
  return (1+max(DepthUsingRecursion(root->left),DepthUsingRecursion(root->right)));
}
void preInPostTraversal(Node* root){
  stack<pair<Node*, int>>stk;

  stk.push({root,1});

  if(!root) return;

  while(!stk.empty()){
    auto it = stk.top();
    stk.pop();

    if(it.second==1){
      pre.push_back(it.first->data);
      it.second++;
      stk.push(it);

      if(!it.first->left) stk.push({it.first->left,1});
    } 

    else if(it.second==2){
      in.push_back(it.first->data);
      it.second++;
      stk.push(it);

      if(it.first->right) stk.push({it.first->right,1});
    }

    else{
      post.push_back(it.first->data);
    }
  }

  cout<<"\n\nPre-Order traversal : "; //Root Left Right
  for(auto &x: pre) cout<<x<<" ";
  cout<<"\n\n";

  cout<<"\n\nIn-Order traversal : "; //Left Root Right
  for(auto &x: in) cout<<x<<" ";
  cout<<"\n\n";

  cout<<"\n\nPost-Order traversal : "; //Left Right Root
  for(auto &x: post) cout<<x<<" ";
  cout<<"\n\n";
}
int main(){

  Node* root = buildTree(); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

 // cout<<"Height using Level Order : "<<maxDepthusingLevelOrder(root); // Height : 3
 // cout<<"\nHeight using Level Recursion : "<<DepthUsingRecursion(root); // Height : 3

  preInPostTraversal(root);
return 0;
}
