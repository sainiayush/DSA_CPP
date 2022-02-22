/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root){
    return (root->left==NULL and root->right==NULL);
}
void leftTraversal(vector<int>& ans,TreeNode<int>* root){
    TreeNode<int>* node=root->left;
    while(node){
		if(!isLeaf(node)) ans.emplace_back(node->data);
        if(node->left) node=node->left;
        else node=node->right;
    }
}
void leafTraversal(vector<int>&ans, TreeNode<int>* root){
    TreeNode<int>* node=root;
    if(isLeaf(node)){
        ans.emplace_back(node->data);
        return;
    }
    if(node->left) leafTraversal(ans,node->left);
    if(node->right) leafTraversal(ans,node->right);
}
void rightTraversal(vector<int>&ans, TreeNode<int>* root){
    TreeNode<int>* node=root->right;
    
    stack<TreeNode<int>*>stk;
    
    while(node){
        if(!isLeaf(node)) stk.push(node);
        if(node->right) node=node->right;
        else node = node->left;
    }
    
    while(!stk.empty()){
        ans.emplace_back(stk.top()->data);
        stk.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!root) return ans;
    
    if(!isLeaf(root)) ans.emplace_back(root->data);
    if(root->left) leftTraversal(ans,root);
   	leafTraversal(ans,root);
    if(root->right) rightTraversal(ans,root);
    
    return ans;
}
