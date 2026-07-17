class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size() ; 
        vector <int> gcds; 

        for(int i = 0 ; i<n-1 ; i++){
            for(int j = i+1; j<n; j++){
                gcds.push_back(gcd(nums[i], nums[j])) ; 
            }
        }

        sort(gcds.begin(), gcds.end()) ; 

        int m =  queries.size() ;
        vector<int> ans(m); 
        for(int i=0; i<m ; i++){
            ans[i] = gcds[queries[i]];
        }

        return ans; 
    }
};