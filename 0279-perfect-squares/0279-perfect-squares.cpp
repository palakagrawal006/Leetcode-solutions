// tabulation - 2
class Solution {
public:
    bool isPerfect(int n) {
        int s = sqrt(n);
        return (s * s == n);
    }
    int numSquares(int n) {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++) {
            if (isPerfect(i))
                dp[i] = 1;
            else {
                int mn = INT_MAX; // or n
                for (int j = 1; j <= i/2; j++) {
                    int ans = dp[j] + dp[i - j];
                    mn = min(mn, ans);
                }
                dp[i] = mn;
            }
        }
        return dp[n];
    }
};


// // tabulation
// class Solution {
// public:
//     bool isPerfect(int n) {
//         int s = sqrt(n);
//         return (s * s == n);
//     }
//     int numSquares(int n) {
//         vector<int> dp(n + 1);

//         for (int i = 1; i <= n; i++) {
//             if (isPerfect(i))
//                 dp[i] = 1;
//             else {
//                 int mn = INT_MAX; // or n
//                 for (int j = 1; j <= sqrt(i); j++) {
//                     int ans = dp[j * j] + dp[i - j * j];
//                     mn = min(mn, ans);
//                 }
//                 dp[i] = mn;
//             }
//         }
//         return dp[n];
//     }
// };



// // dp --2
// class Solution {
// public:

//     bool isPerfect(int n){
//         int s = sqrt(n) ;
//         return (s* s == n);
//     }
//     int helper(int n, vector<int> &dp){
//         if(isPerfect(n)) return 1;
//         if(dp[n] != -1) return dp[n] ;

//         int mn = INT_MAX ; //or n
//         for(int i = 1; i<=sqrt(n) ; i++){
//             int ans = helper(i*i, dp)+helper(n-i*i, dp) ;
//             mn  = min(mn , ans) ;
//         }
//         return dp[n] = mn ;
//     }
//     int numSquares(int n) {
//         vector<int> dp(n+1, -1);
//         return helper(n  ,dp) ;
//     }
// };

// // dp -- still tle in large number like 6405
// class Solution {
// public:

//     bool isPerfect(int n){
//         int s = sqrt(n) ;
//         return (s* s == n);
//     }
//     int helper(int n, vector<int> &dp){
//         if(isPerfect(n)) return 1;
//         if(dp[n] != -1) return dp[n] ;

//         int mn = INT_MAX ; //or n
//         for(int i = 1; i<=n/2 ; i++){
//             int ans = helper(i, dp)+helper(n-i, dp) ;
//             mn  = min(mn , ans) ;
//         }
//         return dp[n] = mn ;
//     }
//     int numSquares(int n) {
//         vector<int> dp(n+1, -1);
//         return helper(n  ,dp) ;
//     }
// };

// // tle -- recursion
// class Solution {
// public:
//     bool isPerfect(int n){
//         int s = sqrt(n) ;
//         return (s* s == n);
//     }
//     int numSquares(int n) {
//         if(isPerfect(n)) return 1;
//         int mn = INT_MAX ; //or n

//         for(int i = 1; i<=n/2 ; i++){
//             int ans = numSquares(i)+numSquares(n-i) ;
//             mn  = min(mn , ans) ;
//         }
//         return mn ;
//     }
// };