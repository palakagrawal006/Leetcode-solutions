
// tabulated -- -same array 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size(); 

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0) continue; 
                else if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] +=  grid[i-1][j] ;
                else grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]) ; 
            }
        }
        return grid[n-1][m-1] ; 
    }
};

// // tabulated
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size() ; 
//         int m = grid[0].size(); 
//         vector<vector<int>>  dp(n, vector<int>(m, -1)) ; 

//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if(i==0 && j==0) dp[i][j]= grid[0][0];
//                 else if(i==0) dp[i][j] = grid[i][j]+ dp[i][j-1] ;
//                 else if(j==0) dp[i][j] = grid[i][j]+ dp[i-1][j] ;
//                 else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]) ; 
//             }
//         }
//         return dp[n-1][m-1] ; 
//     }
// };

// // DP
// class Solution {
// public:
//     int h(vector<vector<int>>& grid , int row, int col , int n, int m , vector<vector<int>> &dp){
//         if(row==n-1 && col==m-1) return grid[n-1][m-1] ; 
//         if(row >=n || col>= m) return INT_MAX ; 
//         if(dp[row][col] != -1) return dp[row][col] ; 

//         return dp[row][col] = grid[row][col] + min(h(grid, row+1 ,col, n, m,dp ) , h(grid, row , col+1, n, m, dp));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size() ; 
//         int m = grid[0].size(); 
//         vector<vector<int>>  dp(n, vector<int>(m, -1)) ; 
//         return h(grid, 0 , 0, n, m, dp) ;
//         // return grid[0][0] + min(h(grid, 1 , 0, n, m ) , h(grid, 0 , 1, n, m));
//     }
// };

// // RECURSION
// class Solution {
// public:
//     int h(vector<vector<int>>& grid , int row, int col , int n, int m ){
//         if(row==n-1 && col==m-1) return grid[n-1][m-1] ; 
//         if(row >=n || col>= m) return INT_MAX ; 

//         return grid[row][col] + min(h(grid, row+1 ,col, n, m ) , h(grid, row , col+1, n, m));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size() ; 
//         int m = grid[0].size(); 
//         return h(grid, 0 , 0, n, m) ;
//         // return grid[0][0] + min(h(grid, 1 , 0, n, m ) , h(grid, 0 , 1, n, m));
//     }
// };