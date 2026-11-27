class Solution {
public:
    void inorder(TreeNode* root , bool &flag , TreeNode *prev){
        if(!root) return  ; 
        inorder(root->left , flag , prev) ; 

        if(prev){
            if(prev->val >= root->val) {
                flag = false; 
                return ;
            }
        }
        prev = root; 
        inorder(root->right ,flag , prev) ; 
    }
    bool isValidBST(TreeNode* root) {
         bool flag = true; 
         TreeNode *prev = NULL ; 
        inorder(root, flag , prev) ;

        return flag;
    }
};
// class Solution {
// public:
//     void inorder(TreeNode* root , vector<int> &v){
//         if(!root) return  ; 
//         inorder(root->left , v) ; 
//         v.push_back(root->val) ; 
//         inorder(root->right , v) ; 
//     }
//     bool isValidBST(TreeNode* root) {
//         vector<int> v ; 
//         inorder(root, v) ;

//         for(int i= 0; i<v.size()-1; i++){
//             if(v[i]>= v[i+1]) return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     long long findMax(TreeNode* root){
//         if(!root) return LLONG_MIN ; 
//         return max((long long)root->val , max(findMax(root->left) , findMax(root->right))) ; 
//     }
//     long long findMin(TreeNode* root){
//         if(!root) return LLONG_MAX ; 
//         return min((long long)root->val , min(findMin(root->left) , findMin(root->right))) ; 
//     }
//     bool isValidBST(TreeNode* root) {
//         // max val(left) < root->val && min val(right) > root->val 
//         if(root==NULL) return true; 
//         long long maxLeft = findMax(root->left) ; 
//         long long minRight = findMin(root->right) ; 

//         if(maxLeft <  (long long)root->val && minRight > (long long)root->val) {
//             return isValidBST(root->left) && isValidBST(root->right) ;
//         }
//         return false; 
//     }
// };