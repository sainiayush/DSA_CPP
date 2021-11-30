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

int check(Node *node){
  if(!node) return 0;

  int leftHeight = check(node->left);
  if(leftHeight==-1) return -1;

  int rightHeight = check(node->right);
  if(rightHeight==-1) return -1;

  if(abs(leftHeight-rightHeight)>1) return -1;

  return 1+max(leftHeight,rightHeight);
}
bool balanced(Node* root){
  return check(root)!=-1;
}
int main(){
  Node* root = buildTree();

  if(balanced(root)) cout<<"Balanced";
  else cout<<"Not balanced";
return 0;
}
