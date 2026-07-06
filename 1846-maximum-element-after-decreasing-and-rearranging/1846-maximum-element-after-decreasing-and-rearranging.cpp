class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size() ;
        if(n) 

        sort(arr.begin() , arr.end());
        arr[0] = 1; 

        for(int i = 1; i<n ; i++){
            if(abs(arr[i]-arr[i-1]) <=1) continue; 
            else arr[i] = arr[i-1]+1;
            // else return n ;
        }

        int maxi = INT_MIN ; 
        for(int x : arr){
            maxi = max(maxi , x) ; 
        }
        return maxi ;
    }
};