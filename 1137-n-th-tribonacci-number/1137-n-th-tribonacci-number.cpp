// DP
class Solution {
public:
    int helper(int n, vector<int> &dp) {
        if(n == 0 ) return 0 ; 
        if(n==1||n==2) return 1 ; 
        if(dp[n] != -1) return dp[n] ; 

        return dp[n]= helper(n-1, dp)+helper(n-2, dp)+helper(n-3, dp) ; 
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1) ; 
        return helper(n , dp) ; 
    }
};


// // recurwsive -- TLE 
// class Solution {
// public:
//     int helper(int n) {
//         if(n == 0 ) return 0 ; 
//         if(n==1||n==2) return 1 ; 

//         return helper(n-1)+helper(n-2)+helper(n-3) ; 
//     }
//     int tribonacci(int n) {
//         return helper(n) ; 
//     }
// };

// iterative
// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n == 0 ) return 0 ; 
//         if(n==1||n==2) return 1 ; 

//         int a = 0 , b = 1 , c =1;

//         for(int i = 3 ; i<=n ; i++){
//             int d = a+b+c ; 
//             a = b ; 
//             b = c ; 
//             c = d; 
//         }
//         return c  ;
//     }
// };