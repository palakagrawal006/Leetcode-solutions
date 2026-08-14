
class Solution {
public:
  int level (TreeNode *root){
        if(!root) return 0 ; 

        return 1+max(level(root->left) , level(root->right));
    }

    void leftToRight(TreeNode *root, vector<int> &v , int level , int curr){
        if(!root) return ; 
        if(level == curr) {
            v.push_back(root->val) ; 
            return ;
        }

        leftToRight(root->left , v, level, curr+1) ;
        leftToRight(root->right , v, level, curr+1) ;
    }
    void rightToLeft(TreeNode *root, vector<int> &v , int level , int curr){
        if(!root) return ; 
        if(level == curr) {
            v.push_back(root->val) ; 
            return ;
        }

        rightToLeft(root->right , v, level, curr+1) ;
        rightToLeft(root->left , v, level, curr+1) ;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         int n = level(root) ; // no of levels in tree 

        vector<vector<int>> ans ; 

        for(int i = 1; i<=n ; i++){
            vector <int> v ; 

            if(i%2!=0)leftToRight(root, v, i , 1) ;
            else rightToLeft(root, v, i , 1);

            ans.push_back(v) ;  
        }
        return ans ;
    }
};