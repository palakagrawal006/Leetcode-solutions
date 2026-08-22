// M3 = Morris
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left != NULL) {
                // save right - find pred
                TreeNode* r = curr->right;
                curr->right = curr->left;
                TreeNode* pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                // link
                pred->right = r;
                curr = curr->left;
            } else
                curr = curr->right;
        }
        TreeNode* temp = root;
        while (temp->right) {
            temp->left = NULL;
            temp = temp->right;
        }
    }
};
// // M2 = recursion
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//        if(root==NULL) return  ;

//        TreeNode *l = root->left;
//        TreeNode *r = root->right;

//        root->left = NULL;
//        root->right = NULL;

//        flatten(l);
//        flatten(r);

//        root->right = l ;

//        TreeNode *temp = root ;
//        while(temp->right){
//             temp = temp->right ;
//        }
//        temp->right = r;
//     }
// };

// // M1 - VECTOR
// class Solution {
// public:
//     void preorder(TreeNode* root,vector<TreeNode*> &v ){
//         if(root==NULL)return ;

//         v.push_back(root) ;
//         preorder(root->left , v) ;
//         preorder(root->right , v) ;
//     }
//     void flatten(TreeNode* root) {
//         vector<TreeNode*> v ;
//         preorder(root, v) ;
//         int n = v.size();

//         for(int i = 0; i<n-1; i++){
//             v[i]->right = v[i+1] ;
//             v[i]->left = NULL;
//         }
//     }
// };