class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size() ;

        int i = 0, j=0; 
        long long sum = 0, score= 0 ;
        long long ans = 0 ;

        while(j<n && i<n){
            sum += nums[j] ; 
            score = sum * (j-i+1) ; 

            while(score>=k){
                sum -= nums[i] ; 
                i++;
                score = sum * (j-i+1) ; 
            }
            // when valid
            ans += j-i+1; 

            j++;
        }

        return ans; 
    }
};