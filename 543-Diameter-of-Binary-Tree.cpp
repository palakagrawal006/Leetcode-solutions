// without global 
class Solution {
public:
    
    int maxLen(TreeNode *root){
        if(!root) return 0;
        return 1 + max(maxLen(root->left) , maxLen(root->right)) ; 
    }
    void helper(TreeNode* root , int& maxi){
        if(!root) return ; 

        int leftMax = maxLen(root->left) ; 
        int rightMax = maxLen(root->right); 
        maxi = max(maxi , leftMax + rightMax); 

        helper(root->left, maxi);
        helper(root->right, maxi);
    }
    int diameterOfBinaryTree(TreeNode *root) {
        int maxi = INT_MIN ; 
        helper(root, maxi) ; 
        return maxi ;
    }
};