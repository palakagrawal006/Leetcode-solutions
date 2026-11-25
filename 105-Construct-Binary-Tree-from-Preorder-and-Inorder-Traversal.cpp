class Solution {
public:
    TreeNode* construct(vector<int>& pre,int pl , int ph, vector<int>& in, int il, int ih ){
        if(pl>ph) return NULL ; 

        TreeNode *root = new TreeNode(pre[pl]);
        if(pl== ph) return root ; 

        int i = il ; //index of root in inorder 
        while(i<ih){
            if(in[i]== pre[pl]) break; 
            i++; 
        }

        int leftCount= i- il;   
        int rightCount= ih- i;

        root->left = construct(pre, pl+1, pl+leftCount , in , il , i-1); 
        root->right = construct(pre,  pl+leftCount+1 , ph , in , i+1 , ih); 

        return root; 


    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return construct (pre, 0 , pre.size()-1 , in, 0, in.size()-1) ; 
    }
};