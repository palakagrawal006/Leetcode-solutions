class Solution {
public:
    int level(TreeNode *root){
        if(!root) return 0 ; 
        return 1+ max(level(root->left), level(root->right)) ; 
    }
    void rightSide(vector<int> &v, TreeNode* root, int l){
        if(!root) return ; 
        v[l] = root->val ; 

        rightSide(v , root->left , l+1);
        rightSide(v , root->right , l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // hrr ek level ka last element 
        int n = level(root) ; 
        vector<int> v (n , 0);
        
        rightSide (v , root, 0) ; 

        return v ; 
    }
};