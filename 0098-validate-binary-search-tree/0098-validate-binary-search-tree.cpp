class Solution {
public:
    void inorder(TreeNode *root , vector <int>& v){
        if(root==NULL) return ; 
        inorder(root->left , v);
        v.push_back(root->val) ; 
        inorder(root->right , v);
    }
   
    bool isValidBST(TreeNode* root) {
        vector <int> v;
        inorder(root, v); 

        for(int i= 0 ; i<v.size()-1 ; i++){
            if(v[i]>=v[i+1]) return false; 
        }
        return true; 
    }
};

////BRUTE FORCE
// class Solution {
// public:
//     long long mx(TreeNode *root){
//         if(!root) return LLONG_MIN; 
//         return max((long long)(root->val) , max(mx(root->left), mx(root->right))) ; 
//     }
//     long long mn(TreeNode *root){
//         if(!root) return LLONG_MAX; 
//         return min((long long)(root->val) , min(mn(root->left), mn(root->right))) ; 
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL) return true; 

//         else if((long long)(root->val) <  mn(root->right) && (long long)(root->val) > mx(root->left)) {
//             return isValidBST(root->left) && isValidBST(root->right) ; 
//         }
//         else return false; 
//     }
// };