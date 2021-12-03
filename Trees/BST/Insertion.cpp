TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if(!root) return new TreeNode(val);
        
        while(true){
            if(curr->val <= val){
                if(curr->right) curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            } else{
                if(curr->left) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
