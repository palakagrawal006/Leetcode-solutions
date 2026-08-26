class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size() ; 

        int lo = 0 ; 
        int hi = n-1 ; 

        while(hi - lo >=k){
            if(abs(arr[lo]-x) <= abs(arr[hi]-x)) hi--;
            else lo++ ; 
        }
        return vector <int> (arr.begin()+lo , arr.begin()+hi+1); //last not included 
    }
};