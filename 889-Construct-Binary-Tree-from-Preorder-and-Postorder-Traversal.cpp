class Solution {
public:
    TreeNode* construct(vector<int>& pre, int pl, int ph, vector<int>& post,int postl , int posth ){
        if(pl>ph) return NULL ; 

        TreeNode *root = new TreeNode(pre[pl]);
        if(pl== ph) return root ; 

        int i = postl ;
        while(i<=posth){
            if(pre[pl+1]== post[i]) break; 
            i++; 
        }

        int leftCount= i- postl+1;   

        root->left = construct(pre , pl+1 , pl+leftCount, post, postl,i); 
        root->right = construct(pre , pl+leftCount+1, ph, post, i+1, posth-1);  

        return root; 
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct (pre, 0, pre.size()-1, post, 0 , post.size()-1) ; 
    }
};