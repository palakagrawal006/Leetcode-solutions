class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[mid+1]){
                // Peak left side me hai (including mid)
                hi = mid;
            } else {
                // Peak right side me hai
                lo = mid + 1;
            }
        }
        return lo; // lo == hi, peak index
    }
};
