class Solution {
public:
    long long findMax(TreeNode* root){
        if(!root) return LLONG_MIN ; 
        return max((long long)root->val , max(findMax(root->left) , findMax(root->right))) ; 
    }
    long long findMin(TreeNode* root){
        if(!root) return LLONG_MAX ; 
        return min((long long)root->val , min(findMin(root->left) , findMin(root->right))) ; 
    }
    bool isValidBST(TreeNode* root) {
        // max val(left) < root->val && min val(right) > root->val 
        if(root==NULL) return true; 
        long long maxLeft = findMax(root->left) ; 
        long long minRight = findMin(root->right) ; 

        if(maxLeft <  (long long)root->val && minRight > (long long)root->val) {
            return isValidBST(root->left) && isValidBST(root->right) ;
        }
        return false; 
    }
};