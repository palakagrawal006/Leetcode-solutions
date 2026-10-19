class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ; 

        int lo = 0, hi = n-1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(nums[mid]== target) return true; 

            if(nums[lo] == nums[mid] && nums[mid]==nums[hi]) {
                lo++;
                hi--;
            }

            // left sorted
            else if(nums[mid] >= nums[lo]){
                if(target <=nums[mid] && target>=nums[lo]) hi= mid-1;
                else lo = mid+1;
            }

            // right sorted
            else {
                if(target <=nums[hi] && target>=nums[mid]) lo= mid+1;
                else hi= mid-1;
            }
        }
        return false; 
    }
};