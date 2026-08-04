class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector <int> ans; 

        for(int i= 0 ; i<n-1 ; i++){
            int ele = nums[i] ; 

            while(ele+1 <nums[i+1]){
                ans.push_back(ele+1);
                ele++; 
            } 

        }

        return ans ; 
    }
};