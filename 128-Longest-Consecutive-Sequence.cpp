class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        
        // store in set
        unordered_set <int> s (nums.begin() , nums.end()) ; 

        int longest = 0 ;

        // traverse set
        for(auto x : s){
            // if x is first element of sequence
            if(s.find(x-1) == s.end()) {
                int curr = x ;
                int len = 1 ;

                while(s.find(curr+1) != s.end()) {
                    curr++; 
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest ;
    }
};