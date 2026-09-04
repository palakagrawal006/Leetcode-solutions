// dp 
class Solution {
public:
    bool helper(vector<int> &nums , int i , int t, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(t == 0) return true; 
            return false; 
        }
        if(dp[i][t] != -1) return dp[i][t] ; 

        bool skip = helper(nums, i+1, t ,  dp);
        if(t-nums[i] <0)return dp[i][t] = skip; 
        bool take = helper(nums, i+1, t-nums[i], dp);
 
        return dp[i][t] =  skip||take; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for(int x : nums) sum += x;
        if(sum%2 !=0) return false; 

        vector<vector<int>> dp(nums.size(), vector<int>((sum/2)+1, -1)) ;
        
        return helper(nums, 0 , sum/2 ,dp) ; //arr, idx, target , takesum 
    }
};

// // recursion 2
// class Solution {
// public:
//     bool helper(vector<int> &nums , int i , int t, int s){
//         if(i==nums.size()){
//             if(t == s) return true; 
//             return false; 
//         }
//         bool skip = helper(nums, i+1, t , s);
//         if(s+nums[i] > t)return skip; 
//         bool take = helper(nums, i+1, t , s+nums[i]);

//         return skip||take; 
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum = 0 ; 
//         for(int x : nums) sum += x;
//         if(sum%2 !=0) return false; 
        
//         return helper(nums, 0 , sum/2 ,0) ; //arr, idx, target , takesum 
//     }
// };

// recursion
// class Solution {
// public:
//     bool helper(vector<int> &nums , int i , int skipS, int takeS){
//         if(i==nums.size()){
//             if(skipS == takeS) return true; 
//             return false; 
//         }
//         bool skip = helper(nums, i+1, skipS+nums[i] , takeS);
//         bool take = helper(nums, i+1, skipS , takeS+nums[i]);

//         return skip||take; 
//     }
//     bool canPartition(vector<int>& nums) {
//         return helper(nums, 0 , 0,0) ; //arr, idx, skipsum , takesum 
//     }
// };