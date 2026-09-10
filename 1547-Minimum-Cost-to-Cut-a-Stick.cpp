class Solution {
public:
    int cost(int i , int j , vector<int>& arr,  vector<vector<int>> &dp){
        if(i>j)return 0; 
        if(dp[i][j]!= -1)return dp[i][j]; 
        int mini = INT_MAX; 

        for(int k=i ; k<=j; k++){
            int len = arr[j+1]-arr[i-1] ; 
            int tc = cost(i, k-1, arr, dp) + cost(k+1, j, arr, dp) + len;
            mini = min(mini, tc);  
        }
        return dp[i][j]= mini ; 
       
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end()) ; //o(nlogn)
        
        int m = cuts.size() ; 
         vector<vector<int>> dp(m, vector<int>(m, -1));

        return cost(1, cuts.size()-2 , cuts, dp); 
    }
};