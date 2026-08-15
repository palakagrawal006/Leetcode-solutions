class Solution {
public:

    void preorder(vector<int> &ans, TreeNode *root){
      
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans; 

        stack <TreeNode*> st ; 
        if(root)st.push(root) ; 

        while(!st.empty()){
            TreeNode *temp = st.top() ;
            st.pop() ; 
            ans.push_back(temp->val) ; 

            if(temp->right) st.push(temp->right); // stack - right first
            if(temp->left) st.push(temp->left);

        }
        return ans ;
    }
};


// class Solution {
// public:

//     void preorder(vector<int> &v , TreeNode *root){
//         // preorder = root left right
//         if(root ==NULL) return; 

//         v.push_back(root->val) ; 
//         preorder(v, root->left);
//         preorder(v , root->right);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector <int> v; 

//         preorder(v , root) ; 

//         return v ; 
//     }
// };