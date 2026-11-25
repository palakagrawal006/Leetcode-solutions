class Solution {
public:
    void helper(TreeNode* root, long long t, int &count){
        if(!root) return ;

        if(t == (long long)root->val) {
            count++;
        }

        helper(root->left , t-(long long)root->val , count) ;
        helper(root->right , t-(long long)root->val , count) ;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0 ;
        if(!root) return 0 ;  
        
        long long t = targetSum;
        helper(root, t , count) ; 

        count+=  pathSum(root->left , targetSum);
        count+= pathSum(root->right , targetSum);

        return count; 

    }
};