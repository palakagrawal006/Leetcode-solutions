class Solution {
public:
    int level (TreeNode *root){
        if(!root) return 0 ; 

        return 1+max(level(root->left) , level(root->right));
    }

    void fill(TreeNode *root, vector<vector<int>> &ans , int level ){
        if(!root) return ; 
        ans[level].push_back(root->val) ; 
        fill(root->left , ans, level+1) ;
        fill(root->right , ans, level+1) ;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = level(root) ; // no of levels in tree 

        vector<vector<int>> ans ; 

        for(int i = 1; i<=n ; i++){
            vector <int> v ; 
            ans.push_back(v) ;  
        }
        fill(root, ans, 0);
        return ans ;
    }
};


// class Solution {
// public:
//     int level (TreeNode *root){
//         if(!root) return 0 ; 

//         return 1+max(level(root->left) , level(root->right));
//     }

//     void fill(TreeNode *root, vector<int> &v , int level , int curr){
//         if(!root) return ; 
//         if(level == curr) {
//             v.push_back(root->val) ; 
//             return ;
//         }

//         fill(root->left , v, level, curr+1) ;
//         fill(root->right , v, level, curr+1) ;
//     }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         int n = level(root) ; // no of levels in tree 

//         vector<vector<int>> ans ; 

//         for(int i = 1; i<=n ; i++){
//             vector <int> v ; 

//             fill(root, v, i , 1) ;

//             ans.push_back(v) ;  
//         }
//         return ans ;
//     }
// };