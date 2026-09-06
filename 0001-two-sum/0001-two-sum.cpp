class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ; 

        map<int, int> mp;
        for(int i = 0 ; i<n ; i++){
            mp[nums[i]] = i ; 
        }

        for(int i = 0 ; i<n; i++){
            int remain = target - nums[i] ; 
            if(mp.find(remain) != mp.end()){
                if(i == mp[remain]) continue; 
                return {i , mp[remain]}; 
            }
        }
        return {-1,-1} ; 
    }
};