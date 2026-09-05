// space optimisation
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(2, vector<int>(m+1, 0)); // 0 for base case

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[1][j] = 1 + dp[0][j - 1];
                else
                    dp[1][j] = max(dp[1][j - 1],  dp[0][j]);
            }
            for (int j = 1; j <= m; j++) {
                dp[0][j] = dp[1][j] ;  
            }
        }
        return dp[1][m]; // extra size
        // dp[n][m] will store lcs of substr(s1, 0 n-1) and substr(s1,0, m-1)
    }
};

// // tabulation -- to avoid base case
// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // 0 for base case

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 if (s1[i-1] == s2[j-1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = max(dp[i][j - 1],  dp[i - 1][j]);
//             }
//         }
//         return dp[n][m]; // extra size
//         // dp[n][m] will store lcs of substr(s1, 0 n-1) and substr(s1,0, m-1)
//     }
// };

// // tabulation
// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {

//                 int p = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
//                 int q = (j > 0) ? dp[i][j - 1] : 0;
//                 int r = (i > 0) ? dp[i - 1][j] : 0;

//                 if (s1[i] == s2[j])
//                     dp[i][j] = 1 + p;
//                 else
//                     dp[i][j] = max(q, r);
//             }
//         }
//         return dp[n - 1][m - 1];
//     }
// };

// // dp - tc - o(n*m)
// class Solution {
// public:
// // since string is not modified- pass it by refernce, and const
//     int helper (const string &s1,int n ,const  string &s2, int m,
//     vector<vector<int>>& dp){
//         if(n<0 || m<0)return 0 ;
//         if(dp[n][m] != -1) return dp[n][m] ;
//         if(s1[n] == s2[m])
//             return dp[n][m] = 1 + helper(s1, n-1, s2, m-1, dp);
//         else
//             return dp[n][m]= max(helper(s1, n, s2, m-1, dp), helper(s1, n-1,
//             s2, m, dp));

//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         int n = s1.size() ;
//         int m = s2.size() ;
//         vector<vector<int>> dp(n , vector<int> (m,-1)) ;
//         return helper(s1, n-1 , s2, m-1, dp) ;
//     }
// };

// recursion
// class Solution {
// public:
//     int helper(string s1,int n , string s2, int m){
//         if(n<0 || m<0)return 0 ;

//         if(s1[n] == s2[m]) {
//             return 1 + helper(s1, n-1, s2, m-1);
//         }
//         else {
//             return max(helper(s1, n, s2, m-1), helper(s1, n-1, s2, m));
//         }
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         return helper(s1, s1.size()-1 , s2, s2.size()-1) ;
//     }
// };