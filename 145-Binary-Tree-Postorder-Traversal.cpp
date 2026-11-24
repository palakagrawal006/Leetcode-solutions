// class Solution {
// public:
// void helper(vector<int>& v , TreeNode* root){
//         if(!root) return ;

//         helper(v , root->left);
//         helper(v , root->right);
//         v.push_back(root->val) ;
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> v ; 
//         helper(v  , root) ; 
//         return v ; 
//     }
// };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v ; 
        stack<TreeNode*> st ; 
        if(root) st.push(root);

        while(!st.empty()){
            TreeNode *temp = st.top() ; 
            st.pop() ;

            v.push_back(temp->val) ;
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right); 
            
        }
        reverse(v.begin() , v.end()) ; 
        return v ; 
    }
};

