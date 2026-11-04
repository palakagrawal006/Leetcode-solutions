class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1)
            return 0;

        int i = 0, j = 0;
        int prod = 1;
        int ans = 0;

        while (i < n && j < n) {
            prod *= nums[j];

            while(prod >= k) {
                ans += j - i;
                prod = prod / nums[i];
                i++;
            }
            j++;
        }
        while (i < n) {
            ans += j - i;
            prod = prod / nums[i];
            i++;
        }
        return ans;
    }
};
