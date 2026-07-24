// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size() ; 
//         int m = nums2.size() ; 
//         set <int> s ;

//         for(int i = 0  ; i<n; i++){
//            s.insert(nums1[i]) ;
//         }

//         set <int> ans ; 
//         for(int i = 0  ; i<m; i++){
//             if(s.find(nums2[i]) != s.end() ) //exists
//                ans.insert(nums2[i]);
//         }
//         vector <int> v(ans.begin() , ans.end()) ;
//         return v ; 
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>st(nums1.begin(),nums1.end());

        vector <int>ans;
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i]) != st.end()){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }
};