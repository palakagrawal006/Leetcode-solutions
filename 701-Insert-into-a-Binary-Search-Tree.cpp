class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode *node = new TreeNode(val);
           return node;
        }

        else if(root->val > val) { // left
            if(root->left==NULL){ // attach
                TreeNode *node = new TreeNode(val);
                root->left= node;
                return root; 
            }
            else insertIntoBST(root->left , val) ;
        }
        else{
            if(root->right==NULL) {
            TreeNode *node = new TreeNode(val);
            root->right= node;
            return root;
            } 
            else insertIntoBST(root->right , val) ;
        }

        return root; 
    }
};