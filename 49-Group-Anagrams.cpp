class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n = str.size();

        unordered_map <string , vector<string>> mp ; 

        for(int i = 0 ; i<n ; i++){
            string temp = str[i] ; 
            sort(temp.begin() , temp.end()) ; 

            mp[temp].push_back(str[i]) ; 
        }


        vector<vector<string>> ans; 
        for(auto x : mp){
            ans.push_back(x.second) ;
        }
        return ans ; 
    }
};