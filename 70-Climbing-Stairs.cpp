
// tabulation
class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1, -1) ; 
       dp[0] = 0; 
       if(n>=1) dp[1] = 1;
       if(n>=2) dp[2] = 2; 

       for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2]; 
       }
       return dp[n] ; 
    }
};

// // dp 
// class Solution {
// public:
//     int helper(int n, vector<int> &dp){
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         if(dp[n]!= -1) return dp[n] ; 
//         return dp[n]=  helper(n-1, dp) + helper(n-2, dp) ;
//     }
//     int climbStairs(int n) {
//        vector<int> dp(n+1, -1) ; 
//        return helper(n , dp) ; 
//     }
// };

// iterative
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;

//         int sum1 = 1;
//         int sum2 = 2;

//         for (int i = 3; i <= n; i++) {

//             sum2 = sum1 + sum2;
//             sum1 = sum2 - sum1;
//         }
//         return sum2;
//     }
// };

//// recursive
// class Solution {
// public:
//     int climbStairs(int n) {
//       if(n==1)return 1 ;
//       if(n==2) return 2 ;

//       return climbStairs(n-1) + climbStairs(n-2) ;
//     }
// };