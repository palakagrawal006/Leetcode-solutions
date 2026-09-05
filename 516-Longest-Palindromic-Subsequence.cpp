class Solution {
public:
// since string is not modified- pass it by refernce, and const
    int helper (const string &s1,int n ,const  string &s2, int m, vector<vector<int>>& dp){
        if(n<0 || m<0)return 0 ; 
        if(dp[n][m] != -1) return dp[n][m] ; 
        if(s1[n] == s2[m]) 
            return dp[n][m] = 1 + helper(s1, n-1, s2, m-1, dp);
        else 
            return dp[n][m]= max(helper(s1, n, s2, m-1, dp), helper(s1, n-1, s2, m, dp)); 
        
    }
    int longestPalindromeSubseq(string s) {
        string t = s; 
        reverse(t.begin(), t.end()) ; 

        int n = s.size() ; //same length
        vector<vector<int>> dp(n , vector<int> (n,-1)) ; 
        return helper(s, n-1, t, n-1, dp) ;
    }
};