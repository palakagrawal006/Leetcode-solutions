class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ; 

        int i = 0, j= 0, count = 0 , odd = 0;
        int ans = 0 ;

        while(i<n && j<n){
            if(nums[j]%2 !=0) {
                odd++ ; 
                count = 0; //no of subarray
            }

            while(i<=j && odd==k){
                count++; 
                if(nums[i]%2 != 0 ) odd--; 
                i++; 
            }

            ans += count ;

            j++;
        } 
        return ans; 
    }
};