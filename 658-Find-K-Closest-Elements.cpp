class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int e) {
        int n = arr.size() ; 

        priority_queue <pair<int, int>> pq; //max heap

        for(int x : arr){
            pq.push({abs(x-e), x}) ; 
            if(pq.size()==k+1){
                pq.pop(); 
            }
        }

        vector<int> ans; 
        while(!pq.empty()){
            auto ele = pq.top() ; 
            ans.push_back(ele.second); 
            pq.pop() ; 
        }

        sort(ans.begin() , ans.end()) ; 
        return ans ;

    }
};


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int n = arr.size() ; 

//         int lo = 0 ; 
//         int hi = n-1 ; 

//         while(hi - lo >=k){
//             if(abs(arr[lo]-x) <= abs(arr[hi]-x)) hi--;
//             else lo++ ; 
//         }
//         return vector <int> (arr.begin()+lo , arr.begin()+hi+1); //last not included 
//     }
// };