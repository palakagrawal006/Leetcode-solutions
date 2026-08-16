class Solution {
public:
    int count = 0 ; 
    void helper(TreeNode* root, long long target, int &count){
        if(root==NULL)return ; 

        if(target==(long long)(root->val)){
            count++; 
        }
        helper(root->left , target-(long long)(root->val), count) ; 
        helper(root->right , target-(long long)(root->val), count) ; 
    }

    int pathSum(TreeNode* root, int target) {
        int count =0 ;
        if(!root) return 0; 
        helper(root, (long long)(target), count) ;  //for root
        
        count+= (pathSum(root->left, target) + pathSum(root->right, target));
        return count; 
    }
};