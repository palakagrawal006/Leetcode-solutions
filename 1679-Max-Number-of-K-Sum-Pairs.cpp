class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int op = 0 ; 
        for(auto x : mp){
            int ele= x.first ; 
            int rem = k-ele ; 
            int count = 0;

            if(mp.find(rem) != mp.end()) {
                if( ele == rem){
                    count = floor(mp[ele]/2) ;
                }
                else count = min(mp[ele] , mp[rem]) ; 
                op = op+count; 
                mp[rem]-= count; 
                mp[ele]-=count; 
            }
        }
        return op ; 
    }
};