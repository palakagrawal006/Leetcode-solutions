// dp
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
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() ;
        int m = s2.size() ;
        vector<vector<int>> dp(n , vector<int> (m,-1)) ; 
        return helper(s1, n-1 , s2, m-1, dp) ; 
    }
};

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