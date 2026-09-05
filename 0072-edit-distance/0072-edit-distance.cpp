class Solution {
public:
    int helper(const string& s1, int n, const string& s2, int m, vector<vector<int>> &dp) {
        if (n < 0 )return m+1;
        if (m< 0 )return n+1;

        if(dp[n][m]!=-1) return dp[n][m] ; 

        if (s1[n] == s2[m])
           return dp[n][m] =helper(s1, n - 1, s2, m - 1, dp);

        else { // deletion , insertion , updation
            int del = helper(s1, n - 1, s2, m, dp);
            int ins = helper(s1, n , s2, m-1, dp);
            int rep = helper(s1, n - 1, s2, m- 1, dp);

            return dp[n][m] = 1+min({del, ins, rep}) ; 
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(word1, n - 1, word2, m - 1,dp);
    }
};