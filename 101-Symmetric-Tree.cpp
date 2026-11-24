class Solution {
public:
    void inverse(TreeNode *root){
        if(!root) return;

        swap(root->left , root->right) ; 
        inverse(root->left);
        inverse(root->right);
    }
    bool issame(TreeNode* l , TreeNode* r){
        if(!l && !r) return true; 
        if(!l || !r ||l->val != r->val) return false; 

        return issame(l->left , r->left) &&
        issame(l->right , r->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true; 

        inverse(root->left) ; 
        return issame(root->left, root->right) ; 

    }
};