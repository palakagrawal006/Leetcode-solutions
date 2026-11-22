
class Solution {
public:
    int maxi = INT_MIN ; 
    int maxLen(TreeNode *root){
        if(!root) return 0;
        return 1 + max(maxLen(root->left) , maxLen(root->right)) ; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ; 

        int leftMax = maxLen(root->left) ; 
        int rightMax = maxLen(root->right); 
        maxi = max(maxi , leftMax + rightMax); 

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi ;

    }
};