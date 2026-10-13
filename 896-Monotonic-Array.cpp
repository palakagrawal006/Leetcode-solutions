class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size() ; 

        vector<int> s = nums ; 
        sort(s.begin(), s.end()) ; 
        if(s==nums) return true; 

        reverse(s.begin(), s.end()) ;
        if(s==nums) return true; 

        return false; 

    }
};