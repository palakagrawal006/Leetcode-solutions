class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size() ; 

        if(n<3)return -1;

        sort(nums.begin(), nums.end()) ; 
        int prod = nums[n-3]*nums[n-2]*nums[n-1] ; 

        int pro = nums[0]*nums[1]*nums[n-1] ; 
        return max(prod, pro); 
    }
};