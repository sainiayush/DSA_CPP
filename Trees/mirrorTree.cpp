void swapPointers(TreeNode* root){
        if(!root)
            return;
        swapPointers(root->left);
        swapPointers(root->right);
        
        // Swap the child pointers
        
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
       swapPointers(root);
        return root;
    }
