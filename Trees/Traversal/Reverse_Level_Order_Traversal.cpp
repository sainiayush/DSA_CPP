vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    
    if(!root)
    return ans;
    
    stack<int>s;
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty()){
        Node* f=q.front();
        s.push(f->data);
        
        q.pop();
        if(f->right)
        q.push(f->right);
        
        if(f->left)
        q.push(f->left);
        
        
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
