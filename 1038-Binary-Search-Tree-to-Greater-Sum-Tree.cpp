class Solution {
public:
    void inorder(TreeNode *root , vector <int>& v, int &sum){
        if(root==NULL) return ; 
        inorder(root->right , v, sum);
        root->val += sum ; 
        sum = root->val ; 
        inorder(root->left , v , sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector <int> v;
        int sum = 0 ; 
        inorder(root, v, sum ); 
        return root; 
    }
};