class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set <int> s (nums.begin() , nums.end());
        if(s.find(0)!=s.end()) s.erase(0) ;
        return s.size() ; 
        
    }
};