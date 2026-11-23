
class Solution {
public:
    void helper(TreeNode* root, vector<string> &v , string s){
        if(!root) return  ; 

        string i = to_string(root->val) ; 

        if(!root->left && !root->right) {
            s += i ; 
            v.push_back(s) ; 
        }

        helper(root->left , v , s+i+"->");
        helper(root->right , v , s+i+"->");
        
    }
    vector<string> binaryTreePaths(TreeNode* root) { 
        vector<string> v ; 
        
        helper( root ,v , "");
        return v ; 
        
    }
};