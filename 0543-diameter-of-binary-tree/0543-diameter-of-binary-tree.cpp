
// by dp-- hash map
class Solution {
public:
    void helper(TreeNode* root, int& maxi, unordered_map<TreeNode* , int> &dp){
        if(!root) return ; 

        int leftLen = maxLength(root->left, dp) ;
        int rightLen = maxLength(root->right, dp) ;
        maxi = max(maxi ,leftLen +rightLen)  ;

        helper(root->left , maxi, dp);
        helper(root->right , maxi, dp );
    }

    int maxLength(TreeNode* root, unordered_map<TreeNode* , int> &dp){
        if(!root) return 0 ; 
        if(dp.find(root)!= dp.end()) return dp[root] ; 

        int maxi = 1+ max(maxLength(root->left, dp) , maxLength(root->right, dp));
        return dp[root] =  maxi ; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = 0 ; //reinitialise
       unordered_map<TreeNode* , int> dp; 
    //    store node and its level 

        helper(root, maxi, dp) ; 
        return maxi ;
    }
};

// // avoid global variable
// class Solution {
// public:
//     void helper(TreeNode* root, int& maxi){
//         if(!root) return ; 

//         int leftLen = maxLength(root->left) ;
//         int rightLen = maxLength(root->right) ;
//         maxi = max(maxi ,leftLen +rightLen)  ;

//         helper(root->left , maxi);
//         helper(root->right , maxi );
//     }

//     int maxLength(TreeNode* root){
//         if(!root) return 0 ; 
//         int maxi = 1+ max(maxLength(root->left) , maxLength(root->right));
//         return maxi ; 
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//        int maxi = 0 ; //reinitialise
//         helper(root, maxi) ; 
//         return maxi ;
//     }
// };


// class Solution {
// public:
//     int maxi = INT_MIN ;

//     int maxLength(TreeNode* root){
//         if(!root) return 0 ; 

//         int maxi = 1+ max(maxLength(root->left) , maxLength(root->right));
//         return maxi ; 
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         // find left max length and right max length -- add --- for all nodes
//         if(!root) return 0 ; 

//         int leftLen = maxLength(root->left) ;
//         int rightLen = maxLength(root->right) ;
//         maxi = max(maxi ,leftLen +rightLen)  ; 

//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);

//         return maxi;
//     }
// };