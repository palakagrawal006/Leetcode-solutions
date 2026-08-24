class Solution {
public:
    void find(TreeNode* root, int start, TreeNode* &first){
        if(root==NULL)return;
        if(root->val == start) {
            first = root; 
            return; 
        }
        find(root->left , start, first);
        find(root->right , start, first);
    }
    void markParent(TreeNode* root , unordered_map<TreeNode*, TreeNode*>& parent){
        if(root== NULL)return; 
        if(root->left){
            parent[root->left] = root; 
        }
        if(root->right){
            parent[root->right] = root; 
        }
        markParent(root->left , parent) ;
        markParent(root->right , parent) ;
    }
    int amountOfTime(TreeNode* root, int start) {
        // 1. find node for start
        TreeNode *first; 
        find(root, start, first) ; 

        //2. mark the parent nodes - using map 
        unordered_map<TreeNode*, TreeNode*> mp ; 
        markParent(root, mp);

        // 3. check if node is already infected - set- isInfected
        unordered_set<TreeNode*> s ; 
        s.insert(first) ; //start is always infected

        // 4. maintain queue of next nodes ans level 
        queue <pair<TreeNode* ,int>> q; 
        q.push({first, 0}) ;

        // 5. maintain maxLevel to return ans  ;
        int maxLevel = 0; 


        while(q.size()>0){
            TreeNode* temp =(q.front()).first ; 
            int level = (q.front()).second ;
            q.pop(); 
            maxLevel = max(maxLevel, level) ; 

            // update if parent, left, right exists
            if(mp.find(temp) != mp.end()){
                if(s.find(mp[temp]) == s.end()){ // not infected
                    q.push({mp[temp] , level+1}) ;
                    s.insert(mp[temp]) ;
                }
            } 
            if(temp->left){
                if(s.find(temp->left) == s.end()){ // not infected
                    q.push({temp->left, level+1});
                    s.insert(temp->left) ;
                }
            }
            if(temp->right){
                if(s.find(temp->right) == s.end()){ // not infected
                    q.push({temp->right, level+1});
                    s.insert(temp->right) ;
                }
            }
        }
        return maxLevel ; 
    }
};