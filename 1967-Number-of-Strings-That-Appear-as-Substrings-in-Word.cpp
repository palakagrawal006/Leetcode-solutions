class Solution {
public:
    int numOfStrings(vector<string>& nums, string word) {
        int n = nums.size() ; 
        int c = 0 ; 

        for(int i = 0 ; i<n ; i++){
            if(word.contains(nums[i])) c++;
        }
        return c ;
    }
};