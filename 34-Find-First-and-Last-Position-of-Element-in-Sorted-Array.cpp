class Solution {
public:
    int first (vector<int>& nums, int n, int t){
        int lo = 0 , hi = n-1; 
        int ans= -1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2; 

            if(nums[mid]==t) {
                ans = mid ;
                hi = mid-1 ;
            }
            else if (nums[mid]>t) hi = mid-1;
            else lo = mid+1; 
        }
        return ans; 
    }
    int last (vector<int>& nums, int n, int t){
        int lo = 0 , hi = n-1; 
        int ans= -1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2; 

            if(nums[mid]==t) {
                ans = mid ;
                lo= mid+1 ;
            }
            else if (nums[mid]>t) hi = mid-1;
            else lo = mid+1; 
        }
        return ans; 
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size() ; 

        return {first(nums, n, t) , last(nums, n, t)} ; 
    }
};