class Solution {
public:
    long long unboundedKnapsack(vector<int>& coins, int amount, int i,
                          vector<vector<int>>& dp) {
        if (i == coins.size()) {
            if (amount == 0)
                return 0; // no more coins
            return INT_MAX; //not valid combination == -1
            // make sure not in min() during return 
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        long long skip = unboundedKnapsack(coins, amount, i + 1, dp);

        if (amount-coins[i] <0)
            return dp[i][amount] = skip;

        long long take =
            1 +
            unboundedKnapsack(
                coins, amount - coins[i], i,
                dp); // can pick again - same product -- stop when limit exceed-

        return dp[i][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {

        // changing i- 0ton-1 and amount = amount-0

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = (int) unboundedKnapsack(coins, amount, 0, dp);
        return (ans==INT_MAX) ?  -1 :  ans; 
    }
};