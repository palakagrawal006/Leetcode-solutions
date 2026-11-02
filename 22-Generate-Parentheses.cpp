class Solution {
public:
    void helper(string s, vector<string> &ans, int n , int o , int c ){
        if(c>o || o>n) return ;
        if(c==n && o==n){
            ans.push_back(s) ;
            return ;
        }

        helper(s+'(' , ans, n, o+1, c);

        if(o>c){
            helper(s+')' , ans, n, o, c+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ; 
        helper("", ans , n , 0, 0 ) ; 

        return ans ; 
    }
};