class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans , int n, int idx ,vector<vector<int>>& v){
        if(idx==n) {
            v.push_back(ans) ;
            return ; 
        }
        helper(nums, ans , n , idx+1 , v); //not append

        ans.push_back(nums[idx]) ; 
        helper(nums, ans , n , idx+1 , v); // append

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ; 

        vector<vector<int>> v ; 
        vector<int> ans ; 

        helper(nums, ans , n , 0, v);

        return v ; 
    }
};