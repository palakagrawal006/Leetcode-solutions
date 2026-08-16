class Solution {
public:
    int levels(TreeNode *root){
        if(!root)return 0 ; 
        return 1+ max(levels(root->left) , levels(root->right)) ;
    }

    void preorder(vector<int> &ans , TreeNode *root ,int level){
        if(!root)return ;
        ans[level] = root->val ;
         
        preorder(ans, root->left, level+1);
        preorder(ans, root->right , level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root) ; 
        vector <int> ans(n , 0); 

       preorder( ans, root, 0) ; 

        return ans ; 
    }
};

// class Solution {
// public:
//     int levels(TreeNode *root){
//         if(!root)return 0 ; 
//         return 1+ max(levels(root->left) , levels(root->right)) ;
//     }

//     void rightView(vector<int> &ans , int level, int curr , TreeNode *root){
//         if(!root)return ;
//         if(level == curr){
//             ans[level] = root->val ;
//             return ; 
//         }
//         rightView(ans, level, curr+1, root->left);
//         rightView(ans, level, curr+1, root->right);
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         int n = levels(root) ; 
//         vector <int> ans(n , 0); 

//         for(int i = 0 ; i<n; i++){
//             rightView(ans,i, 0, root) ; 
//         }

//         return ans ; 
//     }
// };