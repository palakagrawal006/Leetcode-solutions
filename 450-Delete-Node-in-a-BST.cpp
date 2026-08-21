class Solution {
public:
    TreeNode* inorder_pred(TreeNode *root){
        if(root->left == NULL)return NULL; 
        TreeNode *pred = root->left; 

        while(pred->right){
            pred= pred->right; 
        }
        return pred;
    }
    TreeNode* inorder_succ(TreeNode *root){
        if(root->right == NULL)return NULL; 
        TreeNode *succ = root->right; 

        while(succ->left){
            succ= succ->left; 
        }
        return succ;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==NULL) return NULL ;

        if(root->val == key){
            // case 1 : no child
            if(root->left == NULL && root->right == NULL)return NULL ;

            // case 2 : 1 child
            else if(root->left == NULL || root->right == NULL){
                if(root->left == NULL) return root->right;
                else return root->left; 
            }

            // case 3 : 2 child 
            else {
                // replace with inorder pred/succ 
                // after replacing delete pred
                TreeNode *pred = inorder_pred(root) ;
                root->val= pred->val; 
                root->left = deleteNode(root->left,pred->val); 
            }
        }

        else if(root->val > key){ // go left
            root->left= deleteNode(root->left, key) ; 
        }
        else { //root->val < key : go right
            root->right = deleteNode(root->right, key); 
        }

        return root; 
    }
};