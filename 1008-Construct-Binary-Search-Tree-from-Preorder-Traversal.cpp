
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode *node = new TreeNode(val);
           return node;
        }

        else if(root->val > val) { // left
            if(root->left==NULL){ // attach
                TreeNode *node = new TreeNode(val);
                root->left= node;
                return root; 
            }
            else insertIntoBST(root->left , val) ;
        }
        else{
            if(root->right==NULL) {
            TreeNode *node = new TreeNode(val);
            root->right= node;
            return root;
            } 
            else insertIntoBST(root->right , val) ;
        }

        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size() ; 
        TreeNode *root = new TreeNode(pre[0]) ;  

        for(int i = 1; i<n; i++){
            insertIntoBST(root, pre[i]) ; 
        }
        return root; 
    }
};

// class Solution {
// public:
//     TreeNode* build(vector<int>& pre,int prelo, int prehi, vector<int>& in, int inlo, int inhi){ 
//         // base case
//         if(prelo>prehi)return NULL; 

//         // root ele= pre ka 1st ele = prelo
//         TreeNode *root = new TreeNode(pre[prelo]) ; 

//         if(prelo==prehi )return root; 

//         // find left subtree and right subtree using inorder
//         int i= inlo ; 
//         while(i<=inhi){
//             if(in[i]==pre[prelo]) break; 
//             i++;
//         }

//         int leftCount= i-inlo ;
//         int rightCount= inhi-i;

//         root->left = build(pre, prelo+1 , prelo+leftCount, in, inlo , i-1); 
//         root->right = build(pre, prelo+leftCount+1,prehi, in, i+1, inhi); 

//         return root;  
//     }
//     TreeNode* bstFromPreorder(vector<int>& pre) {
//         int n = pre.size() ; 
//         vector<int> in = pre;
//         sort(in.begin() , in.end()) ; 
//          return build(pre, 0 , pre.size()-1, in, 0 , in.size()-1); 
//     }
// };

// class Solution {
// public:
//     TreeNode* helper(vector<int>& pre , int lo , int hi){
//         if(lo>hi) return NULL ; 

//         TreeNode *root = new TreeNode(pre[lo]) ; 

//         int x = hi+1;
//         for(int i = lo+1; i<=hi ; i++ ){
//             if(pre[i] > root->val){
//                 x = i ; 
//                 break ;
//             }
//         }
//         root->left = helper(pre, lo+1 , x-1);
//         root->right = helper(pre, x , hi);
//         return root; 
//     }
//     TreeNode* bstFromPreorder(vector<int>& pre) {
//         int n = pre.size() ; 
//         return helper(pre , 0 , n-1);
//     }
// };