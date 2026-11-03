class Solution {
public:
    void helper(vector<vector<int>>& v,vector<int> &arr, vector<int> &ans, int t, int idx ){
        int n = arr.size() ; 
       
        if(t==0){
            v.push_back(ans);
            return ;
        }

        for(int i = idx ; i<n; i++){
            if(i>idx && arr[i]==arr[i-1]) continue;

            if(arr[i]>t) break; 

            ans.push_back(arr[i]) ; 
            helper(v, arr, ans, t-arr[i] , i+1) ; //append
            ans.pop_back() ;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> ans; 
        vector<vector<int>> v;

        sort(arr.begin(), arr.end()) ;

         helper(v, arr, ans, target, 0  ) ;
         return v ;  
    }
};