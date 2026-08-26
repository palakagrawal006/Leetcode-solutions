// HEAP
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ; 
 
        // frequency 
        unordered_map <int, int> mp; //ele,freq
        for(int x : nums){
            mp[x]++; 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq; // min heap -- freq,ele

        for(auto ele : mp){
           pq.push({ele.second, ele.first}) ; //freq , val

           if(pq.size()==k+1){
            pq.pop() ; 
           }
        }
        // pq have all top k ele

        vector <int> ans; 
        while(pq.size()>0){
            ans.push_back(pq.top().second) ; //val
            pq.pop() ; 
        }
        return ans; 
    }
};

// SPECIAL SORT CUSTOMISED
// class Solution {
// public:
//     static bool cmp (pair<int , int> &a , pair<int, int> &b){
//         return a.second>b.second; 
//     }
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size() ; 

//         // frequency 
//         unordered_map <int, int> mp; 
//         for(int x : nums){
//             mp[x]++; 
//         }

//         vector <pair<int , int>> v ; 
//         for(auto ele : mp){
//             v.push_back({ele.first, ele.second}) ; 
//         }

//         // sort 
//         sort(v.begin() , v.end() , cmp) ;

//         vector <int> ans; 
//         for(int i = 0 ; i<k ; i++){
//             ans.push_back(v[i].first) ;
//         }
//         return ans; 
//     }
// };