class Solution {
public:
    static bool cmp (pair<int , int> &a , pair<int, int> &b){
        return a.second>b.second; 
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ; 

        // frequency 
        unordered_map <int, int> mp; 
        for(int x : nums){
            mp[x]++; 
        }

        vector <pair<int , int>> v ; 
        for(auto ele : mp){
            v.push_back({ele.first, ele.second}) ; 
        }

        // sort 
        sort(v.begin() , v.end() , cmp) ;

        vector <int> ans; 
        for(int i = 0 ; i<k ; i++){
            ans.push_back(v[i].first) ;
        }
        return ans; 
    }
};