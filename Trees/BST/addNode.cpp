Node* addNodeinBST(Node *root, int x){
  ROOT_basecase(new Node(x))

  Node* curr = root;

  while(true){
    if(curr->data >= x){
      if(curr->left) curr = curr->left;
      else{
        curr->left = new Node(x);
        break;
      }
    } else{
      if(curr->right) curr = curr->right;
      else{
        curr->right = new Node(x);
        break;
      }
    }
  }
  return root;
}
