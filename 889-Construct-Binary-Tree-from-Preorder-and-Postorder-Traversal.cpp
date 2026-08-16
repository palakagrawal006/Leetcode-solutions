class Solution {
public:
TreeNode* build(vector<int>& pre,int prelo, int prehi, vector<int>& post, int polo, int pohi){ 
        // base case
        if(prelo>prehi)return NULL; 

        // root ele= pre ka 1st ele = prelo
        TreeNode *root = new TreeNode(pre[prelo]) ; 

        if(prelo==prehi )return root; 

        // find left subtree using postorder
        int i= polo ; 
        while(i<=pohi){
            if(post[i]==pre[prelo+1]) break; 
            i++;
        }

        int leftCount= i-polo+1;
        // int rightCount= inhi-i;

        root->left = build(pre, prelo+1 , prelo+leftCount, post, polo , i); 
        root->right = build(pre, prelo+leftCount+1,prehi, post, i+1, pohi-1); 

        return root;  
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre, 0 , pre.size()-1, post, 0 , post.size()-1);
    }
};