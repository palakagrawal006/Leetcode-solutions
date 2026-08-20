class Solution {
public:
    void inorder(TreeNode *root ,int &count , int k, int &ans){
        if(root==NULL) return ; 

        inorder(root->left , count, k , ans); 
        count++;
        if(count==k) {
            ans = root->val; 
            return;
        }
        inorder(root->right , count, k ,ans); 
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0 ; 
        int ans ; 
        inorder(root, count, k, ans) ; 
        return ans; 
    }
};
// class Solution {
// public:
//     void inorder(TreeNode *root ,vector<int>& v){
//         if(root==NULL) return; 

//         inorder(root->left ,v); 
//         v.push_back(root->val) ; 
//         inorder(root->right , v); 
 
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v; 
//         inorder(root, v) ; 

//         return v[k-1] ; 
//     }
// };