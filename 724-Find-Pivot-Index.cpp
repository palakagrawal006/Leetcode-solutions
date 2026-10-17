class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size() ; 

        int rs = 0 ;
        for(int s : nums) rs += s ;

        int ls = 0 ;

        for(int i = 0 ; i<n; i++){
            rs -= nums[i] ; 

            if(rs == ls) return i ; 

            ls += nums[i] ; 
        }
        return -1;
    }
};