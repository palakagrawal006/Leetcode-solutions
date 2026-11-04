class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size() ; 
        int mx = nums[0] ; 

        // conver
        for(int i  = 0 ; i<n ; i++){
            mx = max(mx , nums[i]) ;
            nums[i] = nums[i] + mx ; 
        }

        // score
        vector<long long> ans(n); 
        ans[0] = nums[0] ; 
        for(int i  = 1 ; i<n ; i++){
            ans[i] = nums[i] + ans[i-1]; 
        }

        return ans ;
    }
};