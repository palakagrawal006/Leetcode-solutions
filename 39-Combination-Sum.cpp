class Solution {
public:
    void helper(vector<vector<int>>& v,vector<int> arr, vector<int> ans, int t, int idx ){
        int n = arr.size() ; 
        if(idx== n || t<0) return ;
        if(t==0){
            v.push_back(ans);
            return ;
        }

        for(int i = idx ; i<n; i++){
            // helper(v, arr, ans, t , i) ;

            ans.push_back(arr[i]) ; 
            helper(v, arr, ans, t-arr[i] , i) ; //append
            ans.pop_back() ;
        }

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> ans; 
        vector<vector<int>> v;

         helper(v, arr, ans, target,0  ) ;
         return v ;  
    }
};