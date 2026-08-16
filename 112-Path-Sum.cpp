class Solution {
public:
    bool helper(TreeNode* root, int target){
        if(!root)return false; 
        if(root->left==NULL && root->right==NULL && root->val == target) return true; 


        bool left = helper(root->left, target-root->val) ; 
        bool right = helper(root->right, target-root->val) ; 
        return left || right ; 
    }
    bool hasPathSum(TreeNode* root, int target) {
        return helper(root, target) ; 
    }
};