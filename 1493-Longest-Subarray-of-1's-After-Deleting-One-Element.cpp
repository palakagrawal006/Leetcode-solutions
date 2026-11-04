class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() ; 

        int count = 0; 
        int maxCount = 0; 
        int k = 1 ;
        int i = 0, j = 0; 

        while(i<n && j<n){
            if(nums[j]==1) j++; 
            else if(nums[j]==0 && k>0) {
                j++;
                k--;
            }
            else { //if(nums[j]==0 && l==0)
                count = j-i;
                maxCount = max(maxCount, count) ;

                while(nums[i]==1) i++;
                if(nums[i]==0) i++;
                j++;  /// last me ek sath bhi sbka j++ krskte h 
            }
        }
        count = j-i;
        maxCount = max(maxCount, count) ;
        return maxCount-1;
    }
};