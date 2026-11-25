class Solution {
public:
    bool helper(TreeNode* root, int t){
        if(!root) return false; 
        if(!root->left && !root->right && t == root->val ){
            return true;
        }

        return helper(root->left, t-root->val) || 
        helper(root->right, t-root->val) ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root , targetSum) ; 
    }
};