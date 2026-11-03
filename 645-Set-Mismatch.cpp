class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() ; 

        int i = 0; 
        while(i<n) {
            int correctIdx = nums[i]-1 ; 

            if(correctIdx == i|| nums[i] == nums[correctIdx]) i++; 
            else swap(nums[i] , nums[correctIdx]) ;  
        }

        for(int i = 0 ; i<n ; i++){
            if(nums[i] != i+1) return {nums[i], i+1}; 
        }
      
          return {-1, -1} ;  
    }
};