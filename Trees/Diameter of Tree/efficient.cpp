 pair<int,int> diameter_util(Node* root){
    if(root==NULL){
            pair<int,int>bp;
            bp.first=0;
            bp.second=0;
            return bp;
        }
        pair<int,int> lp = diameter_util(root->left);
        pair<int,int> rp = diameter_util(root->right);
        
        pair<int,int>np;
        np.first=max(lp.first,rp.first)+1;
        
        int fes = lp.first+rp.first+1;
        
        np.second=max(fes,(max(lp.second,rp.second)));
        
        return np;
    }
    int diameter(Node* root) {
         pair<int,int>ans=diameter_util(root);
        return ans.second;
    }
