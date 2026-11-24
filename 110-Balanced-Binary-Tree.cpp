class Solution {
public:
    int length(TreeNode* root){
        if(!root) return 0; 

        return 1 + max( length(root->left) , length(root->right)) ; 
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true; 

        int left = length(root->left);
        int right = length(root->right);

        int dif = abs(left - right) ; 
        if(dif>1) return false; 

        return isBalanced(root->left) && isBalanced(root->right);
    }
};