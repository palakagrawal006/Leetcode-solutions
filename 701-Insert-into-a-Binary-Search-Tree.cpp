class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* n = new TreeNode(val) ; 
            return n ; 
        }

        else if(root->val> val){
            if(!root->left){
                TreeNode* n = new TreeNode(val) ; 
                root->left = n ;
                return root;
            }
            else insertIntoBST(root->left, val) ; 
        }
        else {
            if(!root->right){
                TreeNode* n = new TreeNode(val) ; 
                root->right = n ;
                return root;
            }
            else insertIntoBST(root->right, val) ; 
        }
        return root; 
    }
};