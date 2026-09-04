// dp
class Solution {
public:
    long long h(vector<int>& nums, int x, int i, int parity, vector<vector<long long>> &dp) {
        if(i== nums.size()) {
            return 0; 
        }

        if(dp[i][parity] != -1) return dp[i][parity];
        int currParity = nums[i]%2 ; //parity of current element = 

        // skip 
        long long skip = h(nums, x, i+1, parity, dp) ;

        // take --
        long long take ;

        // different parity
        if(currParity!= parity) {
            take = nums[i]+h(nums, x, i+1, currParity, dp)-x;
        }
        //  same parity
        else take= nums[i]+h(nums, x, i+1, currParity, dp);

        return dp[i][parity] = max(take , skip) ; 
    }
    long long maxScore(vector<int>& nums, int x) {
        // changes = idx = 1 to n-1 , parity = 0 and 1
        vector<vector<long long>> dp(nums.size() , vector<long long>(2, -1)) ; 
        return nums[0]+h(nums , x ,1, nums[0]%2 , dp);
    }
};

////by parity
// class Solution {
// public:
//     long long h(vector<int>& nums, int x, int i, int parity) {
//         if(i== nums.size()) {
//             return 0; 
//         }
//         int currParity = nums[i]%2 ; //parity of current element = 

//         // skip 
//         long long skip = h(nums, x, i+1, parity) ;

//         // take --
//         long long take ;

//         // different parity
//         if(currParity!= parity) {
//             take = nums[i]+h(nums, x, i+1, currParity)-x;
//         }
//         //  same parity
//         else take= nums[i]+h(nums, x, i+1, currParity);

//         return max(take , skip) ; 
//     }
//     long long maxScore(vector<int>& nums, int x) {
//         return nums[0]+h(nums , x ,1, nums[0]%2 );
//     }
// };

// // recursion
// class Solution {
// public:
//     long long h(vector<int>& nums, int x, int i, int last) {
//         if(i== nums.size()) {
//             return 0; 
//         }
//         int lastParity = last%2 ; //parity of last element = 
//         int currParity = nums[i]%2 ; //parity of current element = 

//         // skip 
//         long long skip = h(nums, x, i+1, last) ;

//         // take --
//         long long take ;

//         // different parity
//         if(currParity!= lastParity) {
//             take = nums[i]+h(nums, x, i+1, nums[i])-x;
//         }
//         //  same parity
//         else take= nums[i]+h(nums, x, i+1, nums[i]);

//         return max(take , skip) ; 
//     }
//     long long maxScore(vector<int>& nums, int x) {
//         return nums[0]+h(nums , x ,1, nums[0] );
//     }
// };