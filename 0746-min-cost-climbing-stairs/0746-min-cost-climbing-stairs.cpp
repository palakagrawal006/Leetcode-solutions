// DP 
class Solution {
public:
    int helper(vector<int>& cost , int i,  vector<int> &dp){
        if(i >= cost.size()) return 0 ; 
        if(dp[i]!= -1) return dp[i] ; 

        return dp[i] =cost[i] + min(helper(cost , i+1, dp) ,helper(cost, i+2, dp)) ;
    }

    // top to bottom 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ; 
        vector<int> dp(n , -1) ; 
        return min(helper(cost ,0, dp) ,helper(cost, 1, dp)) ;   
    }
};


/////TLE - RECURSIVE SOLUTION 

// class Solution {
// public:
//     int helper(vector<int>& cost , int sum, int i){
//         if(i >= cost.size()) return sum ; 

//         return min(helper(cost , sum+cost[i] ,i+1) ,helper(cost, sum+cost[i] ,i+2)) ;
//     }
//     int minCostClimbingStairs(vector<int>& cost) {

//         return min(helper(cost ,0 ,0) ,helper(cost, 0 ,1)) ;   
//     }
// };