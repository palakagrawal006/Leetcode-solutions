class Solution {
public:
    bool isprime(int n) {
        if(n==1) return false; 

        for(int i = 2; i<= sqrt(n) ; i++){
            if(n%i ==0) return false; 
        }
        return true; 
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size() ; 
        int maxi = 0;

        for(int i = 0 ; i<n ; i++){
           int ele = nums[i][i]; 
           if(isprime(ele)) maxi = max(maxi, ele) ; 

           ele = nums[i][n - i - 1];
           if(isprime(ele)) maxi = max(maxi, ele) ; 
        }
        return maxi ; 
    }
};

// class Solution {
// public:
//     bool isprime(int n) {
//         if(n==1) return false; 

//         for(int i = 2; i<= sqrt(n) ; i++){
//             if(n%i ==0) return false; 
//         }
//         return true; 
//     }
//     int diagonalPrime(vector<vector<int>>& nums) {
//         int n = nums.size() ; 
//         // int m = nums[0].size() ; 
//         int maxi = 0;

//         for(int i = 0 ; i<n ; i++){
//             for(int j = 0; j<n; j++){
//                 if((i==j || j == n-i+1 ) && isprime(nums[i][j]) ){
//                    maxi = max(maxi, nums[i][j]);
//                 }
//             }
//         }
//         return maxi ; 
//     }
// };