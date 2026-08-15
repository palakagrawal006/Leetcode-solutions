class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans; 
        stack<TreeNode*> st ;

        TreeNode *node = root ; 

        while(!st.empty() || node){
            if(node) {
                st.push(node) ; 
                node = node->left; 
            }
            else { // node is null 
                TreeNode *temp = st.top() ; 
                st.pop(); 
                ans.push_back(temp->val);
                node = temp->right ; 

            }
        }
        return ans ; 
    }
};



// class Solution {
// public:
//   void inorder(vector<int> &v , TreeNode *root){
//         // inorder =  left root right
//         if(root ==NULL) return; 

//         inorder(v, root->left);
//         v.push_back(root->val) ; 
//         inorder(v , root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector <int> v; 

//         inorder(v , root) ; 

//         return v ; 
//     }
// };