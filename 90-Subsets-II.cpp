class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans , vector<vector<int>>& v, int idx){
        if(idx==nums.size()) {
            if(v.size()==0 ){
                v.push_back(ans) ;
                return ; 
            }

            bool isDuplicate = false; 
            for(int i = 0 ; i<v.size(); i++){
                if(v[i] == ans) isDuplicate = true;
            }

            if(isDuplicate == false) v.push_back(ans) ;
            return ; 
        }


        helper(nums, ans, v, idx+1); //not append

        ans.push_back(nums[idx]) ; 
        helper(nums, ans, v, idx+1); // append

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> v ; 
         vector<int> ans ; 

         sort(nums.begin() , nums.end()) ; 

         helper(nums, ans, v , 0) ; 
         return v ;
    }
};