class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ; 

        int sum = 0 ; 
        int minLen = INT_MAX; 

        int i = 0 , j=0 ;

        while(j<n){
            sum += nums[j] ;

            while(sum>=target){
                minLen = min(j-i+1, minLen); 
                sum -= nums[i] ; 
                i++; 
            }
            j++;
        }

        if(minLen ==INT_MAX) return 0 ; 
        return minLen ;


    }
};