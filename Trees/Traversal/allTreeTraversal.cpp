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

Node* buildTree(){
  int val;
  cin>>val;

  if(val==-1) return NULL;

  Node *root = new Node(val);
  root->left = buildTree();
  root->right = buildTree();

  return root;
}
vector<vector<int>> BFS(Node *root){
  vector<vector<int>>ans;
  if(!root) {cout<<"No data encountered"; return ans; }

  queue<Node*>q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();

    vector<int>subVectr;
    for(int i=0;i<size;i++){
      Node* tree = q.front();
      q.pop();
      if(tree->left) q.push(tree->left);
      if(tree->right) q.push(tree->right);
      subVectr.emplace_back(tree->data);
    }
    ans.emplace_back(subVectr);
  }
  return ans;
}

void preorder(Node *root){
  if(!root){
    cout<<"No data encountered\n";
    return;
  }

  stack<Node*>st;
  st.push(root);

  while(!st.empty()){
    Node* front = st.top();
    st.pop();
    cout<<front->data<<" ";
    if(front->right) st.push(front->right);
    if(front->left) st.push(front->left);
    }

}
void inorder(Node *root){
  stack<Node*>stk;

  Node* node = root;

  while(true){
    if(node){
      stk.push(node);
      node = node->left;
    } else{
      if(stk.empty()) break;
      node = stk.top();
      stk.pop();
      cout<<node->data<<" ";
      node = node->right;
    }
  }
}
void postorder_using_2stack(Node *root){
  if(!root){
    cout<<"No data encountered";
    return;
  } 

  stack<Node*> stk1, stk2;

  stk1.push(root);

  while(!stk1.empty()){
    Node *top = stk1.top();
    stk1.pop();
    stk2.push(top);

    if(top->left) stk1.push(top->left);
    if(top->right) stk1.push(top->right);
  }

  while(!stk2.empty()){
    cout<<stk2.top()->data<<" ";
    stk2.pop();
  }
}

void postorder_using_1stack(Node *root){
  if(!root){
    cout<<"No data encountered";
    return;
  }

  Node* curr = root;
  stack<Node*>st;
  vector<int> post;
  while(curr!=NULL || !st.empty()){
    if(curr!=NULL){
      st.push(curr);
      curr = curr->left;
    }
    else{
      Node* temp = st.top()->right;
      if(!temp){
        temp = st.top();
        st.pop();
        post.push_back(temp->data);
        while(!st.empty() || temp==st.top()->right){
          temp = st.top();
          st.pop();
          post.push_back(temp->data);
        }
      } 
      else{
        curr = temp;
      }
    }
  }
  for(auto it: post){
    cout<<it<<" ";
  }
}
int main(){
  
 Node* root = buildTree();

/*
 vector<vector<int>>printBFS = BFS(root);

 for(vector<int>i: printBFS){
   for(int x: i){
     cout<<x<<" ";
   }
   cout<<"\n";
 } */

 //preorder(root);
 //inorder(root);


 //PostOrder using 2 stacks
 //postorder_using_2stack(root);


 //PostOrder using 1 stack
 postorder_using_1stack(root);
return 0;
}
