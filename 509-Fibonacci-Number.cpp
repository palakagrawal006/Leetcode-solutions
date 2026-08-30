// Tabulation
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0; 
        if(dp.size()>1) dp[1] = 1;

        for(int i= 2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2] ; 
        }
        return dp[n];
    }
};


// // recursion + memoisation
// class Solution {
// public:
//     int fibo(int n, vector<int>& dp) {
//         if (n <= 1)
//             return n;
//         if (dp[n] != -1) { // store some val;
//             return dp[n];
//         }

//         dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp); // store ans
//         return dp[n];
//     }
//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         return fibo(n, dp);
//     }
// };



////recursion
// class Solution {
// public:
//     int fib(int n) {
//         if(n==0) return 0 ;
//         if(n==1) return 1; 

//         return fib(n-1) + fib(n-2) ; 
//     }
// };