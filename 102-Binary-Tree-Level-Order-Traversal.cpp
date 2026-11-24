class Solution {
public:
    int level(TreeNode *root){
        if(!root) return 0 ; 
        return 1 + max(level(root->left)  , level(root->right)) ; 
    }
    void fill(TreeNode* root, vector<int>& v, int lev , int l){
        if(!root) return ;
        if(lev == l){
            v.push_back(root->val) ; 
            return ;
        }
        fill(root->left, v , lev , l+1);
        fill(root->right, v , lev , l+1);
    }
    void helper(TreeNode* root,vector<vector<int>>& ans ){
        int n = level(root) ;

        for(int i = 1; i<=n ; i++){
            vector<int> v ; 
            ans.push_back(v) ; 

            fill(root, ans[i-1] , i , 1) ;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans ;

        helper(root , ans) ; 
        return ans ; 
    }
};