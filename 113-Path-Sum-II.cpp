
class Solution {
public:
    void helper(TreeNode* root, int t, vector<vector<int>> &ans,vector<int> v){
        if(!root) return ; 
        if(!root->left && !root->right && root->val==t) {
            v.push_back(root->val) ; 
            ans.push_back(v) ;
            return  ; 
        }
         v.push_back(root->val) ; 
        helper(root->left, t-root->val, ans , v); 
        helper(root->right, t-root->val, ans , v);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v ; 

        helper(root, targetSum, ans , v);
        return ans ;
    }
};