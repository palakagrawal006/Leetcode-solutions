class Solution {
public:
    void helper(vector<int>& v , TreeNode* root){
        if(!root) return ;

        v.push_back(root->val) ;
        helper(v , root->left);
        helper(v , root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v ; 
        helper(v  , root) ; 
        return v ; 
    }
};