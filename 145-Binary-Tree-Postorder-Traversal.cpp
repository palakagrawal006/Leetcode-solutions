class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> ans; 

        stack <TreeNode*> st ; 
        if(root)st.push(root) ; 

        while(!st.empty()){
            TreeNode *temp = st.top() ;
            st.pop() ; 
            ans.push_back(temp->val) ; 

            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right); 
        }
        reverse(ans.begin() , ans.end()) ;
        return ans;
    }
};

// class Solution {
// public:
// void postorder(vector<int> &v , TreeNode *root){
//         // postorder =  left  right root
//         if(root ==NULL) return; 

//         postorder(v, root->left);
//         postorder(v , root->right);
//         v.push_back(root->val) ; 
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector <int> v; 

//         postorder(v , root) ; 

//         return v ;
//     }
// };