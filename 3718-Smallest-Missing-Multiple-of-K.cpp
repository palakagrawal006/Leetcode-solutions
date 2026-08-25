class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_set<int> s;  

        for(int x : nums){
            s.insert(x);
        }
        for(int i = 1 ; i<=n ; i++){
            if(s.find(k*i)==s.end()) return k*i; 
        }
        return k*(n+1); 
    }
};