class Solution {
public:
    TreeNode* build(vector<int>& pre,int prelo, int prehi, vector<int>& in, int inlo, int inhi){ 
        // base case
        if(prelo>prehi)return NULL; 

        // root ele= pre ka 1st ele = prelo
        TreeNode *root = new TreeNode(pre[prelo]) ; 

        if(prelo==prehi )return root; 

        // find left subtree and right subtree using inorder
        int i= inlo ; 
        while(i<=inhi){
            if(in[i]==pre[prelo]) break; 
            i++;
        }

        int leftCount= i-inlo ;
        int rightCount= inhi-i;

        root->left = build(pre, prelo+1 , prelo+leftCount, in, inlo , i-1); 
        root->right = build(pre, prelo+leftCount+1,prehi, in, i+1, inhi); 

        return root;  
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(pre, 0 , pre.size()-1, in, 0 , in.size()-1); 
    }
};