
// DP
class Solution {
public:
    int helper( int sr, int sc, int er , int ec, vector<vector<int>>& dp) {
        if(sr == er && sc==ec) return 1; 
        if (sr>er || sc>ec) return 0 ;
        if(dp[sr][sc] != -1) return dp[sr][sc] ; 

        return dp[sr][sc] = helper(sr, sc+1, er, ec, dp) + helper(sr+1, sc, er, ec, dp) ;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1))  ; 
        return helper(0, 0, m-1, n-1, dp) ; 
    }
};


// class Solution {
// public:
// // RECURSIVE
//     int uniquePaths(int m, int n) {
//         if(m == 0 && n== 0) return 1;
//         if(m<0 || n<0) return 0 ; 

//         return uniquePaths( m-1, n) + uniquePaths(m ,n-1) ; 
//     }
// };


// class Solution {
// public:
// // RECURSIVE

//     int helper( int sr, int sc, int er , int ec) {
//         if(sr == er && sc==ec) return 1; 
//         if (sr>er || sc>ec) return 0 ;

//         int rightways = helper(sr, sc+1, er, ec) ;
//         int downways = helper(sr+1, sc, er, ec) ;
//         return rightways +downways ;
        
//     }
//     int uniquePaths(int m, int n) {
//         return helper(0, 0, m-1, n-1) ; 
//     }
// };