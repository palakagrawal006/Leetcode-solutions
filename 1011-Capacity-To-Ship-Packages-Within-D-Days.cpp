class Solution {
public:
    int countDays(vector<int>& arr, int cap){
        int n = arr.size() ; 

        int ans = 0 ;
        int i = 0 ;
        while(i<n){
            int m = cap ; 
            while(i<n && m>=arr[i]){
                m = m- arr[i] ; 
                i++; 
            }
            ans++; 
        }
        return ans; 
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size() ; 

        int lo = arr[0], hi= 0 ;
        for(int x : arr){
            lo = max(lo, x) ;
            hi += x; 
        }
        int ans = -1; 

        while(lo<=hi){
            int cap = lo+(hi-lo)/2; //capacity
            int countd = countDays(arr, cap) ;
            cout<< "sbadxkc" ;
            cout<< countd;

            if(countd <= days) {
                ans = cap;  
                hi = cap-1;
            }
            else {
                lo = cap+1 ;
            }
        }
        return ans ;
    }
};