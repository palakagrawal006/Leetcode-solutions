class Solution {
public:
    long long mx(TreeNode *root){
        if(!root) return LLONG_MIN; 
        return max((long long)(root->val) , max(mx(root->left), mx(root->right))) ; 
    }
    long long mn(TreeNode *root){
        if(!root) return LLONG_MAX; 
        return min((long long)(root->val) , min(mn(root->left), mn(root->right))) ; 
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true; 

        else if((long long)(root->val) <  mn(root->right) && (long long)(root->val) > mx(root->left)) {
            return isValidBST(root->left) && isValidBST(root->right) ; 
        }
        else return false; 
    }
};