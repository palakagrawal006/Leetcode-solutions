class Solution {
public:
    TreeNode* construct(vector<int>& in, int il, int ih, vector<int>& post,int pl , int ph ){
        if(pl>ph) return NULL ; 

        TreeNode *root = new TreeNode(post[ph]);
        if(pl== ph) return root ; 

        int i = il ; //index of root in inorder 
        while(i<ih){
            if(in[i]== post[ph]) break; 
            i++; 
        }

        int leftCount= i- il;   
        int rightCount= ih- i;

        root->left = construct(in , il , i-1, post, pl, pl+leftCount-1); 
        root->right = construct(in , i+1 , ih, post, pl+leftCount, ph-1); 

        return root; 
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return construct (in, 0, in.size()-1, post, 0 , post.size()-1) ; 
    }
};