int getMaxTime(Node* root, unordered_map<Node*, Node*>& parent_tracker, Node* res){
  unordered_map<Node*, bool>visited;

  queue<Node*> q;
  q.push(res);

  int fl;
  int time(0);
  
  visited[res] = true;

  while(!q.empty()){
    int sz = q.size();
    fl=0;
    loop(i,0,sz){
      Node* front = q.front();
      q.pop();

      if(front->left && !visited[front->left]){
        q.push(front->left);
        fl=1;
        visited[front->left] = true;
      }
      if(front->right && !visited[front->right]){
        fl=1;
        q.ps(front->right);
        visited[front->right] = true;
      }
      if(parent_tracker[front] && !visited[parent_tracker[front]]){
        fl=1;
        q.ps(parent_tracker[front]);
        visited[parent_tracker[front]] = true;
      }
    }
    if(fl) time++;
  }
  return time;
}
Node* markParentNodes(Node *root, unordered_map<Node*, Node*>& parent_tracker, int target){
  Node* res;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(front->data == target) res = front; 
    if(front->left){
      parent_tracker[front->left] = front;
      q.push(front->left);
    }
    if(front->right){
      parent_tracker[front->right] = front;
      q.push(front->right);
    }
  }
  return res;
}

int getMaxTimetoBurnBT(Node* root, int x){
  if(!root) return 0;

  unordered_map<Node*, Node*> parent_tracker;

  Node* res = markParentNodes(root, parent_tracker, x);

  int time = getMaxTime(root, parent_tracker, res);
  return time;
}
