void markParentNodes(Node *root, unordered_map<Node*, Node*>& parent_tracker){
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(front->left){
      parent_tracker[front->left] = front;
      q.push(front->left);
    }
    if(front->right){
      parent_tracker[front->right] = front;
      q.push(front->right);
    }
  }
}
vi markNodesatDistK(Node *root, int k, Node* target){
  vi ans;

  if(!root) return ans;

  unordered_map<Node*, Node*> parent_tracker;
  markParentNodes(root, parent_tracker);

  unordered_map<Node* ,bool>visited;
  visited[target] = true;

  queue<Node*> q;
  q.push(target);

  int level(0);
  while(!q.empty()){
    int size = q.size();

    if(level++ == k) break;

    loop(i,0,size){
      Node* front = q.front();
      q.pop();
      if(front->left && !visited[front->left]){
        q.push(front->left);
        visited[front->left] = true;
      }
      if(front->right && !visited[front->right]){
        q.push(front->right);
        visited[front->right] = true;
      }
      if(parent_tracker[front] && !visited[parent_tracker[front]]){
        q.push(parent_tracker[front]);
        visited[parent_tracker[front]] = true;
      }
    }
  }

  while(!q.empty()){
      Node* curr = q.front();
      q.pop();
      ans.eb(curr->data);
    }
    
    return ans;
}
