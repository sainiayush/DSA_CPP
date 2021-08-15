vector<int> reverseLevelOrder(Node *root)
{
    vector<int>res;
    
    if(!root)
    return res;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        struct Node* temp=q.front();
        
        res.push_back(temp->data);
        
        q.pop();
        
        if(temp->right)
        q.push(temp->right);
        
        if(temp->left)
        q.push(temp->left);
    }
    reverse(res.begin(),res.end());
    return res;
}
