bool cmp (vector<int> &a , vector<int> &b){ // end time 
    return a[1]<b[1] ; 
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end() , cmp) ; // sort arr in increasing order of end  -- right to left
        vector<vector<int>> ans ; 
        int n = arr.size() ; 

        ans.push_back(arr[n-1]) ;  // last ; 

        for(int i = n-2; i>=0; i--){
            int x = ans.size();

            if(arr[i][1] >=  ans[x-1][0]) { //curr.end>= last.start == overlap = marge 
                ans[x-1][0] = min(arr[i][0], ans[x-1][0]) ;  
                ans[x-1][1] = max(arr[i][1], ans[x-1][1]) ;  
            }
            else { // no overlapping
                ans.push_back(arr[i]);

            }
        }
        reverse(ans.begin() , ans.end()); 
        return ans ;
    }
};