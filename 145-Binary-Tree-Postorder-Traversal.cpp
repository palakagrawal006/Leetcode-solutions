class Solution {
public:
void helper(vector<int>& v , TreeNode* root){
        if(!root) return ;

        helper(v , root->left);
        helper(v , root->right);
        v.push_back(root->val) ;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v ; 
        helper(v  , root) ; 
        return v ; 
    }
};


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v ; 
//         stack<TreeNode*> st ; 
//         TreeNode *node = root ; 

//         while(!st.empty()|| node){
//             if(node){
//                 st.push(node);
//                 node = node->left ;
//             }
//             else{ //node is null 
//                 TreeNode *temp = st.top() ; 
//                 st.pop() ;

//                 v.push_back(temp->val) ;
//                 node = temp->right ;
//             }
//         }
//         return v ; 
//     }
// };

